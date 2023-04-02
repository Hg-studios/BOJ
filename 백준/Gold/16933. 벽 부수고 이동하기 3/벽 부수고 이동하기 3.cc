#include <iostream>
#include <algorithm>
#include <queue>
#include <tuple>
using namespace std;
#define X first
#define Y second

int n,m,k;
string area[1003];
int dist[3][12][1003][1003];
//{d,k,i,j} : (i,j)에 k번 벽을 부수고 도착했는데 d가 1이면 낮, d가 0이면 밤임
queue <tuple<int,int,int,int>> q;

int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

int BFS(){
    while(!q.empty()){
        int curD, curK, curX, curY;
        tie(curD,curK,curX,curY) = q.front();
        q.pop();

        if(curX==n-1 && curY==m-1) return dist[curD][curK][curX][curY];

        for(int dir=0; dir<4; dir++){
            int nx = curX+dx[dir];
            int ny = curY+dy[dir];

            if(nx<0||nx>=n||ny<0||ny>=m) continue;

            //벽을 만난 경우
            //방문한 적이 없어야 함 
            if(area[nx][ny]=='1' && dist[1-curD][curK+1][nx][ny]==0){
                //벽을 부술 수 있으면서 낮인 경우 
                if(curK<k && curD){
                   dist[1-curD][curK+1][nx][ny]=dist[curD][curK][curX][curY]+1;
                   q.push({1-curD,curK+1,nx,ny});
                }
                //벽을 부술 수 있지만 밤이면 기다리면 됨
                else if(curK<k && !curD){
                    dist[1-curD][curK][curX][curY]=dist[curD][curK][curX][curY]+1;
                    q.push({1-curD,curK,curX,curY});
                }
            }
            //벽이 아닌 경우 (그냥 가면 됨)
            //방문한 적이 없어야 함
            else if(area[nx][ny]=='0' && dist[1-curD][curK][nx][ny]==0){
                dist[1-curD][curK][nx][ny]=dist[curD][curK][curX][curY]+1;
                q.push({1-curD,curK,nx,ny});
            }
        }
    }

    return -1;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>n>>m>>k;
    for(int i=0; i<n; i++) cin>>area[i];

    dist[1][0][0][0]=1;
    q.push({1,0,0,0});
    
    cout<<BFS();

    return 0;
}