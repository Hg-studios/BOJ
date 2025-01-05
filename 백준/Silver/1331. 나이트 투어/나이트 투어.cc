#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<pair<int,int>> v;
bool visited[7][7];

bool valid(int curx, int cury, int nextx, int nexty) {
    if((curx-2==nextx && cury-1==nexty) ||
        (curx-1==nextx && cury-2==nexty)||
        (curx+1==nextx && cury-2==nexty)||
        (curx+2==nextx && cury-1==nexty)||
        (curx-2==nextx && cury+1==nexty)||
        (curx-1==nextx && cury+2==nexty)||
        (curx+1==nextx && cury+2==nexty)||
        (curx+2==nextx && cury+1==nexty)) {
        return true;
    }
    else {
        return false;
    }
}

int main()
{
    for(int i=0; i<36; i++) {
        string s; cin>>s;
        v.push_back({s[0]-'A', s[1]-'1'});
    }
    
    visited[v[0].first][v[0].second]=true;
    
    for(int i=0; i<35; i++) {
        int curx = v[i].first;
        int cury = v[i].second;
        int nextx = v[i+1].first;
        int nexty = v[i+1].second;
        
        // 이미 방문한 좌표라면 틀림
        if(visited[nextx][nexty]) {
            cout<<"Invalid";
            return 0;
        }
        
        // 현재 좌표에서 나이트가 갈 수 있는 8개 중 하나의 좌표인지 확인
        if(valid(curx, cury, nextx, nexty)) {
            // 조건에 맞는 좌표라면 방문 표시
            visited[nextx][nexty]=true;
            continue;
        }
        else {
            // 나이트가 갈 수 없는 곳을 간 경우
            cout<<"Invalid";
            return 0;
        }
    }
    
    //마지막 점에서 시작점으로 돌아올 수 있는지 확인
    if(valid(v[35].first, v[35].second, v[0].first, v[0].second)) {
        cout<<"Valid";    
    }
    else {
        cout<<"Invalid";
    }
    return 0;
}