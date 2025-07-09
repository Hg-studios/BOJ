/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define X first
#define Y second

int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};
int mx = -1;

int main()
{
    int n,m,k; cin>>n>>m>>k;
    
    vector<vector<int>> v(n+1, vector<int> (m+1,0));
    
    while(k--) {
        int r,c; cin>>r>>c;
        
        v[r][c]=1; // 음식물을 1로 표현
    }
    
    vector<vector<bool>> visited(n+1, vector<bool> (m+1,false));
    
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++) {
            if(visited[i][j]) continue;
            if(v[i][j]==0) continue;
            
            int cnt=0;
            queue<pair<int,int>> q;
            
            cnt++;
            visited[i][j]=true;
            q.push({i,j});
            
            while(!q.empty()) {
                auto cur = q.front();
                q.pop();
                
                for(int dir=0; dir<4; dir++) {
                    int nx = cur.X + dx[dir];
                    int ny = cur.Y + dy[dir];
                    
                    if(nx<1||ny<1||nx>n||ny>m) continue;
                    if(visited[nx][ny]) continue;
                    if(v[nx][ny]==0) continue;
                    
                    cnt++;
                    visited[nx][ny]=true;
                    q.push({nx,ny});
                }
            }
            
            if(mx<cnt) mx = cnt;
        }
    }
    
    cout<<mx;
    
    return 0;
}