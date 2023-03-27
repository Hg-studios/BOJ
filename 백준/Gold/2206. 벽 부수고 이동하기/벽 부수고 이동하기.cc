#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
#define X first
#define Y second
#define MAX 1003

int n,m;
string map[MAX];
int dist[2][MAX][MAX];
// {k,{i,j}}
// : k가 0은 벽을 부수지 않은 상태, 1은 이미 벽을 한 번 부순 상태
// : i,j 위치에서 k가 0또는1 일 수 있음
queue<pair<int,pair<int,int>>> q; 

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int bfs(){
    while(!q.empty()){
        auto cur = q.front();
        q.pop();
        int curK = cur.X;
        int curX = cur.Y.X;
        int curY = cur.Y.Y;

        //먼저 도착하는 경로가 dist를 채우게 되므로
        //0일때와 1일때 중 더 작은 경로를 찾을 필요가 없음
        //bfs 특징 중 하나인, "큐에 쌓이는 순서는 반드시 거리 순" 이므로!!
        if(curX==n-1 && curY==m-1) return dist[curK][curX][curY];

        for(int dir=0; dir<4; dir++){
            int nx = curX + dx[dir];
            int ny = curY + dy[dir];
    
            if(nx<0||nx>=n||ny<0||ny>=m) continue;

            //벽을 만나지 않아서 지금 경로에서 순탄히 가는 경우
            if(map[nx][ny]=='0' && dist[curK][nx][ny]==-1){
                dist[curK][nx][ny] = dist[curK][curX][curY]+1;
                q.push({curK,{nx,ny}});
            }
            //벽을 만났는데 아직 한번도 부순 적 없는 경우
            if(map[nx][ny]=='1' && !curK && dist[curK][nx][ny]==-1){
                dist[1][nx][ny] = dist[0][curX][curY]+1;
                q.push({1,{nx,ny}});
                
            }
            //벽을 만났는데 부순 적이 있으면 더이상 나아가지 못해서 넘어가면 됨
        }
    }

    return -1;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>n>>m;
    for(int i=0; i<n; i++){
        cin>>map[i];
    }

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            dist[0][i][j] = dist[1][i][j] = -1;

    dist[0][0][0] = 1; //거리는 1부터 시작함
    //dist[1][0][0] = 1;
    q.push({0,{0,0}}); //0,0좌표에서 시작함 

    cout<<bfs();

    return 0;
}