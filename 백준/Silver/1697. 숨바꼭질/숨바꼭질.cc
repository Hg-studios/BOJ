#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

#define X first
#define Y second
#define MAX 100002

int dist[MAX];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n, k; cin >> n >> k;
	fill(dist, dist + MAX, -1);
	dist[n] = 0;

	queue<int> q;
	q.push(n);

	while (dist[k] == -1) {
		int cur = q.front();
		q.pop();

		for (int nxt : {cur - 1, cur + 1, cur * 2}) {
			if (nxt < 0 || nxt>100000) continue;
			if (dist[nxt] != -1) continue;
			dist[nxt] = dist[cur] + 1;
			q.push(nxt);
		}
	}
	cout << dist[k];

	return 0;
}