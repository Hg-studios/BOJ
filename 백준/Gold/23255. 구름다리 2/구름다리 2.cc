#include <vector>
#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    vector<vector<int>> adj(N + 1);
    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vector<int> color(N + 1, 0);
    vector<int> used(N + 1, 0);  // used[c] == i 이면 i번 건물에서 색 c 사용 금지

    for (int i = 1; i <= N; ++i) {
        // 1) 이웃 중 번호가 i보다 작은 건물들의 색을 금지 표시
        for (int v : adj[i]) {
            if (v < i) {
                int c = color[v];
                if (c != 0) used[c] = i;
            }
        }

        // 2) 가장 작은 사용 가능한 색 찾기
        int c = 1;
        while (c <= N && used[c] == i) ++c;
        color[i] = c;
    }

    // 3) 출력
    for (int i = 1; i <= N; ++i) {
        cout << color[i] << (i == N ? '\n' : ' ');
    }
    return 0;
}
