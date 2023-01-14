#include <iostream>
#define MAX 110
using namespace std;

int n, k;
int coin[MAX];
int DP[10101]; //DP[a]=b : a원으로 만들 수 있는 경우의 수 b가지

void solve() {
	DP[0] = 1;
	
	for (int i = 1; i <= n; i++) {
		for (int j = coin[i]; j <= k; j++) {
			DP[j] = DP[j] + DP[j - coin[i]];
		}
	}
	cout << DP[k] << '\n';
}

int main() {
	cin >> n >> k;

	for (int i = 1; i <= n; i++) cin >> coin[i];

	solve();
	

	return 0;
}