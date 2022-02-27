#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main(){
  stack<char> s; //태그를 제외한 나머지를 넣음, 공백을 기준으로 출력함
  
  string str;
  getline(cin, str);
  str += '\n';
  
  int tagCheck = 0; //태그인지 체크하는 변수
  
  for(char ch : str){
    if(ch == '<' && tagCheck==0){ //여는 괄호
      while(!s.empty()){ //<가 오기 전에 스택에 있던 문자열 전부 출력 *놓치기 쉬운 부분임* 
          cout << s.top();
          s.pop();
      }
      tagCheck = 1;
      cout << ch;
    }
    else if(ch == '>' && tagCheck==1){ //닫는 괄호 
      tagCheck = 0;
      cout << ch;
    }
    else if(tagCheck == 1){ //태그 안의 문자열
      cout << ch;
    }
    else{ //태그가 아닌 문자열
      if(ch==' ' || ch=='\n'){ //빈칸이거나 개행이면 스택에 있는 것을 전부 빼줌
        while(!s.empty()){
          cout << s.top();
          s.pop();
        }
        if(ch==' ') cout << " ";
      }
      else{ //빈칸이 아니면 스택에 넣어줌 
        s.push(ch);
      }
    }
  }
  cout << '\n';
  return 0;
}