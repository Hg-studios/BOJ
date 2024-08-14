#include <iostream>
#include <queue>
using namespace std;

#define MAX 255

int r,c;
bool visited[MAX][MAX];
string arr[MAX];
int ansS, ansW;

int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};

void solve() {
    for(int i=0; i<r; i++) {
        for(int j=0; j<c; j++) {
            if(visited[i][j]) continue;
            if(arr[i][j]=='#') continue; // 울타리가 아닌 곳에서 탐색을 시작함 
            
            queue<pair<int,int>> q;
            int cntS=0, cntW=0;
            
            if(arr[i][j]=='o') cntS++;
            else if(arr[i][j]=='v') cntW++;
            visited[i][j]=true;
            q.push({i,j});
            
            while(!q.empty()) {
                auto cur = q.front();
                q.pop();
                
                for(int dir=0; dir<4; dir++) {
                    int nr = cur.first + dx[dir];
                    int nc = cur.second + dy[dir];
                    
                    if(nr<0||nc<0||nr>=r||nc>=c) continue; // 범위를 벗어나면 끝
                    if(visited[nr][nc]) continue; // 이미 탐색했다면 탐색하지 않음 
                    if(arr[nr][nc]=='#') continue; //울타리 안에만 탐색함
                    
                    if(arr[nr][nc]=='o') cntS++;
                    else if(arr[nr][nc]=='v') cntW++;
                    visited[nr][nc]=true;
                    q.push({nr,nc});
                }
            }
            if(cntW<cntS) ansS+=cntS;
            else ansW+=cntW;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr); cout.tie(nullptr);
    
    cin>>r>>c;
    for(int i=0; i<r; i++) {
        cin>>arr[i];
    }
    
    solve();
    
    cout<<ansS<<" "<<ansW;
    
    return 0;
}