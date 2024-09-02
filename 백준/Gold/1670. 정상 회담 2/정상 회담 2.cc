#include <iostream>
using namespace std;

using ll = long long;
#define MOD 987654321LL

ll dp[5002];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr); cout.tie(nullptr);
    
    int n;
    cin>>n;
    
    n/=2;
    
    dp[0]=1;
    dp[1]=1;
    
    for(int i=2; i<=n; i++) {
        for(int j=0; j<i; j++) {
            dp[i] += ((dp[j]%MOD) * (dp[i-j-1]%MOD)) % MOD;
            dp[i] %= MOD;
        }
    }
    
    cout<<dp[n];
    
    return 0;
}