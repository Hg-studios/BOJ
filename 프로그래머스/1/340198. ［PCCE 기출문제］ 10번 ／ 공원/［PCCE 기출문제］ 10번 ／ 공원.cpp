#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int n,m;

bool checkSquare(int x, int y, int size, vector<vector<string>>& park) {
    for(int i=x; i<x+size; i++) {
        for(int j=y; j<y+size; j++) {
            if(park[i][j]!="-1") return false;
        }
    }
    
    return true;
}

int solution(vector<int> mats, vector<vector<string>> park) {
    // 부르트포스로 할 것 
    
    // 내림차순으로 정렬
    sort(mats.begin(), mats.end(), greater<>());
    
    n = park.size();
    m = park[0].size();
    
    int answer=-1;
    
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            // 비어있는 칸을 발견했다면
            if(park[i][j]!="-1") continue;
            
            // 각 칸에서 큰 정사각형부터 넣으면서 확인해봄
            for(int k=0; k<mats.size(); k++) {
                // 이미 큰 돗자리 값을 구해놨다면 굳이 작은 돗자리 검사하지 않아도 됨
                if(answer>mats[k]) continue;
                
                // 돗자리를 넣을 수 없다면 검사하지 않음 **범위넘어가지않도록주의**
                if(i+mats[k]>n || j+mats[k]>m) continue;
                
                // 돗자리가 들어가면 checkSquare함수는 true를 반환
                if(checkSquare(i,j,mats[k], park)){
                    if(answer<mats[k]) answer = mats[k];
                }
            }
        }
    }
    
    return answer;
}