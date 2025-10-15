#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

#define X first
#define Y second 

int dx[] = {1,0,-1,0,1,1,-1,-1};
int dy[] = {0,1,0,-1,1,-1,1,-1};

int ddx[] = {-1,-2,-2,-1,1,2,2,1};
int ddy[] = {-2,-1,1,2,-2,-1,1,2};

int board[1002][1002]; // 1-indexed 1:Q, 2:K, 3:P
bool visited[1002][1002]; // 킹이나 퀸이 갈 수 있는 곳이면 true = 안전하지 않은 곳

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    
    int n,m; cin>>n>>m;
    
    // 퀸 입력받기
    int n1; cin>>n1;
    vector<pair<int,int>> q(n1);
    for(int i=0; i<n1; i++) {
        int r,c; cin>>r>>c;
        q[i] = {r,c};
        board[r][c]=1;
        visited[r][c]=true;
    }
    
    // 킹 입력받기
    int n2; cin>>n2;
    vector<pair<int,int>> k(n2);
    for(int i=0; i<n2; i++) {
        int r,c; cin>>r>>c;
        k[i]={r,c};
        board[r][c]=2;
        visited[r][c]=true;
    }
    
    // 폰 입력받기
    int n3; cin>>n3;
    vector<pair<int,int>> p(n3);
    for(int i=0; i<n3; i++) {
        int r,c; cin>>r>>c;
        p[i] = {r,c};
        board[r][c]=3;
        visited[r][c]=true;
    }
    
    // 퀸 이동시키기
    for(auto cur : q) {
        // 상하좌우대각선으로 이동
        queue<pair<pair<int,int>,int>> q; // <<x좌표,y좌표>, 방향>
        
        // 8방향 시작 좌표 넣기
        for(int i=0; i<8; i++) q.push({cur, i});
        
        while(!q.empty()) {
            auto tmp = q.front();
            int curx = tmp.X.X;
            int cury = tmp.X.Y;
            int curd = tmp.Y;
            q.pop();
            
            int nx = curx + dx[curd];
            int ny = cury + dy[curd];
            
            if(nx<1||ny<1||nx>n||ny>m) continue;
            if(board[nx][ny]!=0) continue;
            
            visited[nx][ny]=true;
            q.push({{nx,ny},curd});
        }
    }
    
    // 킹 이동시키기
    for(auto cur : k) {
        for(int dir=0; dir<8; dir++) {
            int nx = cur.X + ddx[dir];
            int ny = cur.Y + ddy[dir];
            
            if(nx<1||ny<1||nx>n||ny>m) continue;
            visited[nx][ny]=true;
        }
    }
    
    int cnt=0;
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++) {
            // cout<<visited[i][j]<<" ";
            if(!visited[i][j])cnt++;
        }
        // cout<<'\n';
    }
    
    cout<<cnt;
    
    return 0;
}