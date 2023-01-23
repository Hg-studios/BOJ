#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

constexpr int MAX = 1e3+3;
int n, m;
int dp[MAX][MAX];

int main() {
	//freopen("input.txt", "r", stdin);
	
	string a, b; cin >> a >> b;
	n = a.size(); m = b.size();

	a = "#" + a; b = "#" + b; //0-based to 1-based
	
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (a[i] == b[j]) dp[i][j] = dp[i - 1][j - 1] + 1;
			else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
		}
	}

	cout << dp[n][m];

	return 0;
}