#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;
    vector<vector<int>> adj(N + 1);
    for (int i = 0; i < M; i++) {
        int A, B;
        cin >> A >> B;
        adj[A].push_back(B);
        adj[B].push_back(A);
    }
    int X;
    cin >> X;

    // X의 직속 친구 표시
    vector<bool> isNeighbor(N + 1, false);
    for (int v : adj[X]) {
        isNeighbor[v] = true;
    }

    vector<bool> visited(N + 1, false);
    int ans = 1;  // 최소 1명

    // X를 제거한 뒤의 각 컴포넌트 탐색
    for (int v = 1; v <= N; v++) {
        if (v == X || visited[v]) continue;
        int compSize = 0;
        int nbCnt = 0;
        queue<int> q;

        visited[v] = true;
        q.push(v);

        while (!q.empty()) {
            int u = q.front();
            q.pop();
            compSize++;
            if (isNeighbor[u]) nbCnt++;
            for (int w : adj[u]) {
                if (w == X || visited[w]) continue;
                visited[w] = true;
                q.push(w);
            }
        }

        int groupSize = compSize;
        if (nbCnt == 1) {
            // 배신자와 친구인 유일한 한 명이 있으므로 함께 모일 수 있음
            groupSize = compSize + 1;
        }
        // nbCnt >= 2 이면 배신자가 축출되어 compSize 그대로
        ans = max(ans, groupSize);
    }

    cout << ans << '\n';
    return 0;
}
