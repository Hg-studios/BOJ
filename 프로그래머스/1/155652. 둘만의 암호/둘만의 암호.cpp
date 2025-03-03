#include <string>
#include <vector>
#include <map>
#include <iostream>
using namespace std;

string solution(string s, string skip, int index) {
    string answer = "";
    
    map<char, int> m;
    for(char c : skip) m[c]++;
    
    for(int i=0; i<s.size(); i++) {
        char c = s[i];
        for(int j=0; j<index; j++) {
            c++;
            //범위를 벗어나면 다시 a로 돌아옴
            if(c>'z') c='a';
            // skip하는 문자이면 하나 더 뒤로
            while(1) {
                if(!m[c]) break; // skip 문자열이 아닐때까지 
                c++;
                if(c>'z') c='a';
            }
            // if(m[c]==1) c++;
            
        }
        answer+=c;
    }
    
    return answer;
}