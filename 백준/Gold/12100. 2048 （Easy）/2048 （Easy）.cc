#include <iostream>
#include <algorithm>
using namespace std;

int board1[21][21];
int board2[21][21];
int n, mx = -1;

void rotate() { //board2를 시계 방향으로 90도 회전하는 함수
	int tmp[21][21];

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			tmp[i][j] = board2[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			board2[i][j] = tmp[n - 1 - j][i];
		}
	}
}

//board1를 한줄씩 왼쪽으로 밀었을 때의 결과를 구해서 총 n번을 진행함 
//왼쪽이 아닌 경우, 아래쪽은 시계방향으로 1번 돌려주고 오른쪽은 2번, 위쪽은 3번 돌려줌
void tilt(int dir) { 
	while (dir--) rotate();

	for (int i = 0; i < n; i++) {
		int tilted[21] = {}; //board2[i]를 왼쪽으로 기울인 결과를 저장할 변수, 0으로 초기화되어있음
		int idx = 0; //tilted배열에서 어디에 삽입해야 하는지 가리키는 변수

		for (int j = 0; j < n; j++) {
			if (board2[i][j] == 0) continue; //값이 없으면 옮겨주지 않아도 됨
			
			//board2값이 있으면서 현재idx 자리가 비어있다면 값을 그곳에 바로 대입
			if (tilted[idx] == 0) tilted[idx] = board2[i][j];
			//board2값이 있으면서 현재idx 자리가 비어있지 않다면 
			//tilted가 가리키는 값과 내가 현재 저장해야하는 값을 비교해줌
			//같다면 값을 2배해야되고 아니라면 그냥 다음 인덱스에 값을 저장해줌
			else if (board2[i][j] == tilted[idx]) { //같은 값이 와서 2배해줘야하는경우
				tilted[idx] *= 2;
				idx++;
			}
			else { //다른값이 온 것이므로 다음idx에 값을 저장해야하는경우
				idx++;
				tilted[idx] = board2[i][j];
			}
		}

		//완성된 tilted배열 값을 board2에 넣어줌
		for (int j = 0; j < n; j++) board2[i][j] = tilted[j];
	}
}

int main() {
	//freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> board1[i][j];
		}
	}

	for (int i = 0; i < (1 << (2 * 5)); i++) {
		//각 경우할 때마다 배열을 초기화해줌 
		for (int a = 0; a < n; a++) {
			for (int b = 0; b < n; b++) {
				board2[a][b] = board1[a][b];
			}
		}

		//가장 바깥 포문에서 i가 쓰이고 있기 때문에 
		//i를 그대로 계산에 사용하면 안됨
		int tmp = i;

		for (int j = 0; j < 5; j++) {
			int dir = tmp % 4;
			tmp /= 4;
			tilt(dir);
		}

		//배열에서 가장 큰 수 찾기
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				mx = max(mx, board2[i][j]);
			}
		}
	}

	cout << mx;

	return 0;
}