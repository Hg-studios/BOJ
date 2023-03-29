#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

#define X first
#define Y second
#define MAX 101

string board[MAX];
int visited[MAX][MAX];
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,-1,0,1 };
int n, nor, abnor;
void bfs(int i, int j) {
	queue<pair<int, int>> q;

	visited[i][j] = 1;
	q.push({ i,j });

	while (!q.empty()) {
		auto cur = q.front();
		q.pop();

		for (int dir = 0; dir < 4; dir++) {
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];

			if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
			if (board[cur.X][cur.Y] != board[nx][ny] || visited[nx][ny]) continue;

			visited[nx][ny] = 1;
			q.push({ nx,ny });
		}
	}

}

int area() {
	int cnt = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if ((!visited[i][j])) {
				cnt++;
				bfs(i, j);
			}
		}
	}

	return cnt;
}

int main() {
	//freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> board[i];
	}

	//정상인 사람이 볼 때의 구역의 개수 구하기
	nor = area();

	//방문배열 초기화시키기
	for (int i = 0; i < n; i++) fill(visited[i], visited[i] + n, 0);


	//적록색약인 사람은 빨강과 초록이 똑같으므로 하나로 통일하기
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (board[i][j] == 'R')
				board[i][j] = 'G';
		}
	}
	
	//적록색약인 사람이 볼 때의 구역의 개수 구하기...
	abnor = area();

	cout << nor << " " << abnor << '\n';

	return 0;
}
