#include <string>
#include <map>
#include <iostream>
using namespace std;
#define X first 
#define Y second

bool visited[12][12][4]; // U D R L 순서로 저장
int dx [] = {1,0,0,-1};
int dy [] = {0,1,-1,0};

int solution(string dirs) {
    pair<int, int> cur = {5,5};
    int cnt=0;
    
    for(auto d : dirs) {
        int dir=0;
        
        if(d=='U') dir=3;
        else if(d=='D') dir=0;
        else if(d=='L') dir=2;
        else dir=1;
        
        int nx = cur.X + dx[dir];
        int ny = cur.Y + dy[dir];
        
        if(nx<0||ny<0||nx>=11||ny>=11) continue;
        
        if(!visited[cur.X][cur.Y][dir]) {
            visited[cur.X][cur.Y][dir] = true;
            visited[nx][ny][3-dir] = true;
            cnt++;
        }
        
        cur = {nx,ny};
    }

    return cnt;
}