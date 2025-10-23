 #include <bits/stdc++.h>
using namespace std;

static int dp[3001][2][3001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, B;
    if (!(cin >> N >> B)) return 0;
    vector<int> A(N + 1);
    for (int i = 1; i <= N; ++i) cin >> A[i];

    const int NEG = -1000000000; // -1e9: 도달 불가 상태

    // 초기화
    for (int i = 0; i <= N; ++i)
        for (int b = 0; b < 2; ++b)
            for (int k = 0; k <= B; ++k)
                dp[i][b][k] = NEG;

    dp[0][0][0] = 0; // 아직 아무 구간도 보지 않았고, 안자는 중, 0개 선택

    // 점화식: i-1 -> i
    for (int i = 1; i <= N; ++i) {
        for (int k = 0; k <= B; ++k) {
            // i를 고르지 않음
            // b=0에서 유지, b=1에서 끊고 b=0으로
            dp[i][0][k] = max(dp[i][0][k], dp[i-1][0][k]);
            dp[i][0][k] = max(dp[i][0][k], dp[i-1][1][k]);

            // i를 고름 (선택 수 +1)
            if (k >= 1) {
                // 새 블록 시작: 이전 b=0, 첫 칸 보상 0
                dp[i][1][k] = max(dp[i][1][k], dp[i-1][0][k-1]);
                // 블록 연장: 이전 b=1, 보상 A[i]
                if (dp[i-1][1][k-1] != NEG) {
                    dp[i][1][k] = max(dp[i][1][k], dp[i-1][1][k-1] + A[i]);
                }
            }
        }
    }

    cout << max(dp[N][0][B], dp[N][1][B]) << '\n';
    return 0;
}
