#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
#define X first
#define Y second

string board[5];
int permu[30]; //조합을 구할 때 사용될 배열 25개 중 7개는 0으로 채워짐
int ans=0; //답 카운트

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    for(int i=0; i<5; i++){
        cin>>board[i];
    }

    for(int i=0; i<30; i++) permu[i]=1;
    for(int i=0; i<7; i++) permu[i]=0;

    //25개 중 조합을 이용하여 7개를 뽑고 뽑은 정수를 좌표로 변환한다.
    //좌표를 저장하면서 해당 좌표가 S인지를 센다.
    //그 수에 해당하는 좌표들 중 "S"가 4개 이상이면 bfs를 돌린다.
    //그 후 모두 연결되어 있으면 답으로 센다.
    do
    {
        queue<pair<int,int>> q;
        bool visited[5][5]={0,}; //bfs를 돌려야 하므로 vis배열 필요
        bool isP7[5][5]={0,}; //조합을 통해 7명으로 뽑힌 사람의 좌표 표시
        int cntS=0; //"S"의 개수를 세는 변수 
        for(int i=0; i<25; i++){
            int x,y;
            if(permu[i]==0){
                x = i/5;
                y = i%5;
                isP7[x][y]=1;
                if(board[x][y]=='S') cntS++;

                if(q.empty()){ //시작점 하나를 큐에 넣어줌 
                    q.push({x,y});
                    visited[x][y]=1;
                }
            }
        }
        if(cntS<4) continue; //다솜파가 4명보다 적으면 탐색할 필요x

        int adj=0; //isP7로 연결돼있으면서 인접한 사람의 수를 저장 
        while(!q.empty()){
            auto cur = q.front();
            q.pop();
            adj++;

            for(int dir=0; dir<4; dir++){
                int nx = cur.X+dx[dir];
                int ny = cur.Y+dy[dir];

                if(nx<0||nx>5||ny<0||ny>=5) continue;
                if(visited[nx][ny]||!isP7[nx][ny]) continue;
                
                visited[nx][ny]=1;
                q.push({nx,ny});
            }
        }

        if(adj==7) ans++;
    } while (next_permutation(permu, permu+25));

    cout<<ans;
}