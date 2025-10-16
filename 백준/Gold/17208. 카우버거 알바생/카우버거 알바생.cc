#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

struct menu {
    int h;
    int f;
};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    
    int N,M,K; cin>>N>>M>>K;
    
    vector<menu> v(N);
    vector<vector<vector<int>>> dp(N+1, vector<vector<int>>(M+1, vector<int>(K+1, -1))); // dp[i][j][k]=l : 버거j 감튀 k를 소모하는 i번째 주문까지 봤을 때 처리 가능한 최대 주문 수 l개
    
    for(int i=0; i<N; i++) {
        int x,y; cin>>x>>y;
        v[i]={x,y};
    }
    
    dp[0][0][0]=0;
    
    for(int i=0; i<v.size(); i++) {
        auto cur = v[i];
        for(int j=0; j<=M; j++) {
            for(int k=0; k<=K; k++) {
                if(dp[i][j][k]==-1) continue;
                
                // i번째 주문 안받기
                dp[i+1][j][k] = max(dp[i+1][j][k], dp[i][j][k]);
                
                // i번째 주문 받기
                if (j + cur.h <= M && k + cur.f <= K) {
                    dp[i+1][j+cur.h][k+cur.f] = max(dp[i+1][j+cur.h][k+cur.f], dp[i][j][k] + 1);
                }   
            }
        }
    }
    
    int ans=0;
    
    for(int j=0; j<=M; j++) {
        for(int k=0; k<=K; k++) {
            ans = max(ans, dp[N][j][k]);
        }
    }
    
    cout<<ans<<'\n';
    
    return 0;
}