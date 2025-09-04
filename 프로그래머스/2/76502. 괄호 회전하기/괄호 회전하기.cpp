#include <string>
#include <vector>
#include <stack>
#include <iostream>
using namespace std;

int solution(string s) {
    int answer = 0;
    
    int n = s.size();
    
    // 시작점
    for(int i=0; i<n; i++) {
        stack<char> stk;
        bool flag = true;
        
        // for(int j=i; j<i+n; j++) cout<<s[j%n];
        // cout<<'\n';
        
        for(int j=i; j<i+n; j++) {
            int idx = j%n;
            
            if(stk.empty()) stk.push(s[idx]);
            else if(s[idx]==')') {
                if(stk.top()!='(') { // 짝이 안맞는 경우
                    flag = false;
                    break;
                }
                stk.pop(); // 짝이 맞는 경우 제거해줌 
            }
            else if(s[idx]==']') {
                if(stk.top()!='[') {
                    flag = false; // 짝이 안맞는 경우
                    break;
                }
                stk.pop(); // 짝이 맞는 경우 제거해줌 
            }
            else if(s[idx]=='}') {
                if(stk.top()!='{') {
                    flag = false; // 짝이 안맞는 경우
                    break;
                }
                stk.pop(); // 짝이 맞는 경우 제거해줌 
            }
            else { // 열리는 괄호는 스택에 넣어줌
                stk.push(s[idx]); 
            }
        }
        
        if(!stk.empty()) flag = false;
        
        if(flag) answer++;
    }
    
    return answer;
}