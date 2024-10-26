#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(string s) {
    string answer;
    
    for(int i=0; i<s.length(); i++) {
        if(isdigit(s[i])) {
            answer += s[i];
        }
        else{ // 영어인 경우 s[i]부터 시작해서 해당하는 영어단어를 찾아야함
            if(s[i]=='z') {
                answer += '0';
                i+=3;
            }
            else if(s[i]=='o') {
                answer += '1';
                i+=2;
            }
            else if(s[i]=='t') {
                if(s[i+1]=='w') {
                    answer += '2';
                    i+=2;
                }
                else if(s[i+1]=='h') {
                    answer += '3';
                    i+=4;
                }
            }
            else if(s[i]=='f') {
                if(s[i+1]=='o') {
                    answer += '4';
                    i+=3;
                }
                else if(s[i+1]=='i') {
                    answer+='5';
                    i+=3;
                }
            }
            else if(s[i]=='s') {
                if(s[i+1]=='i'){
                    answer+='6';
                    i+=2;
                }
                else if(s[i+1]=='e'){
                    answer+='7';
                    i+=4;
                }
            }
            else if(s[i]=='e'){
                answer+='8';
                i+=4;
            }
            else if(s[i]=='n'){
                answer+='9';
                i+=3;
            }
        }
    }
    
    return stoi(answer);
}