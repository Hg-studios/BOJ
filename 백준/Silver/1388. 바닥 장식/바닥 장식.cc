#include <iostream>
#include <queue>
using namespace std;
#define MAX 51
#define X first
#define Y second 

string arr[MAX];
bool visited[MAX][MAX];

int main()
{
    int n,m; cin>>n>>m;
    
    for(int i=0; i<n; i++) {
        cin>>arr[i];
    }
    
    
    int cnt=0;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(visited[i][j]) continue;
            
            cnt++;
            
            queue<pair<int,int>> q;
            visited[i][j]=true;
            q.push({i,j});
            
            // 탐색 시작
            while(!q.empty()) {
                auto cur = q.front();
                q.pop();
                
                int nx, ny;
                if(arr[i][j]=='|') {
                    nx = cur.X+1;
                    ny = cur.Y;
                }
                else {
                    nx = cur.X;
                    ny = cur.Y+1;
                }
                
                if(nx>=n||nx<0||ny>=m||ny<0) continue;
                
                if((arr[i][j]=='|' && arr[nx][ny]=='|') 
                || (arr[i][j]=='-' && arr[nx][ny]=='-')) {
                    visited[nx][ny]=true;
                    q.push({nx,ny});
                }
                
            }
        }
    }
    
    cout<<cnt;
    
    return 0;
}