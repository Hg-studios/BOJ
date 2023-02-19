#include <iostream>
using namespace std;

constexpr int MAX = 2200;
int arr[MAX][MAX];
int cnt_1, cnt0, cnt1; //각각 -1, 0, 1의 개수를 저장함

void func(int r, int c, int k) { //시작이 r행 c열이면서 검사해야하는 크기는 k
	int ch; //arr[r][c]의 값을 저장할 변수
	bool flag = 1; //종이가 모두 같은 수로 되어있는지 체크하는 플래그

	//해당 종이가 모두 같은 수로 되어 있는지 체크함
	for (int i = r; i < r + k; i++) {
		for (int j = c; j < c + k; j++) {
			if (i == r && j == c) ch = arr[i][j];
			else {
				if (arr[i][j] != ch) flag = 0;
			}
		}
	}

	//모두 같은 수로 되어있지 않을 때
	if (!flag) {
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				func(r + i * k / 3, c + j * k / 3, k / 3);
			}
		}
	}

	//모두 같은 수로 되어있을 때
	else {
		if (ch == -1) cnt_1++;
		else if (ch == 0) cnt0++;
		else if (ch == 1) cnt1++;

		//원하는 조건에 도달했으므로 함수를 빠져나옴 
		return;
	}

}

int main() {
	//freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n; cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}

	func(0, 0, n);
	
	cout << cnt_1 << '\n';
	cout << cnt0 << '\n';
	cout << cnt1 << '\n';

	return 0;
}