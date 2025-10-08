#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    
    int tc; cin>>tc;
    
    while(tc--) {
        int n; cin>>n;
        
        vector<vector<int>> v(2, vector<int>(n));
        for(int i=0; i<2; i++) {
            for(int j=0; j<n; j++) {
                cin>>v[i][j];
                // cout<<v[i][j]<<" ";
            }
            // cout<<'\n';
        }
        
        vector<vector<int>> dp(2, vector<int>(n,0));
        
        // dp[a][b] = c : 행 a (0 or 1) b번째(열) 스티커가 현재 갖을 때 최댓값 c
        // dp[a][b] = dp[a][b] + max(dp[1-a][b-1], dp[1-a][b-2])
        
        dp[0][0] = v[0][0];
        dp[1][0] = v[1][0];
        if(n<=1) {
            cout<<max(dp[0][0], dp[1][0])<<'\n';
            continue;
        }
        
        dp[0][1] = v[0][1] + dp[1][0];
        dp[1][1] = v[1][1] + dp[0][0];
        if(n<=2) {
            cout<<max(dp[0][1], dp[1][1])<<'\n';
            continue;
        }
        
        for(int i=2; i<n; i++) {
            for(int j=0; j<2; j++) {
                dp[j][i] = v[j][i] + max(dp[1-j][i-1], dp[1-j][i-2]);
            }
        }
        
        cout<<max(dp[0][n-1], dp[1][n-1])<<'\n';
        
        // for(int i=0; i<2; i++) {
        //     for(int j=0; j<n; j++) {
        //         cout<<dp[i][j]<<" ";
        //     }
        //     cout<<'\n';
        // }
    }
    
    return 0;
}