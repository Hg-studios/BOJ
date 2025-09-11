#include <string>
#include <map>
#include <iostream>
using namespace std;
#define X first 
#define Y second

bool visited[12][12][4]; // U D R L 순서로 저장
map<char, pair<int,int>> m;
map<char, int> d; // U L R D 순서로 저장

int solution(string dirs) {
    int cnt = 0;
    
    m['U'] = {-1,0};
    m['D'] = {1,0};
    m['R'] = {0,1};
    m['L'] = {0,-1};
    
    // u와 d는 서로 합쳐서 3, l와 r도 서로 합쳐서 3
    d['U'] = 0;
    d['L'] = 1;
    d['R'] = 2;
    d['D'] = 3;
    
    // for(auto cur : m) cout<<cur.first<<" "<<cur.second.first<<" "<<cur.second.second<<'\n';
    
    pair<int,int> cur = {5,5};
    
    for(char dir : dirs) {
        // 현재 좌표에다가 뽑힌 dir 방향으로 이동시킴
        int nx = cur.X + m[dir].X;
        int ny = cur.Y + m[dir].Y;
        
        // cout<<nx<<" "<<ny<<'\n';
        
        if(nx<0||ny<0||nx>10||ny>10) continue; // 범위를 벗어난 경우
        
        
        
        // 아직 가지 않은 좌표라면 cnt 해줌
        // 1. 내 좌표에서 이동하는 방향을 체크
        // 2. 이동한 좌표에서 내 좌표로 이동하는 방향을 체크
        if(!visited[cur.X][cur.Y][d[dir]] && !visited[nx][ny][3-d[dir]]) {
            cnt++;
            visited[cur.X][cur.Y][d[dir]] = true;
            visited[nx][ny][3-d[dir]] = true;
        }
        
        // 범위를 벗어나지 않는다면 실제로 이동시킴
        cur.X = nx;
        cur.Y = ny;
        
    }
    
    return cnt;
}