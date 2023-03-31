#include <iostream>
#include <algorithm>
#include <queue>
#include <cstdlib>
using namespace std;
#define X first
#define Y second

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int n; 
int idx;
int area[102][102];
int visited[102][102];
queue<pair<int,int>> q;
vector<pair<int,int>> land[10002]; //i번째 섬에 포함된 땅의 좌표들의 vector

bool OOB(int x, int y){
    return x<0||x>=n||y<0||y>=n;
}

void BFS(){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(visited[i][j] || area[i][j]==0) continue;

            idx++;
            land[idx].push_back({i,j});
            area[i][j]=idx; //몇번째 땅인지 표시
            visited[i][j]=1;
            q.push({i,j});

            while(!q.empty()){
                auto cur = q.front();
                q.pop();

                for(int dir=0; dir<4; dir++){
                    int nx = cur.X + dx[dir];
                    int ny = cur.Y + dy[dir];
                    if(nx<0||nx>=n||ny<0||ny>=n) continue;
                    if(visited[nx][ny]||area[nx][ny]==0) continue;

                    land[idx].push_back({nx,ny});
                    area[i][j]=idx;
                    visited[nx][ny]=1;
                    q.push({nx,ny});
                }
            }
        }
    }
}

int min_bridge(int idx){
    //idx번째 섬에서 최단 거리의 다리 구하기
    //BFS 특성상 "큐에 쌓이는 순서는 반드시 거리 순" 이므로
    
    queue<pair<pair<int,int>,int>> q;

    //vector에 저장해놨던 애들을 꺼내어 한번에 큐에 넣어줌
    //queue는 x,y좌표 그리고 거리를 저장함
    //이로써 하나의 섬의 모든 좌표는 "동시에" 거리를 계산하게 됨
    for(auto i : land[idx]){
        visited[i.X][i.Y]=idx;
        q.push({{i.X, i.Y},0});
    }

    while(!q.empty()){
        auto cur = q.front(); q.pop();
        int t = cur.Y;

        for(int dir=0; dir<4; dir++){
            int nx = cur.X.X+dx[dir];
            int ny = cur.X.Y+dy[dir];

            if(OOB(nx,ny)) continue; //범위를 벗어남
            if(visited[nx][ny]==idx) continue; //이미 방문했던 좌표임
            if(area[nx][ny]==idx) continue; //같은 섬일 경우
            if(area[nx][ny]!=0) return t; //바다가 아니란 것은 다른 섬이라는 의미
            //남은 경우는 area[nx][ny]==0인 경우밖에 없음
            visited[nx][ny]=idx;
            q.push({{nx,ny},t+1});
        }
    }
    //다른 섬을 못만난 경우 큰 값을 반환함
    return 99999;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>n;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>area[i][j];
        }
    }

    //땅을 BFS로 찾고, 하나의 땅을 찾았을 때마다
    //그 좌표를 각 vector에 저장함
    //vector는 땅의 개수만큼 저장될 것이고 땅을 다 찾은 후
    //1번 땅 좌표에서 2번땅 좌표까지 중에서 4방향으로 뻗어갈 때
    //최단거리를 구함
    //시간복잡도를 구해봐야할듯

    BFS(); //*여기서 땅마다 번호를 매겨줘야함.. 

/*
원래는 모든 좌표를 vector<pair<int,int>> v[102]; 이렇게 두고
v[idx].push_back({nx,ny}); 했었다.
그리고 포문을 돌면서 v[i]와 v[j]에서 하나씩 꺼내서 
|x1-x2|+|y1-y2|-1 값을 구해서 가장 작은 값을 찾으려고 했었다.
근데 이렇게 할 필요가 없었다. 그리고 어떻게 구현해야될지도 감이 안왔다.
내가 왜 이생각을 못했는지 모르겠다. 어떻게 하면 되냐면 땅마다 번호를 표시한다. 그리고 한칸씩 전진하면서
같은 땅인지 확인하고 아니라면 값을 증가시키며 전진한다. 
BFS의 특성상 큐에 쌓이는 순서는 반드시 거리 순이게 된다!!!
그래서 그냥 다른 번호의 땅에 닿을 때까지 BFS하면 되는 것이었다. ㄷㄷ..

*/

    //초기화안해도됨
    for(int i=0; i<n; i++) {
        fill(visited[i], visited[i]+n, -1);
    }

    int ans = 0x7fffffff;
    for(int i=1; i<=idx; i++){
        ans = min(ans, min_bridge(i));
    }
    
    cout<<ans;

    return 0;
}
