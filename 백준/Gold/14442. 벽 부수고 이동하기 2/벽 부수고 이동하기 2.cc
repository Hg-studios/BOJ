#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
#define X first
#define Y second

int n,m,k;
string area[1003];
int dist[12][1003][1003];
queue<pair<int,pair<int,int>>> q; //{k,i,j} : (i,j)까지 k번 벽을 부수고 이동한 최단 경로

int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

int BFS(){
    while(!q.empty()){
        auto cur = q.front();
        q.pop();

        int curK = cur.X;
        int curX = cur.Y.X;
        int curY = cur.Y.Y;

        if(curX==n-1&&curY==m-1) return dist[curK][curX][curY];

        for(int dir=0; dir<4; dir++){
            int nx = curX+dx[dir];
            int ny = curY+dy[dir];

            if(nx<0||nx>=n||ny<0||ny>=m) continue;
            
            //벽을 만난 경우
            if(area[nx][ny]=='1'){
                //부술 수 있는 횟수보다 적게 부셨으면 벽을 부수고 나아감 
                //그리고 방문한 적이 없어야함
                if(curK<k&&dist[curK+1][nx][ny]==0){
                    dist[curK+1][nx][ny]=dist[curK][curX][curY]+1;
                    q.push({curK+1,{nx,ny}});
                }
            }
            //벽이 아닌 경우
            else{
                if(dist[curK][nx][ny]==0){ //방문한 적이 없어야함
                    dist[curK][nx][ny]=dist[curK][curX][curY]+1;
                    q.push({curK,{nx,ny}});

                }
            }
        }
    }

    return -1;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>n>>m>>k;
    //입력이 띄어쓰기없이 한줄로 나오기 때문에 입력받기 신경쓰기!!
    for(int i=0; i<n; i++){
        cin>>area[i];
    }

    dist[0][0][0]=1;
    q.push({0,{0,0}});
    cout<<BFS();

    return 0;
}