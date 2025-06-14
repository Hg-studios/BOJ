#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// 답이 다섯 개 중 가장 왼쪽에 있는 바둑알을 찾아야하므로
// 오른쪽, 아래, 오른쪽아래대각선, 왼쪽아래대각선만 검사하면 됨
int dx[] = {1, 0, 1, -1, 1, -1, 0, -1};
int dy[] = {0, 1, 1, 1, -1, -1, -1, 0};

bool OOB(int x, int y) {
    return x<0 || y<0 || x>=19 || y>=19;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(nullptr); cout.tie(nullptr);
    
    vector<vector<int>> v(19, vector<int>(19, 0));
    
    for(int i=0; i<19; i++) {
        for(int j=0; j<19; j++) {
            cin>>v[i][j];
        }
    }
    
    for(int i=0; i<19; i++) {
        for(int j=0; j<19; j++) {
            if(v[i][j]==0) continue;
            // cout<<"["<<i<<", "<<j<<'\n';
            // 흰돌이든 검은돌이든 시작점인지 확인해야 함
            // 8방향을 봤을 때 같은 색이 그 칸에 있으면 bfs를 돌려서 5개 놓여져 있는지 봐야함 
            // 근데? 그 검사를 하기 전에 그 방향의 반대 방향 먼저 봐야됨 -> 위에 하나 더 있으면 그건 시작점이 아니므로
            for(int dir=0; dir<4; dir++) {
                int nx = i + dx[dir];
                int ny = j + dy[dir];
                // cout<<"["<<i<<", "<<j<<"] dir : "<<dir<<'\n';
                if(OOB(nx,ny)) continue;
                if(v[i][j] != v[nx][ny]) continue;
                // cout<<"["<<i<<", "<<j<<"] dir : "<<dir<<'\n';
                // 현재 칸과 같은 색이라면 몇 개가 연속으로 있는지 확인하기 전에 방향 먼저 보기
                int tmpx = i + dx[7-dir];
                int tmpy = j + dy[7-dir];
                // cout<<"["<<i<<", "<<j<<"] dir : "<<dir<<'\n';
                // 반대 방향에 있는 색이 범위를 벗어났으면 무슨 색인지 안봐도 됨 
                // 색이 같다면 시작점이 아니므로 (=육목이므로) 검사를 그만함 
                if(!OOB(tmpx, tmpy) && v[i][j]==v[tmpx][tmpy]) continue;
                
                
                // 이제 총 몇 개가 연속되어 있는지 확인하기
                queue<pair<int,int>> q;
                q.push({i,j});
                int cnt=0;
                
                while(!q.empty()) {
                    cnt++;
                    auto cur = q.front();
                    q.pop();
                    
                    int nx = cur.first + dx[dir];
                    int ny = cur.second + dy[dir];
                    
                    if(OOB(nx,ny)) break;
                    if(v[cur.first][cur.second] != v[nx][ny]) break;
                    
                    q.push({nx,ny});
                }
                
                // cout<<"["<<i<<", "<<j<<"] dir : "<<dir<<" cnt: "<<cnt<<'\n';
                
                if(cnt==5) {
                    cout<<v[i][j]<<'\n';
                    cout<<i+1<<" "<<j+1;
                    
                    return 0;
                }
            }
        }
    }
    
    cout<<0;
    
    return 0;
}