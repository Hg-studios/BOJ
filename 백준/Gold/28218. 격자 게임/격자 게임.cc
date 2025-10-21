#include <vector>
#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M, K;
    if (!(cin >> N >> M >> K)) return 0;

    vector<string> g(N);
    for (int i = 0; i < N; ++i) cin >> g[i];

    // win[i][j] == true  → (i,j)에서 현재 차례가 이김
    vector<vector<char>> win(N, vector<char>(M, 0));

    // 바텀업: 목표칸에서 거꾸로 (아래/오른쪽/대각선으로만 갈 수 있으므로 역순이 안전)
    for (int i = N - 1; i >= 0; --i) {
        for (int j = M - 1; j >= 0; --j) {
            if (g[i][j] == '#') {  // 장애물 칸은 시작 불가/도달 불가 → 그대로 둠
                win[i][j] = 0;
                continue;
            }
            bool w = false;
            
            // 3경우 중 한 가지라도 만족하면 현재 칸은 true임
            // 즉, 현재 갈 수 있는 칸 중 하나라도 false인 칸이 있다면 현재 칸은 true가 됨
            
            // 1) 오른쪽 1칸을 봤을 때 false 이면 됨
            if (j + 1 < M && g[i][j + 1] != '#' && !win[i][j + 1]) w = true;

            // 2) 아래 1칸을 봤을 때 false 이면 됨
            if (i + 1 < N && g[i + 1][j] != '#' && !win[i + 1][j]) w = true;

            // 3) 대각선 1~K칸을 봤을 때 하나라도 false 이면 됨
            for (int t = 1; t <= K; ++t) {
                int ni = i + t, nj = j + t;
                
                if (ni >= N || nj >= M) break; // 범위 벗어나면 끝냄 
                if (g[ni][nj] != '#' && !win[ni][nj]) { // 위에서랑 똑같이 벽이 아니면서 false인 칸이 있는지 찾기
                    w = true;
                    break;
                }
            }

            win[i][j] = w;
        }
    }

    int Q; 
    cin >> Q;
    while (Q--) {
        int x, y;
        cin >> x >> y; // x=행, y=열 (1-indexed)
        int i = x - 1, j = y - 1;
        // 시작 칸이 장애물이면 이동 불가 → 선공 패배로 처리됨(win=false)
        cout << ( (i>=0 && i<N && j>=0 && j<M && win[i][j]) ? "First\n" : "Second\n");
    }
    return 0;
}
