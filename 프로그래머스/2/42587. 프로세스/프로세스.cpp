#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <iostream>

#define X first
#define Y second

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    
    int n = priorities.size();
    
    queue<pair<int,int>> q;
    for(int i=0; i<n; i++) {
        q.push({priorities[i], i}); //우선순위, 인덱스
    }
    
    while(!q.empty()) {
        // answer++;
        
        // 큐의 가장 앞에 있는 걸 꺼내서 우선순위가 가장 큰 것인지 확인하고 아니라면 다시 넣고를 반복함
        // 가장 큰 우선순위를 가진 인덱스가 나올 때까지
        auto cur = q.front();
        q.pop();
        
        auto mx = max_element(priorities.begin(), priorities.end());
        cout<<mx-priorities.begin()<<" "<<*mx<<'\n';
        
        // 현재 뽑은 게 가장 높은 우선순위인 경우
        if(cur.X == *mx) {
            // 큐에는 다시 넣지 않아도 됨
            // 우선순위 배열에서 현재 우선순위를 없애줌
            priorities.erase(mx);
            answer++;
            
            // 만약 찾고 있던 인덱스 위치였다면 바로 return
            if(cur.Y == location) return answer;
        }
        
        // 아닌 경우
        // 뽑은 걸 다시 넣어줘야 함
        else {
            q.push(cur);
        }
        
    }
    
    
    return answer;
}