#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main()
{
    int n; cin>>n;
    vector<double> v(n);
    for(int i=0; i<n; i++) cin>>v[i];
    
    vector<double> dp(n);
    dp[0]=v[0]; // dp[a] : a를 포함할 때 연속된 곱의 최대값
    
    double ans=dp[0];
    for(int i=1; i<n; i++) {
        // 나를 포함할 때 나부터 다시 시작하거나 
        // dp[i-1] 은 i-1은 포함하니깐 전의 수부터 시작되어왔거나
        dp[i] = max(v[i], dp[i-1]*v[i]);
        ans = max(ans, dp[i]);
        // cout<<dp[i]<<" ";
    }
    // cout<<'\n';
    printf("%.3lf", ans);
    
    return 0;
}