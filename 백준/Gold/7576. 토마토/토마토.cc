#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

#define X first
#define Y second
int tomato[1003][1003]; //1이면 익은 토마토, 0이면 안익은 토마토, -1은 토마토없음
int dist[1003][1003]; //익은 토마토와 빈칸은 0에서 시작, 익지 않은 토마토는 -1로 초기화할 예정
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,-1,0,1 };

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	queue<pair<int, int>> q;
	int n, m;
	//***주의*** 여기 n, m이 아니라 m, n 순서임!!
	cin >> m >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> tomato[i][j];
			
			//그냥 if(tomato[i][j]) 라고 하면 -1인 친구도 들어가므로 이러면 안됨
			if (tomato[i][j] == 1) q.push({ i,j });
			//익은 토마토는 이미 익은 토마토로 시작하는 곳이므로 0에서 시작
			//익지 않은 토마토는 -1로 초기화되어서 익지 않은 토마토에 접근하지 않았다면 -1로 남아있음 
			if (!tomato[i][j]) dist[i][j] = -1; 
		}
	}

	while (!q.empty()) {
		auto cur = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = cur.X + dx[i];
			int ny = cur.Y + dy[i];

			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			if (dist[nx][ny] != -1) continue;

			dist[nx][ny] = dist[cur.X][cur.Y] + 1;
			q.push({ nx,ny });
		}
	}

	int res = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (dist[i][j] == -1) {
				cout << -1;
				return 0;
			}
			res = max(res, dist[i][j]);
		}
	}
	cout << res;

	return 0;
}