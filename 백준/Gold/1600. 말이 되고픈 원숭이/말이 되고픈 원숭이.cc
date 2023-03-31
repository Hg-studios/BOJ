#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
#define X first
#define Y second

int k, h, w;
int area[202][202];
int dist[32][202][202]; //[k][x][y]:말움직임을 k번사용하여 x,y에 도착하는 최솟값
queue<pair<int,pair<int,int>>> q;

int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
int cx[8]={1,2,2,1,-1,-2,-2,-1};
int cy[8]={-2,-1,1,2,2,1,-1,-2};

bool OOB(int x, int y){
    return x<0||x>=h||y<0||y>=w;
}

int BFS(){
    while(!q.empty()){
        auto cur = q.front(); q.pop();
        int curK = cur.X;
        int curX = cur.Y.X;
        int curY = cur.Y.Y;

        if(curX==h-1 && curY==w-1) return dist[curK][curX][curY]; //도착함
        //말의 움직임으로 가는 경우
        if(curK<k){ //k번 모두 했으면 더이상 할 수 없음
            for(int dir=0; dir<8; dir++){
                int nx = curX+cx[dir];
                int ny = curY+cy[dir];

                if(OOB(nx,ny)) continue;
                if(dist[curK+1][nx][ny] || area[nx][ny]) continue;
                
                dist[curK+1][nx][ny] = dist[curK][curX][curY]+1;
                q.push({curK+1,{nx,ny}});
            }
        }
        //원숭이의 움직임으로 가는 경우
        for(int dir=0; dir<4; dir++){
            int nx = curX+dx[dir];
            int ny = curY+dy[dir];

            if(OOB(nx,ny)) continue;
            if(dist[curK][nx][ny] || area[nx][ny]) continue;

            dist[curK][nx][ny] = dist[curK][curX][curY]+1;
            q.push({curK,{nx,ny}});
        }
        
    }

    return -1;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>k>>w>>h; //h가 행이고 w가 열

    for(int i=0; i<h; i++){
        for(int j=0; j<w; j++){
            cin>>area[i][j];
        }
    }

    //(0,0) 좌표 큐에 넣고 시작
    dist[0][0][0]=1; //-1로 초기화하는 대신 0으로 초기화된 상태를 이용하고 마지막에 -1을 해줌
    q.push({0,{0,0}});

    int ans = BFS();
    if(ans!=-1) cout<<ans-1;
    else cout<<-1;

    return 0;
}