#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
#define X first
#define Y second

int n,m;
bool on[102][102]; //불이 켜지면 1, 꺼져있으면 0 (불을 켜기 위한 배열)
bool visited[102][102]; //방문했으면 1, 안했으면 0 (BFS만을 위한 배열)
vector<pair<int,int>> adj[102][102]; //해당 좌표에서 불을 켤 수 있는 좌표
queue<pair<int,int>> q;

int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

bool OOB(int x, int y){
    return x<1||x>n||y<1||y>n;
}

bool is_conn(pair<int,int> nxt){ //(1,1)에서 nxt에 도달가능한가?
    //nxt점을 기준으로 상하좌우 중 한군데라도 방문한 적이 있으면 도달가능한 곳임
    for(int dir=0; dir<4; dir++){
        int nx = nxt.X + dx[dir];
        int ny = nxt.Y + dy[dir];

        if(OOB(nx,ny)) continue;
        if(visited[nx][ny]) return 1;
    }
    return 0;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>n>>m;
    while(m--){
        int x,y,a,b;
        cin>>x>>y>>a>>b;

        adj[x][y].push_back({a,b});
    }

    //연결리스트처럼 하나의 좌표에서 연결된 좌표만 불을 켤 수 있음
    //켤 수 있는 곳의 불을 모두 킨다. -> 불이 켜지는 곳의 on값을 1로 변경함
    on[1][1]=1;
    visited[1][1]=1;
    q.push({1,1});
    while(!q.empty()){
        auto cur = q.front();
        q.pop();

        //각 좌표의 adj에 해당하는 vector에서 값을 하나씩 꺼내서 불을 킴
        //큐에 넣어주는 좌표는 이동가능한 좌표만 넣어줌
        for(auto nxt : adj[cur.X][cur.Y]){
            if(visited[nxt.X][nxt.Y]) continue; //이미 방문한 경우엔 스킵
            if(is_conn(nxt)){ //(1,1)에서부터 도달할 수 있는 좌표라면 큐에 넣어줌
                visited[nxt.X][nxt.Y]=1;
                q.push({nxt.X, nxt.Y});
            }
            on[nxt.X][nxt.Y]=1;
        }

        //큐에 들어있는 값을 가지고 상하좌우로 이동함
        //위에서 불이 켜졌지만 그곳으로 이동할 수 있는가는 또다른 문제임
        for(int dir=0; dir<4; dir++){
            int nx = cur.X+dx[dir];
            int ny = cur.Y+dy[dir];

            if(OOB(nx,ny)) continue;
            //불이켜지지않은곳이거나 이미방문했던 곳이면 가지 못함 
            if(!on[nx][ny] || visited[nx][ny]) continue; 

            visited[nx][ny]=1;
            q.push({nx,ny});
        }
    }

    int ans = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++) ans += on[i][j];
    cout << ans;

    return 0;
}