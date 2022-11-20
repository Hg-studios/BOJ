#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string.h>
using namespace std;

constexpr int N = 1003;
int n, m, v;
vector<int> adj[N]; //2차원
bool visited[N];

//dfs벡터로 하는 방법
void dfs(int cur) {
	visited[cur] = 1;
	cout << cur << " ";

	for (int nxt : adj[cur]) {
		if (!visited[nxt]) dfs(nxt);
	}

}
//bfs벡터로 하는 방법
void bfs(int start) {
	queue<int> q;
	q.push(start);
	visited[start] = 1;

	while (!q.empty()) {
		int cur = q.front(); q.pop();
		cout << cur << " ";

		for (int nxt : adj[cur]) {
			if (!visited[nxt]) {
				q.push(nxt);
				visited[nxt] = 1;
				//cout << cur << " ";
			}
		}

	}
}
int main() {
	cin >> n >> m >> v;

	for (int i = 0; i < m; i++) {
		int a, b; cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	// 문제에서 
	// "방문할 수 있는 정점이 여러 개인 경우에는 
	// 정점 번호가 작은 것을 먼저 방문" 이라고 했기에 정렬해줘야함
	for (int i = 1; i <= n; i++) {
		sort(adj[i].begin(), adj[i].end());
	}

	memset(visited, 0, sizeof(visited));
	dfs(v);

	cout << "\n";

	memset(visited, 0, sizeof(visited));
	bfs(v);

	return 0;
}