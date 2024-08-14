#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define MAX 302

int n;
int arr[MAX];
int dp[MAX]; //dp[a]=b : a번째 계단까지의 최대값

void solve() {
    dp[1] = arr[1];
    dp[2] = arr[1]+arr[2];
    dp[3] = max(arr[1], arr[2]) + arr[3];
    
    for(int i=4; i<=n; i++) {
        dp[i] = max(dp[i-2], dp[i-3]+arr[i-1]) + arr[i];
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr); cout.tie(nullptr);
    
    // 입력 받기
    cin>>n;
    for(int i=1; i<=n; i++) cin>>arr[i];
    
    solve();
    
    cout<<dp[n];
    
    return 0;
}