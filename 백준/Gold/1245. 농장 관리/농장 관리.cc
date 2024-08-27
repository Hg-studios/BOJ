#include <iostream>
#include <queue>
using namespace std;

#define X first
#define Y second

int n,m,ans;
int arr[102][72];
bool visited[102][72]; //탐색한 "봉우리" 확인용
bool isPeak;

int dx[] = {1,0,-1,0, 1,1,-1,-1};
int dy[] = {0,1,0,-1, 1,-1,1,-1};

void bfs(int curX, int curY) {
    queue<pair<int,int>> q;
    
    q.push({curX,curY});
    visited[curX][curY]=true;
    
    while(!q.empty()) {
        auto cur = q.front();
        q.pop();
        
        for(int dir=0; dir<8; dir++) {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            
            if(nx<0||ny<0||nx>=n||ny>=m) continue;
            
            /** 핵심 포인트 : bfs를 돌렸을 때 나보다 높은 게 있으면, 이 높이는 산봉우리가 아니므로 표시해줌 **/
            if(arr[cur.X][cur.Y]<arr[nx][ny]) isPeak = false;
            
            if(visited[nx][ny]) continue; // 이걸 위의 줄보다 먼저 실행하면 안됨! 저번 bfs때 봤던 값이어도 현재 bfs에서도 8방향에 대해 검사는 해야 하므로..!!
            if(arr[cur.X][cur.Y]!=arr[nx][ny]) continue;
            
            q.push({nx,ny});
            visited[nx][ny]=true;
        }
    }      
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr); cout.tie(nullptr);
    
    cin>>n>>m;
    
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cin>>arr[i][j];
        }
    }
    
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(visited[i][j]) continue;
            if(arr[i][j]==0) continue;
            
            isPeak = true;
            bfs(i,j);
            
            if(isPeak) ans++;
        }
    }
    
    cout<<ans;

    return 0;
}