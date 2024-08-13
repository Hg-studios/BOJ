#include <iostream>
using namespace std;

#define MAX 16
int n;
int t[MAX]; // 상담 걸리는 기간
int p[MAX]; // 받을 수 있는 금액 
int dp[MAX];

void solve() {
    int max_pay = 0;
    for(int i=0; i<=n; i++) {
        dp[i] = max(dp[i], max_pay);
        
        if(t[i]+i<=n) {
            dp[t[i]+i] = max(dp[t[i]+i], p[i]+dp[i]);
        }
        
        max_pay = max(max_pay, dp[i]);
    }
    
    cout<<max_pay;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr); cout.tie(nullptr);
    
    cin>>n;
    for(int i=0; i<n; i++) cin>>t[i]>>p[i];
    
    solve();
    
    return 0;
}