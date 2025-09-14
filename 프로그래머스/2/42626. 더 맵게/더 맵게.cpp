#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

#define ll long long

int solution(vector<int> scoville, int K) {
    int answer = 0;
    
    priority_queue<int, vector<int>, greater<int>> pq(scoville.begin(), scoville.end());
    
    while(1) {
        if(pq.top()>=K) {
            return answer;
        }
        
        // 아직 모든 음식의 스코빌 지수가 K 이상이 안됐다면
        if(pq.empty()) {
            return -1;
        }
        int x = pq.top();
        pq.pop();
        
        if(pq.empty()) {
            return -1;
        }
        int y = pq.top();
        pq.pop();
        
        pq.push(x+y*2);
        answer++;
    }
    
    
    return answer;
}