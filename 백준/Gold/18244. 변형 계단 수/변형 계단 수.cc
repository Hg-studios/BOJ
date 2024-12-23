#include <iostream>
#include <cstring>
using namespace std;

#define MOD 1000000007
int n;
int dp[101][10][6]; // dp[a][b][c]=e : 총 길이 a이면서 현재 숫자 b이고 연속으로 증가 혹은 감소인 c 상태
                    // c=0:증가 혹은 감소 0, c=1:한번 증가, c=2:두번 증가, c=3:한번 감소, c=4:두번 감소 



int main()
{
    cin>>n;
    
    // 초기화
    for(int i=0; i<=9; i++) {
        dp[1][i][0] = 1;
    }
    
    for(int i=2; i<=n; i++) {
        for(int j=0; j<=9; j++) {
            if(j!=0) {
                // 1번 증가인 상태가 되려면 0에서 오거나 -2 혹은 -1에서 올 수 있음
                dp[i][j][1] = (dp[i][j][1] + dp[i-1][j-1][0]) % MOD;
                dp[i][j][1] = (dp[i][j][1] + dp[i-1][j-1][3]) % MOD;
                dp[i][j][1] = (dp[i][j][1] + dp[i-1][j-1][4]) % MOD;
                // 2번 증가인 상태가 되려면 1번 증가했던 상태에서 와야 함 
                dp[i][j][2] = (dp[i][j][2] + dp[i-1][j-1][1]) % MOD;
            }
            if(j!=9) {
                // 1번 감소인 상태가 되려면 0에서 오거나 +1 혹은 +2에서 올 수 있음
                dp[i][j][3] = (dp[i][j][3] + dp[i-1][j+1][0]) % MOD;
                dp[i][j][3] = (dp[i][j][3] + dp[i-1][j+1][1]) % MOD;
                dp[i][j][3] = (dp[i][j][3] + dp[i-1][j+1][2]) % MOD;
                // 2번 증가인 상태가 되려면 2번 증가했던 상태에서 와야 함
                dp[i][j][4] = (dp[i][j][4] + dp[i-1][j+1][3]) % MOD;
            }
        }
    }
    
    long long ans = 0L;
    for(int j=0; j<=9; j++) {
        for(int k=0; k<5; k++) {
            ans = (ans+dp[n][j][k])%MOD;   
        }
    }
    
    cout<<ans;
    
    
    return 0;
}