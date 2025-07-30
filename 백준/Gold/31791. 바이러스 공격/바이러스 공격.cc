#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct node {
    int timer, x, y;
    
    bool operator>(const node& other) const {
        return timer > other.timer;
    }
};

int dx[] = {0,1,0,-1};
int dy[] = {1,0,-1,0};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(nullptr); cout.tie(nullptr);
    
    int n, m; cin>>n>>m;
    int tg, tb, x, b; cin>>tg>>tb>>x>>b;
    
    vector<vector<char>> v(n, vector<char> (m));
    priority_queue<node, vector<node>, greater<node>> pq;
    
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cin>>v[i][j];
            if(v[i][j]=='*') pq.push({0,i,j});
        }
    }
    
    while(!pq.empty()) {
        auto cur = pq.top();
        pq.pop();
        
        for(int dir=0; dir<4; dir++) {
            int next_x = cur.x + dx[dir];
            int next_y = cur.y + dy[dir];
            
            if(next_x<0 || next_y<0 || next_x>=n || next_y>=m) continue;
            
            char next_char = v[next_x][next_y];
            
            int next_time;
            if(next_char=='#') {
                next_time = cur.timer + tb + 1; // 건물인 경우, 전파가 현시각+1이 아니라 여기에다가 +tb를 해줘야 됨
                
                if(next_time <= tg) { // tg 전까지 전파만 보면 됨 
                    v[next_x][next_y] = '*'; // 감염됐음을 표시 -> 다른 좌표에서 이 좌표를 탐색할 때 이미 감염되었다고 표시함으로써 다시 이 좌표를 중복 체크하지 않도록 하기 위함 
                
                    if(next_time < tg) pq.push({next_time, next_x, next_y}); // 탐색을 더 할 수 있는 경우에는 우선순위큐에 넣어줌 
                }
                else { // 시간 안에 건물이 감염되지 않는 경우
                    v[next_x][next_y] = '-'; // 감염 중임을 표시
                }
            }
            else if(next_char=='.') {
                next_time = cur.timer + 1;
                
                if(next_time<=tg) {
                    v[next_x][next_y] = '*';
                    
                    if(next_time<tg) pq.push({next_time, next_x, next_y});
                }
            }
        }
    }
    
    bool flag = false;
    
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(v[i][j]=='#' || v[i][j]=='-' || v[i][j]=='.') {
                flag = true;
                cout<<i+1<<" "<<j+1<<'\n';
            }
        }
    }
    
    if(!flag) cout<<-1;
    
    return 0;
}