#include <vector>
#include <stack>
using namespace std;

int solution(vector<int> order) {
    int n = (int)order.size();
    stack<int> sub;        // 보조 컨베이어(스택)
    int nextBox = 1;       // 메인 벨트에서 다음으로 볼 상자 번호 (1..n)
    int idx = 0;           // order에서 현재 실어야 하는 위치
    // 메인 벨트를 순차적으로 훑으면서 가능한 한 많이 싣는다
    while (nextBox <= n) {
        // 1) 메인 벨트 앞의 상자가 지금 실어야 하는 상자라면 바로 싣는다
        if (order[idx] == nextBox) {
            nextBox++;
            idx++;
            // 그 다음, 보조 벨트 top이 연달아 필요한 상자면 계속 싣는다
            while (!sub.empty() && idx < n && sub.top() == order[idx]) {
                sub.pop();
                idx++;
            }
        }
        // 2) 아니면 그 상자를 보조 벨트에 잠시 넣는다
        else {
            sub.push(nextBox);
            ++nextBox;
        }
    }
    // 메인 벨트가 끝난 뒤에도 보조 벨트에서 더 실을 수 있으면 계속 싣는다
    while (!sub.empty() && idx < n && sub.top() == order[idx]) {
        sub.pop();
        idx++;
    }
    
    return idx; // 적재한 상자 수
}
