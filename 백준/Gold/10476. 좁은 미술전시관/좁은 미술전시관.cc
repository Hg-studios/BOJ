#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <limits.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(nullptr); cout.tie(nullptr);
    
    int n, k; cin>>n>>k;
    
    int sum = 0;
    vector<vector<int>> v(n+1, vector<int> (3));
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=2; j++) {
            cin>>v[i][j];
            sum+=v[i][j];
            // cout<<v[i][j]<<" ";
        }
        // cout<<'\n';
    }
    
    // dp[i][j][k] 
    // i : 1행부터 i행까지 값 중 최솟값
    // j : 0이면 현재 행에서 아무 칸도 선택안함, 1이면 왼쪽칸 선택, 2이면 오른쪽칸 선택
    // k : 현재까지 몇 칸을 닫았는지 
    
    int dp[n+1][3][k+1];
    // vector<vector<vector<int>>> dp(n+1, vector<int>(3, vector<int> (k+1, 999)));
    // memset(dp, 999, sizeof(dp));
    for(int i=0; i<=n; i++) {
        for(int j=0; j<3; j++) {
            for(int m=0; m<=k; m++) {
                dp[i][j][m] = 99999999; // 길이를 999에서 충분히 늘려줌 
            }
        }
    }
    
    // for(int j=0; j<3; j++) {
    //     for(int m=0; m<=k; m++) {
    //         dp[0][j][m]=0;
    //     }
    // }
    dp[0][0][0]=0; // 초기화를 0,0,0 만
    
    // dp[0][0][0]=0;
    
    for(int i=1; i<=n; i++) {
        for(int j=0; j<3; j++) {
            for(int m=0; m<=k; m++) {
                if(j==0) {
                    int mn = dp[i-1][0][m];
                    if(mn>dp[i-1][1][m]) mn = dp[i-1][1][m];
                    if(mn>dp[i-1][2][m]) mn = dp[i-1][2][m];
                    dp[i][j][m] = mn;
                }
                else if(j==1) {
                    dp[i][j][m] = min(dp[i-1][0][m-1], dp[i-1][1][m-1]) + v[i][j];
                }
                else if(j==2) {
                    dp[i][j][m] = min(dp[i-1][0][m-1], dp[i-1][2][m-1]) + v[i][j];
                }
            }
        }
    }
    
    // for(int i=0; i<3; i++) {
    //     cout<<dp[n][i][k]<<" ";
    // }
    
    // for(int i=0; i<=n; i++) {
    //     for(int j=0; j<3; j++) {
    //         for(int m=0; m<=k; m++) {
    //             cout<<dp[i][j][m]<<" ";
    //             // if(mn>dp[i][j][m])
    //         }
    //         cout<<'\n';
    //     }
    //     cout<<'\n';
    // }
    
    int mn = INT_MAX;
    for(int j=0; j<3; j++) {
        if(dp[n][j][k]<mn) mn = dp[n][j][k];
    }
    // cout<<sum<<" ";
    cout<<sum-mn;
}