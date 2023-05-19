#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

#define X first
#define Y second

char board[22][22];
int h, w;
pair<int, int> dir; //전차 방향
int x, y; //전차 좌표

bool OOB(int x, int y) {
	return x < 0 || x >= h || y < 0 || y >= w;
}

void solve(char s) {
	if (s == 'U') {
		//방향바꾸기
		dir = { -1,0 }; 
		//범위를 벗어나지 않으면서 평지이면 한칸이동
		if (!OOB(x - 1, y) && board[x - 1][y] == '.') {
			board[x][y] = '.'; //원래 전차좌표는 평지로
			x -= 1; //전차좌표 업데이트
		}
		board[x][y] = '^'; //좌표에서 전차방향 바꾸기
	}
	else if (s == 'D') {
		dir = { 1,0 };
		if (!OOB(x + 1, y) && board[x + 1][y] == '.') {
			board[x][y] = '.';
			x += 1;
		}
		board[x][y] = 'v';
	}
	else if (s == 'L') {
		dir = { 0,-1 };
		if (!OOB(x, y - 1) && board[x][y - 1] == '.') {
			board[x][y] = '.';
			y -= 1;
		}
		board[x][y] = '<';
	}
	else if (s == 'R') {
		dir = { 0,1 };
		if (!OOB(x, y + 1) && board[x][y + 1] == '.') {
			board[x][y] = '.';
			y += 1;
		}
		board[x][y] = '>';
	}
	else if (s == 'S') {
		int bx = x; int by = y; //폭탄좌표
		while (1) {
			bx += dir.X;
			by += dir.Y;

			if (OOB(bx, by)) break;
			if (board[bx][by] == '*') {
				board[bx][by] = '.';
				break;
			}
			if (board[bx][by] == '#') {
				break;
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	//freopen("input.txt", "r", stdin);

	int t; cin >> t;
	for (int tc = 1; tc <= t; tc++) {
		//입력받기
		cin >> h >> w;
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				cin >> board[i][j];
			}
		}
		int n; cin >> n;
		string str;  cin >> str;

		//전차방향 초기화
		dir = { 0,0 };
		//전차방향,좌표 구하기
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				if (board[i][j] == '<') {
					dir = { 0,-1 };
					x = i; y = j;
				}
				else if (board[i][j] == '>') {
					dir = { 0,1 };
					x = i; y = j;
				}
				else if (board[i][j] == '^') {
					dir = { -1,0 };
					x = i; y = j;
				}
				else if (board[i][j] == 'v') {
					dir = { 1,0 };
					x = i; y = j;
				}
			}
		}

		//입력 처리
		for (int i = 0; i < n; i++) {
			solve(str[i]);
		}

		//출력
		cout << "#" << tc << " ";
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				cout << board[i][j];
			}
			cout << '\n';
		}
	}
}