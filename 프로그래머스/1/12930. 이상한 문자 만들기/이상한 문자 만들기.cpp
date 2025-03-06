#include <string>
#include <vector>
#include <sstream>
#include <iostream>
using namespace std;

string solution(string s) {
    string answer = "";
    
    int idx=0;
    for(char c : s) {
        if(c==' ') {
            answer+=' ';
            idx=0;
        }
        else {
            if(idx%2==0) { //짝수인 경우
                if(c>='a') answer+=(c-('a'-'A')); //소문자인 경우
                else answer+=c;
            }
            else { //홀수인 경우
                if(c<='Z') answer+=(c+('a'-'A')); //대문자인 경우
                else answer+=c;
            }
            idx++;
        }
        
    }
    
    return answer;
}