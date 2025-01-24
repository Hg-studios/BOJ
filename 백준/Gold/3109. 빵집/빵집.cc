#include <iostream>
using namespace std;

// 순서는 무조건 위 대각선 -> 오른쪽 -> 아래 대각선
int dx[] = {-1, 0, 1};
int dy[] = {1, 1, 1};
int r, c;
int cnt;
string arr[10001];
bool visited[10001][501];

bool dfs(int x, int y) {
    // cout<<x<<" "<<y<<'\n';
    if(y==c-1) {
        return true;
    }
    
    for(int dir=0; dir<3; dir++) {
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        
        if(nx<0||ny<0||nx>=r||ny>=c) continue;
        
        if(visited[nx][ny]||arr[nx][ny]=='x') continue;
        // cout<<"*"<<nx<<" "<<ny<<'\n';
        visited[nx][ny]=true;
        if(dfs(nx,ny)) return true;
    }
    
    return false;
}

void solve() {
    for(int i=0; i<r; i++) {
        if(dfs(i,0)) cnt++;
    }
}

int main()
{
    cin>>r>>c;
    
    for(int i=0; i<r; i++) {
        cin>>arr[i];
    }
    
    solve();
    
    cout<<cnt;

    return 0;
}