#include <string>
#include <vector>
#include <queue>
#include <sstream>
#include <algorithm>
#include <iostream>

using namespace std;

char arr[52][52];
int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};

vector<int> solution(vector<string> park, vector<string> routes) {
    vector<int> answer;
    
    
    // 시작위치 찾기
    int n = park.size();
    int m = park[0].size();
    
    int curx, cury;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(park[i][j]=='S') {
                curx=i;
                cury=j;
            }
        }
    }
    
    for(string route : routes) {
        istringstream ss(route);
        char tmp_dir;
        int dis;
        ss>>tmp_dir>>dis;
        
        // N과 같이 저장한 값을 숫자로 변환
        int dir;
        if(tmp_dir=='N') dir=0;
        else if(tmp_dir=='S') dir=1;
        else if(tmp_dir=='W') dir=2;
        else dir=3;
        
        int nx = curx + dx[dir] * dis;
        int ny = cury + dy[dir] * dis;
        
        // 범위를 벗어나는지 확인
        if(nx<0||ny<0||nx>=n||ny>=m) continue;
        // 가는 길에 장애물을 만나는지 확인
        bool flag=false;
        for(int i=1; i<=dis; i++) {
            int tmpx = curx + dx[dir]*i;
            int tmpy = cury + dy[dir]*i;
            
            if(park[tmpx][tmpy]=='X') {
                flag=true;
                break;
            }
        }
        if(flag) continue;
        
        // 현재 좌표에서 이동
        curx = nx;
        cury = ny;
    }
    
    answer.push_back(curx);
    answer.push_back(cury);
    
    return answer;
}