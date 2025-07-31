#include <iostream>
#include <vector>
#include <cmath>
#include <limits.h>
using namespace std;

int main()
{
    int n; cin>>n;
    
    vector<int> dp(n+1, -1); // dp[a]=b : a를 표현할 수 있는 제곱수 합의 최소 개수 b
    
    dp[0]=0;
    dp[1]=1;
    
    for(int i=2; i<=n; i++) {
        int mn = INT_MAX;
        
        // i보다 작은 제곱수들을 모두 봄
        // 그 제곱수의 dp값에다가 +1 하면 현재 dp 값이 나오므로
        for(int j=1; j*j<=i; j++) {
            mn = min(mn, dp[i-j*j]+1);
        }
        
        dp[i] = mn;
    }
    
    // dp[a] 는 결국 a/2까지만 보면 됨 . . . 
    
    cout<<dp[n];
    
    return 0;
}