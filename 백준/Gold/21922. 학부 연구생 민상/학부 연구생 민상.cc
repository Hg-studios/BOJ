#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define R first
#define C second

int dx[] = {-1,1,0,0}; // 상 하 좌 우 
int dy[] = {0,0,-1,1};

// int board[2001][2001];
// bool visited[2001][2001][4];

int v[2001][2001];
bool visited[2001][2001];

struct Pose {
    int x,y,dir;
};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(nullptr); cout.tie(nullptr);
    
    int n, m; cin>>n>>m;
    
    // vector<vector<int>> v(n, vector<int> (m,0));
    vector<pair<int,int>> pan;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++) {
            cin>>v[i][j];
            
            if(v[i][j]==9) pan.push_back({i,j});
        }
    }
    
    // int cnt=0; // 총 몇 칸에 방문했는지 저장
    // vector<vector<bool>> visited(n, vector<bool> (m,0));
    // 각 선풍기 4방향으로 돌리기
    for(auto p : pan) {
        int x = p.first;
        int y = p.second;
        
        queue<Pose> q;
        visited[x][y] = true;
        
        for(int dir=0; dir<4; dir++) {
            // 시작칸 + 그 때의 방향 
            q.push({x, y, dir});
            // cout<<"[방향 : "<<dir<<"]"<<'\n';
            
            while(!q.empty()) {
                auto cur = q.front();
                int curx = cur.x;
                int cury = cur.y;
                int curdir = cur.dir;
                
                q.pop();
                
                // cout<<"cur : "<<cur.x<<" "<<cur.y<<" "<<cur.dir<<'\n';
                
                int nx = curx + dx[curdir];
                int ny = cury + dy[curdir];
                int ndir = cur.dir;
                
                // cout<<"next : "<<nx<<" "<<ny<<" "<<ndir<<'\n';
                if(nx<0 || ny<0 || nx>=n || ny>=m) continue;
                
                // **중요**
                // 다시 제자리로 왔다면 무한 뻉뺑이 돌게 되는 것이므로 멈추기
                //if(nx==x && ny==y) break;
                
                if(v[nx][ny]==9) break;
                
                // **중요**
                // q에 넣기 직전에 해주면 칸이 1, 2일 때 표시가 안되므로 표시해주기
                // 그 칸에 도착하기 전에 갈 수 있는지 없는지를 미리 구해보기 때문에 1, 2일 때는 미리 막히므로 꼭 미리 해주기
                visited[nx][ny] = true;
                
                // 칸이 1이면서 바람의 방향이 좌우라면 더이상 갈 수 없음
                if(v[nx][ny]==1 && (cur.dir==2 || cur.dir==3)) {
                    // cout<<"1\n";
                    continue;
                }
                // 칸이 2이면서 바람의 방향이 상하라면 더이상 갈 수 없음 
                if(v[nx][ny]==2 && (cur.dir==0 || cur.dir==1)) {
                    // cout<<"2\n";
                    continue;
                }
                // 칸이 3이라면 방향이 바뀜
                if(v[nx][ny]==3) {
                    // cout<<"3\n";
                    if(ndir==0) ndir = 3;
                    else if(ndir==1) ndir = 2;
                    else if(ndir==2) ndir = 1;
                    else if(ndir==3) ndir = 0;
                }
                
                // 칸이 4라면 방향이 바뀜
                if(v[nx][ny]==4) {
                    // cout<<"4\n";
                    if(ndir==0) ndir = 2;
                    else if(ndir==1) ndir = 3;
                    else if(ndir==2) ndir = 0;
                    else if(ndir==3) ndir = 1;
                }
                
                // cout<<"push : "<<nx<<" "<<ny<<" "<<ndir<<'\n';
                // visited[nx][ny] = true;
                q.push({nx,ny,ndir});
            }
            
            // 한 방향 끝나고 찍어보기 
            // for(int i=0; i<n; i++){
            //     for(int j=0; j<m; j++) {
            //         cout<<visited[i][j]<<" ";
            //     }
            //     cout<<'\n';
            // }
            
            //     cout<<'\n';
            
            // 최적화 - 이미 다 찼으면 더이상 돌지 않도록
            /*
            cnt=0;
            for(int i=0; i<n; i++){
                for(int j=0; j<m; j++) {
                    if(visited[i][j]) cnt++;
                }
            }
            if(cnt>=n*m) break;
            */
        }
    }
    
    int cnt=0;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++) {
            if(visited[i][j]) cnt++;
        }
    }
    
    cout<<cnt;
    
    
    return 0;
}