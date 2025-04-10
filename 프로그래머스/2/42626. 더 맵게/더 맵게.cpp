#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    
    priority_queue<int, vector<int>, greater<int>> q;
    
    for(int x : scoville) q.push(x);
    
    while(!q.empty() && q.top()<K) {
        if(q.size()<2) {
            answer = -1;
            break;
        }
        
        answer++;
        
        int first = q.top();
        q.pop();
        int second = q.top();
        q.pop();
        
        q.push(first+second*2);
    }
    
    return answer;
}