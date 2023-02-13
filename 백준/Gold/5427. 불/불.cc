#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

#define MAX 1003
#define X first
#define Y second

//Q1 : string board[MAX]는 fill함수로 초기화를 할 수 없는건가..?
string board[MAX]; 
int distF[MAX][MAX]; //불의 거리 배열
int distS[MAX][MAX]; //상근이의 거리 배열 
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,-1,1 };

int main() {
	//freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);

	int tc; cin >> tc;

	while (tc--) {
		queue<pair<int, int>> qF, qS;
		int n, m; cin >> m >> n;

		//Q2 : char c; cin>>c; 하게 되면 하나씩 받을 수 있는거임? 공백이 없어도???
		for (int i = 0; i < n; i++) cin >> board[i];

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				//dist배열은 -1로 초기화해줌 
				distF[i][j] = -1;
				distS[i][j] = -1;

				if (board[i][j] == '*') {
					distF[i][j] = 0;
					qF.push({ i,j });
				}
				else if (board[i][j] == '@') {
					distS[i][j] = 0;
					qS.push({ i,j });
				}
			}
		}
		
		//불 BFS
		while (!qF.empty()) {
			auto cur = qF.front();
			qF.pop();

			for (int dir = 0; dir < 4; dir++) {
				int nx = cur.X + dx[dir];
				int ny = cur.Y + dy[dir];

				if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
				if (board[nx][ny] == '#' || distF[nx][ny] != -1) continue;

				distF[nx][ny] = distF[cur.X][cur.Y] + 1;
				qF.push({ nx,ny });
			}
		}
		
		bool escape = 0;
		//상근 BFS
		while ((!qS.empty()) && (!escape)) {
			auto cur = qS.front();
			qS.pop();

			for (int dir = 0; dir < 4; dir++) {
				int nx = cur.X + dx[dir];
				int ny = cur.Y + dy[dir];

				if (nx < 0 || nx >= n || ny < 0 || ny >= m) { //여기에 도달했다면 탈출
					cout << distS[cur.X][cur.Y] + 1<<'\n';
					escape = 1;
					break;
				}
				if (board[nx][ny] == '#' || distS[nx][ny] != -1) continue;
				//불보다 빨리 도착해야지만 그곳을 지날 수 있음
				//***주의*** distF가 distS보다 작다면 continue이다
				//왜냐하면 더 작다는 것이 더 빨리 도착했다는 것이므로!!
				//이걸 헷갈려서 부등호를 반대로 썼음 
				//distF[nx][ny]가 초기화되어있는 값이 아니면서 
				if (distF[nx][ny]!=-1 && distF[nx][ny] <= distS[cur.X][cur.Y] + 1) continue; 

				distS[nx][ny] = distS[cur.X][cur.Y] + 1;
				qS.push({ nx,ny });
			}
		}

		if(!escape) cout << "IMPOSSIBLE" << '\n';
	}

	return 0;
}