#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

#define X first
#define Y second

string board[102];
int dist[102][102];
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,-1,0,1 };

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		cin >> board[i];
	}

	//거리는 -1로 초기화시킴 
	for (int i = 0; i < n; i++) {
		fill(dist[i], dist[i] + m, -1);
	}
	
	queue<pair<int, int>> q;
	dist[0][0] = 0;
	q.push({ 0,0 });

	while (!q.empty()) {
		pair<int, int> cur = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = cur.X + dx[i];
			int ny = cur.Y + dy[i];

			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			//***주의*** !board[nx][ny] 라고 하면 안됨 왜냐면 얘네는 string 이니깐
			if (board[nx][ny] != '1' || dist[nx][ny] != -1) continue;

			dist[nx][ny] = dist[cur.X][cur.Y] + 1;
			q.push({ nx,ny });
		}
	}

	//문제 특성상 거리+1이 정답임
	cout << dist[n - 1][m - 1] + 1;

	return 0;
}