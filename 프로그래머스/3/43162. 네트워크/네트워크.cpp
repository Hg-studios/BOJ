#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

bool visited[201];

// i는 방문하지 않은 노드
void dfs(int i, vector<vector<int>>& computers){
    visited[i] = true;
    
    for(int j=0; j<computers[i].size(); j++) {
        if(computers[i][j]==0) continue;
        if(visited[j]) continue;
        
        dfs(j, computers);
    }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    
    for(int i=0; i<n; i++) {
        // 이미 방문한 곳은 건너뜀
        if(visited[i]) continue;
        
        answer++;
        
        dfs(i, computers);
    }
    
    return answer;
}