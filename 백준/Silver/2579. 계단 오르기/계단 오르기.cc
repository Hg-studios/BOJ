#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define MAX 302

int n;
int arr[MAX];
int dp[MAX][3];

void solve() {
    // 초기화
    dp[1][1]=arr[1];
    dp[1][2]=0;
    dp[2][1]=arr[2];
    dp[2][2]=arr[1]+arr[2];
    
    // 완탐 시작
    for(int i=3; i<=n; i++) {
        dp[i][1] = max(dp[i-2][1], dp[i-2][2]) + arr[i];
        dp[i][2] = dp[i-1][1] + arr[i];
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
    
    cout<<max(dp[n][1], dp[n][2]);
    
    return 0;
}