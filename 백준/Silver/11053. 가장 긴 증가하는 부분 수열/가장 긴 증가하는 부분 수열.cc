#include <iostream>
#include <algorithm>
using namespace std;

constexpr int MAX = 1e3+3;
int a[MAX];
int dp[MAX];
int res = 0;

int main() {
	//freopen("input.txt", "r", stdin);
	
	//ex) 10 20 10 30 20 50
	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	for (int i = 0; i < n; i++) {
		dp[i] = 1; //자신이 수열에 들어가므로 길이 1은 디폴트임
		for (int j = 0; j < i; j++) { //자기 수보다 작은 수들만 검사함
			if (a[i] > a[j]) { //자기보다 작은 수가 존재하면 수열에 넣어줘야 함
				//a[j]에는 이미 a[i]보다 작은 값들로 수열이 만들어져 있을 수 있음
				//ex) a[3]=30, a[1]=20
				//ex) dp[3]=1->2(a[3]>a[0]일때, dp[3]값이 1에서 2로 업데이트됐음), dp[1]=2
				//ex) dp[3] = max(dp[3], dp[2]+1);
				dp[i] = max(dp[i], dp[j] + 1); 
			}
		}
		res = max(res, dp[i]); //dp에 저장되는 값 중 가장 큰 수가 정답이 됨
	}

	cout << res << '\n';
	return 0;
}