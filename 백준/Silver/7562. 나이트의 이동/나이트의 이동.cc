#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

#define MAX 303
#define X first
#define Y second

int dist[MAX][MAX];
int dx[8] = { 1,2,2,1,-1,-2,-2,-1 };
int dy[8] = { 2,1,-1,-2,-2,-1,1,2 };

int main() {
	//freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);

	int tc; cin >> tc;

	while (tc--) {
		int n; 
		int x1, y1, x2, y2; 
		cin >> n;
		cin >> x1 >> y1 >> x2 >> y2;

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (i == x1 && j == y1) {
					dist[i][j] = 0; //시작점은 0으로 시작
				}
				else {
					dist[i][j] = -1; //dist배열은 시작점 빼고 -1로 초기화
				}
			}
		}

		//bfs 시작
		queue<pair<int, int>> q;
		q.push({ x1,y1 });
		
		while (!q.empty()) {
			auto cur = q.front();
			q.pop();

			for (int dir = 0; dir < 8; dir++) {
				int nx = cur.X + dx[dir];
				int ny = cur.Y + dy[dir];

				if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
				if (dist[nx][ny] != -1) continue;

				dist[nx][ny] = dist[cur.X][cur.Y] + 1;
				q.push({ nx,ny });
			}
		}
		cout << dist[x2][y2] << '\n';
	}

	return 0;
}