#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

#define X first
#define Y second

string board[12];
bool visited[13][7];

int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

void tilt() {
	//세로6줄을 빈칸없이 밑으로 밀어줘야함
	for (int j = 0; j < 6; j++) {
		// . 으로 채운 tmp배열에다가 board배열을 세로로 한줄을 읽고 저장함
		// 그리고나서 tmp를 다시 board에 저장할 때 . 가 아닐때 값까지 복사함 
		char tmp[13];
		fill(tmp, tmp + 13, '.');
		
		int idx = 0;

		for (int i = 0; i < 12; i++) {
			if (board[i][j] != '.') {
				tmp[idx++] = board[i][j];
			}
		}

		//tmp에 색이 있는 칸을 옮겼으니 . 으로 초기화
		for (int i = 0; i < 12; i++) board[i][j] = '.';

		int k = 12 - idx;
		//tmp에 옮긴 내용을 가장 밑 행부터 채워줌
		for (int i = 0; i < idx; i++) {
			board[k][j] = tmp[i];
			k++;
		}
	}
}

bool func() {
	bool flag = 0;

	for (int i = 0; i < 12; i++) {
		for (int j = 0; j < 6; j++) {
			//bfs로 넓이가 4이상 되는 영역 구하기
			//그 영역의 좌표를 x로 바꾼 뒤, 세로6줄을 x개수만큼 밑으로 밀어줌
			//밀어줄 때 무작정 x개수만큼만 밀어주면 되는 것이 아님
			//왜냐면 . . x . x (가로로눕힌모양) 이런식일수도 있기 때문

			if (visited[i][j] || board[i][j] == '.') continue;

			queue<pair<int, int>> q; //같은 색의 칸이 4칸 이상인지 확인하기 위한 변수
			queue<pair<int, int>> del; //같은 색이 4칸 이상일 때 해당 칸들을 삭제해줘야함
			int area = 0; //이어진 칸이 총 몇 개인지를 저장하는 변수

			area++;
			visited[i][j] = 1;
			del.push({ i,j });
			q.push({ i,j });

			while (!q.empty()) {
				auto cur = q.front();
				q.pop();

				for (int dir = 0; dir < 4; dir++) {
					int nx = cur.X + dx[dir];
					int ny = cur.Y + dy[dir];

					//범위를 벗어나면 더이상 탐색x
					if (nx < 0 || nx >= 12 || ny < 0 || ny >= 6) continue;
					//이미 방문을 했거나 다른 색의 칸이라면 더이상 탐색x
					if (visited[nx][ny] || board[cur.X][cur.Y] != board[nx][ny]) continue;

					area++;
					visited[nx][ny] = 1;
					del.push({ nx,ny });
					q.push({ nx,ny });
				}
			}
			//4칸이상 그룹이라서 터질 수 있다면 없애줘야함
			if (area >= 4) {
				//이번 함수 호출에서는 삭제할 칸이 있으므로 1을 리턴함
				flag = 1;
				//queue는 탐색기능이 없어서 vector처럼 인덱스를 통해 
				//접근하는 것이 불가능하며 이터레이터도 존재하지 않음 
				while (!del.empty()) {
					auto cur = del.front();
					del.pop();

					board[cur.X][cur.Y] = '.';
				}
			}

		}
	}

	return flag;
}
int main() {
	//freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);

	for (int i = 0; i < 12; i++) {
		cin >> board[i];
	}

	int cnt = 0;
	//더이상 터트릴 칸이 없다면 함수호출을 그만둠
	while (func()) {
		cnt++;
		tilt(); //터트린 칸이 있으니 칸을 전체적으로 밑으로 내려줘야함 

		//새롭게 func함수에 들어가기 전에 visited배열을 초기화시켜줘야함 
		for (int i = 0; i < 12; i++) {
			for (int j = 0; j < 6; j++) {
				visited[i][j] = 0;
			}
		}
	}

	cout << cnt;

	return 0;
}