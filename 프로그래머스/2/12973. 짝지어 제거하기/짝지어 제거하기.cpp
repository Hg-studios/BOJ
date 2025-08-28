#include <iostream>
#include<string>
#include <vector>
#include <stack>
using namespace std;

int solution(string str)
{
    // 아 대박 스택이구나 .........
    stack<char> s;
    
    for(int i=0; i<str.size(); i++) {
        if(s.empty()) s.push(str[i]);
        
        else {
            if(s.top()==str[i]) s.pop();
            else s.push(str[i]);
        }
    }
    
    if(!s.empty()) return 0;
    
    return 1;
}