#include <iostream>
using namespace std;

long long dp[16][16]; //1-15까지 인덱스 사용할 것임

int main() {
	//freopen("input.txt", "r", stdin);
	
	int N, M, K; cin >> N >> M >> K;
	int dN, dM;

	dp[1][1] = 1;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			dp[i][j] += dp[i - 1][j] + dp[i][j - 1];
		}
	}
	
	if (K!=0) {
		if (K % M != 0) {
			dM = K % M;
			dN = (K - dM) / M + 1;
		}
		else {
			dN = K / M;
			dM = M;
		}
	}

	if (!K) cout << dp[N][M];
	else cout << dp[dN][dM] * dp[N - dN + 1][M - dM + 1];

	return 0;
}