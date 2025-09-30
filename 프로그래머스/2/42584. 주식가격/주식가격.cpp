#include <string>
#include <vector>
#include <stack>

using namespace std;

vector<int> solution(vector<int> prices) {
    int n = prices.size();
    vector<int> ans(n, 0);
    stack<int> st; // 아직 떨어지는 시점을 못 만난 인덱스들

    for (int i = 0; i < n; ++i) {
        // 새 가격이 들어왔을 때, 이전들보다 작아지면 답 확정
        while (!st.empty() && prices[i] < prices[st.top()]) {
            int idx = st.top(); st.pop();
            ans[idx] = i - idx; // 처음 떨어진 순간까지의 시간
        }
        st.push(i);
    }

    // 끝까지 안 떨어진 애들 처리
    while (!st.empty()) {
        int idx = st.top(); st.pop();
        ans[idx] = (n - 1) - idx;
    }
    return ans;
}