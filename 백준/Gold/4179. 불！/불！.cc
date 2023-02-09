#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;


#define X first
#define Y second
#define MAX 1003
string board[MAX];
int dist1[MAX][MAX];
int dist2[MAX][MAX];
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,-1,0,1 };

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n, m; cin >> n >> m;

	for (int i = 0; i < n; i++) {
		fill(dist1[i], dist1[i] + m, -1);
		fill(dist2[i], dist2[i] + m, -1);
	}

	for (int i = 0; i < n; i++) {
		cin >> board[i];
	}

	//불과 지훈이 걸리는 시간 -1로 초기화하면서
	//지훈이랑 불 찾아서 바로 큐에 넣어주기 
	queue<pair<int, int>> q1; //불
	queue<pair<int, int>> q2; //지훈이 

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (board[i][j] == 'F') {
				q1.push({ i,j });
				dist1[i][j] = 0;	
			}
			if (board[i][j] == 'J') {
				q2.push({ i,j });
				dist2[i][j] = 0;
			}
		}
	}

	//불 BFS 부터 시작해줌
	while (!q1.empty()) {
		auto cur = q1.front();
		q1.pop();

		for (int dir = 0; dir < 4; dir++) {
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];

			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			if (dist1[nx][ny] != -1 || board[nx][ny] == '#') continue;

			dist1[nx][ny] = dist1[cur.X][cur.Y] + 1;
			q1.push({ nx,ny });
		}
	}

	//지훈이 BFS 시작함 
	while (!q2.empty()) {
		auto cur = q2.front();
		q2.pop();

		for (int dir = 0; dir < 4; dir++) {
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];

			//***주의*** 키포인트는 여기임. 범위를 벗어났다는 것은 
			//탈출에 성공했다는 것을 의미함. 
			// 큐에 거리 순으로 들어가므로 최초에 탈출한 시간을 출력하면 됨
			if (nx < 0 || nx >= n || ny < 0 || ny >= m) {
				cout << dist2[cur.X][cur.Y] + 1;
				return 0;
			}

			if (dist2[nx][ny] != -1 || board[nx][ny] == '#') continue;
			
			//불의 전파시간을 조건에 추가함
			//지훈이는 자신이 도착한 시간과 동시에 불이 도착하거나
			//혹은 자신보다 더 빨리 불이 도착하는 자리로는 갈 수 없음 
			if (dist1[nx][ny] != -1 && dist1[nx][ny] <= dist2[cur.X][cur.Y] + 1) continue;

			dist2[nx][ny] = dist2[cur.X][cur.Y] + 1;
			q2.push({ nx,ny });
		}
	}
	
	//여기에 도달했다는 것은 탈출에 실패했음을 의미함
	cout << "IMPOSSIBLE";

	return 0;
	
}