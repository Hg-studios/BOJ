#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define X first
#define Y second

int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(nullptr); cout.tie(nullptr);
    
    int n,m; cin>>n>>m;
    
    vector<vector<int>> v(n+1, vector<int> (m+1));
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++) {
            cin>>v[i][j];
        }
    }
    
    int h,w; cin>>h>>w;
    int sr, sc, fr, fc; cin>>sr>>sc>>fr>>fc;
    
    // 누적합을 위한 배열 sum
    // (1,1) 부터 (x,y) 까지의 누적합
    vector<vector<int>> sum(n+1, vector<int> (m+1,0));
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++) {
            sum[i][j] = v[i][j] + sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1];
        }
    }
    
    vector<vector<int>> dist(n+1, vector<int> (m+1,-1)); // 방문여부 저장배열이자 거리배열
    queue<pair<int,int>> q;
    
    dist[sr][sc]=0;
    q.push({sr,sc});
    
    while(!q.empty()) {
        auto cur = q.front();
        q.pop();
        
        if(cur.X==fr && cur.Y==fc) {
            cout<<dist[cur.X][cur.Y];
            return 0;
        }
        
        for(int dir=0; dir<4; dir++) {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            
            if(nx<=0 || nx+h-1>n || ny<=0 || ny+w-1>m) continue; // 범위 체크
            if(dist[nx][ny]!=-1) continue; // 이미 살펴본 좌표라면 탐색 끝
            
            // (nx,ny)를 시작점으로 h*w 칸만큼 이동할 수 있는지 확인
            // 누적합으로 O(1)에 확인해야 시간초과나지 않음 
            // (nx, ny) ~ (endr, endc) 까지의 누적합을 구해야함 
            int endr = nx+h-1;
            int endc = ny+w-1;
            
            int s = sum[endr][endc]-sum[nx-1][endc]-sum[endr][ny-1]+sum[nx-1][ny-1];
            
            if(s!=0) continue;
            
            // cout<<"queue push : "<<nx<<" "<<ny<<'\n';
            dist[nx][ny] = dist[cur.X][cur.Y]+1;
            q.push({nx,ny});
        }
    }
    
    cout<<-1;
    
    return 0;
}