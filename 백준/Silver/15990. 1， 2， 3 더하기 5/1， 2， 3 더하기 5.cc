#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define MOD 1000000009
#define ll long long

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n; cin>>n;
    
    vector<int> v(n,0);
    for(int i=0; i<n; i++) {
        cin>>v[i];
    }

    int mx = *max_element(v.begin(), v.end());
    // cout<<mx;
    
    vector<vector<int>> dp(100001, vector<int> (4,0));
    
    // 초기화
    dp[1][1]=1;
    dp[2][2]=1;
    dp[3][1]=1; // ** 이거 안넣어서 틀렸었음 ...
    dp[3][2]=1;
    dp[3][3]=1;
    
    for(int i=4; i<=mx; i++) {
        for(int j=1; j<=3; j++) {
            if(j==1) dp[i][j] = (dp[i-j][2]%MOD + dp[i-j][3]%MOD) % MOD;
            else if(j==2) dp[i][j] = (dp[i-j][1]%MOD + dp[i-j][3]%MOD) % MOD;
            else if(j==3) dp[i][j] = (dp[i-j][1]%MOD + dp[i-j][2]%MOD) % MOD;
        }
    }
    
    // for(int i=1; i<=mx; i++) {
    //     cout<<"i : "<<i<<"\n";
    //     for(int j=1; j<=3; j++) {
    //         cout<<dp[i][j]<<" ";
    //     }
    //     cout<<'\n';
    // }
    
    for(int i=0; i<n; i++) {
        ll ans = 0;
        ans = ((ll)dp[v[i]][1]% MOD + dp[v[i]][2]% MOD + dp[v[i]][3]% MOD) % MOD;
        cout<<ans<<'\n';
    }
    
    return 0;
}