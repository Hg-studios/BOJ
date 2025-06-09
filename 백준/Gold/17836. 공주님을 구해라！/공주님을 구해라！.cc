#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct dot {
    int r,c,count;
    bool weapon;
};

int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};

int main()
{
    int n, m, t; cin>>n>>m>>t;
    
    vector<vector<int>> v(n+1, vector<int> (m+1, 0));
    
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++) {
            cin>>v[i][j];
        }
    }
    
    // visited[r][c][0] : 무기 없이 방문한 경우
    // visited[r][c][1] : 무기 가지고 방문한 경우
    bool visited[n+1][m+1][2] = { false }; 
    
    queue<dot> q;
    q.push({1,1,0,false});
    visited[1][1][0]=true;
    
    while(!q.empty()) {
        auto cur = q.front();
        q.pop();
        
        if(cur.count>t) continue; // T시간 이내에 구출할 수 없으므로 
        
        // cout<<cur.r<<" "<<cur.c<<'\n';
        if(cur.r==n && cur.c==m) { // 목적지에 도달했다면
            cout<<cur.count;
            return 0;
        }
        
        for(int dir=0; dir<4; dir++) {
            int nr = cur.r + dx[dir];
            int nc = cur.c + dy[dir];
            
            if(nr<1||nc<1||nr>n||nc>m) continue;
            
            
            bool nextWeapon = cur.weapon? true : false;
            
            if(v[nr][nc]==2) nextWeapon = true;
            
            // 단순히 한 번 방문한 적이 있을 때 가지 않는다고 하면, 무기가 생기고 나서 그 칸을 재방문했을 때를 처리하지 못함
            // 따라서 visited를 3차원으로 구성 !! **
            // 무기 보유에 따라 방문 여부를 나눠야 함
            if(visited[nr][nc][nextWeapon]) continue;
            
            // 현재 무기를 보유하지 않았을때 벽을 만났다면 continue
            if(v[nr][nc]==1 && !cur.weapon) continue;
            
            
            
            // // 그람이 놓여있는 공간이라면
            // if(v[nr][nc]==2) {
            //     nextWeapon = true;
            // }
            
            visited[nr][nc][nextWeapon] = true;
            q.push({nr,nc,cur.count+1,nextWeapon});
        }
    }
    
    cout<<"Fail";
    
    return 0;
}