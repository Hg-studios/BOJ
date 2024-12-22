#include <iostream>
#include <cstring>
using namespace std;
#define MAX 102
char arr[MAX][MAX];
int n,m,k,ans;
string s;
int dp[MAX][MAX][80];

int dx[] = {0,1,-1,0};
int dy[] = {1,0,0,-1};

int solve(int i, int j, int depth) {
    if(dp[i][j][depth]!=-1) return dp[i][j][depth];
    if(depth>=s.length()) return 1;
    
    // dp값이 -1일 때만 이곳에 도달함
    // 이제 새롭게 (i, j) 좌표 depth만큼으로 이곳에 왔다면 얼만큼 단어를 완성할 수 있을지 구해줘야 함
    dp[i][j][depth]=0; 
    for(int dir=0; dir<4; dir++) {
        for(int step=1; step<=k; step++) {
            int nx = i+dx[dir]*step;
            int ny = j+dy[dir]*step;
            
            if(nx<0||ny<0||nx>=n||ny>=m) continue;
            if(s[depth]!=arr[nx][ny]) continue;
            
            dp[i][j][depth] = dp[i][j][depth] + solve(nx,ny,depth+1);
        }
    }
    return dp[i][j][depth];
}


int main()
{
    cin>>n>>m>>k;
    
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cin>>arr[i][j];
        }
    }
    cin>>s;
    
    memset(dp, -1, sizeof(dp));
    
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(arr[i][j]==s[0]) {
                ans = ans + solve(i,j,1);
            }
        }
    }
    
    cout<<ans;
    return 0;
}