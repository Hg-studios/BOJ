#include <string>
#include <vector>
#include <sstream>
#include <iostream>

using namespace std;

string solution(string s) {
    string answer = "";
    
    bool flag = true; // 첫번째 글자인지 확인
    for(int i=0; i<s.size(); i++) {
        if(s[i]==' ') { // 공백
            flag = true;
            continue;
        }
        if(flag) { // 첫번째 글자
            if(s[i]>='a' && s[i]<='z') {
                s[i] -= ('a'-'A');
            }
            flag = false;
        }
        else { // 첫번째 글자 아님 
            if(s[i]>='A' && s[i]<='Z') {
                s[i] += ('a'-'A');
            }
        }
    }
    
    answer = s;
    
    return answer;
}