#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

#define X first
#define Y second

int board[501][501];
int visited[501][501];
int num; //그림의 개수
int mx; //그림의 최대 크기
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,-1,0,1 };

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n,m; cin >> n >> m;
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
		}
	}
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			//방문했거나 색칠이 안된 부분은 큐에 넣지 않음  
			if (visited[i][j] || board[i][j]==0) continue;

			queue<pair<int, int>> q;

			//큐에 시작점을 넣어줌, 그 전에 방문 체크함
			visited[i][j] = 1;
			q.push({ i,j });
			//시작점이 되는 곳의 개수가 그림의 개수임 
			num++;

			int tmp = 0; //땅의 크기를 저정할 변수 = pop개수
			while (!q.empty()) {
				tmp++;
				pair<int, int> cur = q.front(); 
				q.pop();

				for (int k = 0; k < 4; k++) {
					int nx = cur.X + dx[k];
					int ny = cur.Y + dy[k];

					//nx와 ny 인덱스가 0~n-1, 0~m-1 범위를 넘어서면 안됨 
					if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
					//또한, 방문했거나 색칠이 안된 부분은 큐에 넣지 않음 
					if (visited[nx][ny] || !board[nx][ny]) continue;
					//***큐에 넣기 전에 꼭 visited 체크 해줄 것***
					visited[nx][ny] = 1;
					q.push({ nx,ny });
				}
			}
			mx = max(mx, tmp);
		}
	}
	cout << num << '\n' << mx;

	return 0;
}