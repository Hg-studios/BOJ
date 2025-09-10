#include <vector>
#include <queue>
#include <iostream>
#include <queue>
using namespace std;

#define X first
#define Y second

int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};

int solution(vector<vector<int>> maps)
{
    int n = maps.size();
    int m = maps[0].size();
    
    vector<vector<int>> dist(n, vector<int> (m,-1));
    queue<pair<int,int>> q;
    
    dist[0][0]=1;
    q.push({0,0});
    
    while(!q.empty()) {
        auto cur = q.front();
        q.pop();
        
        if(cur.X==n-1 && cur.Y==m-1) {
            return dist[cur.X][cur.Y];
        }
        
        for(int dir=0; dir<4; dir++) {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            
            if(nx<0||ny<0||nx>=n||ny>=m) continue;
            if(dist[nx][ny]!=-1) continue;
            if(maps[nx][ny]==0) continue;
            
            dist[nx][ny] = dist[cur.X][cur.Y]+1;
            q.push({nx,ny});
        }
    }
    
    return -1;
}