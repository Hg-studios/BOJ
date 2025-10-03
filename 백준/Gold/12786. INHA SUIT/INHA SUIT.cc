#include <iostream>
#include <vector>
#include <cstring>
#include <limits.h>
using namespace std;

int main()
{
    int n; cin>>n;
    int k; cin>>k;
    
    vector<vector<int>> v(n+1);
    
    for(int i=1; i<=n; i++) {
        int m; cin>>m;
        for(int j=0; j<m; j++) {
            int h; cin>>h;
            v[i].push_back(h);
        }
    }
    
    int dp[102][21];
    
    // memset(dp, 99999999, sizeof(dp));
    
    for(int i=0; i<102; i++) {
        for(int j=0; j<21; j++) {
            dp[i][j] = 99999999;
        }
    }
    
    // 처음 위치
    dp[0][1]=0; // dp[a][b]=c : a번째 나무의 b 높이의 구멍까지 최소 T 기능 횟수
    v[0].push_back(1);
    
    for(int i=1; i<=n; i++) {
        // 해당 i번째 나무에 있는 구멍만 검사함
        for(auto j : v[i]) { // i번째 나무에서 갈 수 있는 곳을 모든 방문?
            // i번째 j번째 구멍마다 j-1번째에 있는 모든 구멍을 살펴봄
            
            for(auto k : v[i-1]) {
                // i-1번째 구멍에서 올 수 있는 경우
                // 즉, O A B C 기능 사용 
                if(k==j || k+1==j || (k*2>=20? 20 : k*2)==j || k-1==j) dp[i][j] = min(dp[i][j], dp[i-1][k]);
                // T기능 사용
                else dp[i][j] = min(dp[i][j], dp[i-1][k]+1);
            }
        }
        // for(int j=1; j<=20; j++) cout<<dp[i][j]<<" ";
        // cout<<'\n';
    }
    
    int ans = INT_MAX;
    for(int i=1; i<=20; i++) {
        if(dp[n][i]<=k) ans = min(ans, dp[n][i]);
    }
    
    if(ans==INT_MAX || ans==99999999) ans = -1;
    
    cout<<ans;
    // ans = min(ans, cout<<dp[n][i]<<" ";
    
    return 0;
}