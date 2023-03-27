#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
#define X first
#define Y second 

int n;
int ans;
int area[102][102];
bool visited[102][102];

int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

void BFS(int h){
    //visited배열 초기화
    for(int i=0;i<n;i++){
        fill(visited[i], visited[i]+n, 0);
    }

    queue<pair<int,int>> q;
    int safe_area=0;

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(visited[i][j]||area[i][j]<=h) continue;

            safe_area++;
            visited[i][j]=1;
            q.push({i,j});

            while(!q.empty()){
                auto cur=q.front();
                q.pop();

                for(int dir=0; dir<4; dir++){
                    int nx = cur.X + dx[dir];
                    int ny = cur.Y + dy[dir];

                    if(nx<0||nx>=n||ny<0||ny>=n) continue;
                    if(visited[nx][ny]||area[nx][ny]<=h) continue;

                    visited[nx][ny]=1;
                    q.push({nx,ny});
                }
            }
        }
    }   
    ans = max(ans, safe_area);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    //1~100값을 모두 볼 필요가 없음
    //최대높이를 구해서 그 범위에서만 검사하면 됨
    int maxH=0; 

    cin>>n;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>area[i][j];
            maxH=max(maxH, area[i][j]);
        }
    }
    
    for(int i=0; i<=maxH; i++){
        BFS(i);
    }

    cout<<ans;

    return 0;
}