#include <iostream>
using namespace std;

int arr[101];
long long dp[101][21]; //dp[i][j]=x 는 i번째 등식까지 합이 j인 경우의 수가 x임을 의미
int n;

int main() {
	//freopen("input.txt", "r", stdin);
	
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	dp[0][arr[0]] = 1;

	for (int i = 1; i < n - 1; i++) {
		for (int j = 0; j < 21; j++) {
			if (dp[i - 1][j]) {
				if (j + arr[i] <= 20) dp[i][j + arr[i]] += dp[i - 1][j];
				if (j - arr[i] >= 0) dp[i][j - arr[i]] += dp[i - 1][j];
			}
		}
	}

	cout<< dp[n - 2][arr[n - 1]];

	return 0;
}
