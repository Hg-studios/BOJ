#include<string>
#include <iostream>
#include <stack>
using namespace std;

bool solution(string s)
{
    stack<char> st;
    
    for(char c : s) {
        if(c=='(') {
            st.push('(');
        }
        else {
            if(st.empty()) {
                return false;
            }
            st.pop();
        }
    }
    
    if(st.empty()) return true;
    else return false;
    
}