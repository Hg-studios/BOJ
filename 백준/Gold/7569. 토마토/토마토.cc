#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
#define MAX 101

int board[MAX][MAX][MAX]; //1:익은토마토, 0:안익은토마토, -1:빈칸
int dist[MAX][MAX][MAX]; //-1로 초기화됨, 큐에 들어가게 되면 0부터 시작임
int dx[6] = { -1,1,0,0,0,0 };
int dy[6] = { 0,0,-1,1,0,0 };
int dz[6] = { 0,0,0,0,-1,1 };

queue<pair<pair<int, int>, int>> q;
int n, m, h;

void bfs() {
	while (!q.empty()) {
		auto cur = q.front();
		q.pop();

		for (int dir = 0; dir < 6; dir++) {
			int nz = cur.first.first + dx[dir];
			int nx = cur.first.second + dy[dir];
			int ny = cur.second + dz[dir];

			if (nx < 0 || nx >= n || ny < 0 || ny >= m || nz < 0 || nz >= h) continue;
			if (dist[nz][nx][ny] >= 0) continue;

			dist[nz][nx][ny] = dist[cur.first.first][cur.first.second][cur.second] + 1;
			q.push({ {nz,nx},ny });
		}
	}
}

int main() {
	//freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> m >> n >> h;

	//3차원 배열에서 앞에서부터 h,n,m임
	//***주의*** 그냥 내 마음대로 포문을 i,j,k로 돌렸는데 그러면 안됨!! 
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < m; k++) {
				cin >> board[i][j][k];
				
				//dist배열은 안익은 토마토 부분을 -1로 초기화
				if (board[i][j][k] == 0) dist[i][j][k] = -1;

				//토마토 문제는 출발점이 여러 개인 문제에 해당하므로
				//익은 토마토가 여러 개 들어있으니 미리 토마토를 큐에 넣고 시작함
				if (board[i][j][k]==1) q.push({ {i,j},k });
			}
		}
	}

	bfs();

	int res = 0;
	
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < m; k++) {
				if (dist[i][j][k] == -1) {
					cout << -1 << '\n';
					return 0;
				}
				res = max(res, dist[i][j][k]);
			}
		}
	}

	cout << res;

	return 0;
}