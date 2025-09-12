#include <string>
#include <vector>
#include <stack>
using namespace std;

vector<int> solution(vector<int> numbers) {
    int n = numbers.size();
    vector<int> ans(n, -1);
    
    // stack에 저장되어있는 인덱스 값은 이미 지나온 값임
    // 즉, 현재 값과 스택에 저장되어 있는 값을 비교하는 것은 과거값과 비교하는 것이므로
    // stack의 top과 비교해서 나보다 작은 수가 있을 때까지 나의 값으로 ans를 채움
    
    stack<int> s; // 인덱스 저장
    for(int i=0; i<n; i++) {
        while(!s.empty() && numbers[s.top()] < numbers[i]) {
            ans[s.top()] = numbers[i];
            s.pop();
        }
        s.push(i);
    }
    
    return ans;

}
