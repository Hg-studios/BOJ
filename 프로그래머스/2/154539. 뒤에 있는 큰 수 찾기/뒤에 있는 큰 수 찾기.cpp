#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> numbers) {
    int n = (int)numbers.size();
    vector<int> answer(n, -1);
    // std::stack<int>보다 vector<int>를 스택처럼 쓰면 약간 더 빠른 경우가 많음
    vector<int> st;
    st.reserve(n);

    for (int i = 0; i < n; ++i) {
        // 현재 값이 스택 상단(아직 미해결)의 값보다 크면 답을 채운다
        while (!st.empty() && numbers[st.back()] < numbers[i]) {
            answer[st.back()] = numbers[i];
            st.pop_back();
        }
        st.push_back(i);
    }
    // 남은 인덱스는 기본값 -1 유지
    return answer;
}
