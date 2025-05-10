#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    string s; 
    getline(cin,s);
    
    string tmp="";
    bool isPar = false;
    for(int i=0; i<s.size(); i++) {
        // 괄호 안에 값들은 뒤집으면 안됨
        if(s[i]=='<') {
            // 앞에 tmp에 저장된 값이 있었다면 처리해줌 
            if(tmp!="") {
                reverse(tmp.begin(), tmp.end());
                cout<<tmp;
                tmp="";
            }
            
            tmp+='<';
            isPar = true;
        }
        // 괄호가 끝났으면 그대로 출력해줌 
        else if(s[i]=='>') {
            tmp+='>';
            cout<<tmp;
            tmp=""; //초기화
            isPar=false;
        }
        // 빈칸이면서 괄호가 아니면 거꾸로 출력해줌
        else if(s[i]==' ' && !isPar){
            reverse(tmp.begin(), tmp.end());
            cout<<tmp;
            cout << ' '; // 공백 따로 출력
            tmp="";
        }
        // 빈칸이면서 괄호 안에 있는 경우
        // 혹은 그냥 글자인 경우 
        else {
            tmp+=s[i];
        }
    }
    
    if(tmp!="") {
        reverse(tmp.begin(), tmp.end());
        cout<<tmp;
    }
    
    
    return 0;
}