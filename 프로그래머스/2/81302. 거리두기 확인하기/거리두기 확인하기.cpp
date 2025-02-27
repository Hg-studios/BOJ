#include <string>
#include <vector>
#include <queue>

using namespace std;

int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};

typedef struct {
    int x,y,d;
}info;

bool BFS(int i, int j, vector<string>& place) {
    bool visited[5][5] = { false, };
    queue<info> q;
    
    visited[i][j]=true;
    q.push({i,j,0});
    
    while(!q.empty()) {
        auto cur = q.front();
        int x = cur.x;
        int y = cur.y;
        int d = cur.d;
        q.pop();
        
        for(int dir=0; dir<4; dir++) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            
            if(nx<0||ny<0||nx>=5||ny>=5) continue;
            if(visited[nx][ny]) continue;
            if(place[nx][ny]=='X') continue;
            
            if(place[nx][ny]=='P') {
                if(d+1<=2) return false;
            }
            
            visited[nx][ny]=true;
            q.push({nx,ny,d+1});
        }
    }
    
    return true;
}

bool solve(vector<string>& place) {
    for(int i=0; i<5; i++) {
        for(int j=0; j<5; j++) {
            if(place[i][j]=='P') {
                // 하나라도 거리두기가 지켜지지 않았다면 false
                if(!BFS(i,j,place)) return false;
            }
        }
    }
    return true;
}

vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;
    
    for(auto place : places) {
        if(solve(place)) answer.push_back(1);
        else answer.push_back(0);
    }
    
    return answer;
}