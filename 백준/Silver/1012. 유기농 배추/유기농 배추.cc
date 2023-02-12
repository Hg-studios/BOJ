#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

#define X first
#define Y second
#define MAX 51

int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,-1,0,1 };

int main() {
	//freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int tc; cin >> tc;

	while (tc--) {
		int board[MAX][MAX];
		int visited[MAX][MAX];
		int n, m, k; 
		int cnt = 0; //배추를 심을 수 있는 땅덩어리(?) 개수
		
		cin >> m >> n >> k;

		//***주의*** tc가 여러 개 나오는 경우는 int배열을 지역변수로 잡아야됨 
		//그러면 꼭 초기화를 해줘야함!!!!!!!!!!!
		for (int i = 0; i < n; i++) {
			fill(board[i], board[i] + MAX, 0);
			fill(visited[i], visited[i] + MAX, 0);
		}

		while (k--) {
			//***주의*** 입력에서도 m과 n을 반대로 줬었음.. 
			int i, j; cin >> i >> j;
			board[j][i] = 1;
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				//배추가 심어져 있지 않거나 이미 방문한 경우는 시작점이 될 수 없음
				if (!board[i][j] || visited[i][j]) continue;

				//***주의*** 큐 생성을 이중for문 밖에서 했음
				// 그러면 초기화가 안되어있음..
				//시작점을 찾았으므로 큐를 생성해주고, cnt을 하나 올려줌
				queue<pair<int, int>> q;
				cnt++;

				//배추 심을 수 있는 시작점은 방문 체크하고 큐에 넣어줌 
				visited[i][j] = 1;
				q.push({ i,j });

				while (!q.empty()) {
					auto cur = q.front();
					q.pop();

					for (int dir = 0; dir < 4; dir++) {
						int nx = cur.X + dx[dir];
						int ny = cur.Y + dy[dir];

						if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
						if (!board[nx][ny] || visited[nx][ny]) continue;

						visited[nx][ny] = 1; //방문 체크
						q.push({ nx,ny }); //노드를 큐에 넣어줌 
					}
				}
			}
		}
		cout << cnt << '\n';
	}

	return 0;
}