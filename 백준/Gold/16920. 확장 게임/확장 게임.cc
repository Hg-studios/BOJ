#include <iostream>
#include <algorithm>
#include <queue>
#include <tuple>
using namespace std;
#define X first
#define Y second

int n,m,p;
int canExtend[1003][1003];
int cnt[10]; //각 플레이어가 한 라운드에 움직일 수 있는 횟수
int ans[10]; //각 플레이어가 차지하는 땅의 개수 (=답)
queue<tuple<int,int,int>> q[10]; //각 플레이어의 큐임, <x,y,step>으로 좌표와 움직인횟수 저장

int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>n>>m>>p;
    for(int i=1; i<=p; i++) {
        cin>>cnt[i];
    }
    
    char ch;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>ch;

            if(ch=='.') canExtend[i][j]=1;
            else if(ch=='#') canExtend[i][j]=0;
            else{ //플레이어들의 성인 경우
                canExtend[i][j]=0;
                ans[ch-'0']++;
                q[ch-'0'].push({i,j,0});
            }
        }
    }
    //게임 시작
    while(1){
        bool isExtend = 0;
        for(int i=1; i<=p; i++){
            queue<tuple<int,int,int>> nextq; //다음턴에 확장가능한 영토 기록
            while(!q[i].empty()){
                int curx,cury,curstep;
                tie(curx,cury,curstep)=q[i].front();
                q[i].pop();

                //확장가능한 횟수가 넘었으면 다음 차례때 확장해야함
                //그래서 이번 턴에서 다음 턴으로 넘겨주면 됨
                //q[i]에 push하게 되면 이번 턴에 확인하면 안되는 영토를 
                //큐에 넣고 이번 턴에 확인하게 됨  
                if(curstep>=cnt[i]){ 
                    nextq.push({curx,cury,0}); 
                    continue;
                }

                for(int dir=0; dir<4; dir++){
                    int nx = curx+dx[dir];
                    int ny = cury+dy[dir];

                    if(nx<0||nx>=n||ny<0||ny>=m) continue;
                    if(!canExtend[nx][ny]) continue;

                    canExtend[nx][ny]=0;
                    ans[i]++;
                    q[i].push({nx,ny,curstep+1});
                    isExtend=1;
                }
            }
            q[i]=nextq; //다음 번를 미리 세팅해놓음 
        }
        //더이상 아무도 영토를 확장하지 못하면 게임을 종료시킴 
        if(!isExtend) break;
    }
    //각 플레이어의 영토 출력 
    for(int i=1; i<=p; i++){
        cout<<ans[i]<<" ";
    }

    return 0;
}