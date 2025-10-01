#include <string>
#include <vector>
#include <stack>

using namespace std;

vector<int> solution(vector<int> prices) {
    int n = prices.size();
    vector<int> ans(n, 0);
    stack<int> s;
    
    for(int i=0; i<n; i++) {
        while(!s.empty() && prices[s.top()]>prices[i]) {
            // 끝나기 전에 뽑힌 경우
            // 이전에 스택에 쌓인 인덱스의 값을 결정해줌
            ans[s.top()] = (i-s.top());
            s.pop();
        }
        s.push(i);
    }
    
    // 아직 뽑히지 않은 인덱스들은 끝까지 떨어지는 가격이 없었던 것임
    while(!s.empty()) {
        ans[s.top()] = n-1-s.top();
        s.pop();
    }
    
    return ans;
}