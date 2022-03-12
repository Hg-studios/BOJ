#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main(){
  stack<char> l; //커서 기준 왼쪽 문자열 저장 스택
  stack<char> r; //커서 기준 오른쪽 문자열 저장 스택

  string str;
  cin >> str;

  for(char ch : str){ //읽은 str의 글자 하나하나를 l 스택에 저장
    l.push(ch);
  }
  
  int n;
  cin >> n;
  cin.ignore();
  
  while(n--){
    string cmd;
    getline(cin, cmd);
    
    if(cmd == "L"){
      if(!l.empty()){
        char ch1 = l.top(); //가장 위에 있는 걸 꺼내서
        r.push(ch1); //r로 옮겨주고
        l.pop(); //가장 위에 것을 삭제해줌
      }
    }
    else if(cmd == "D"){
      if(!r.empty()){
        char ch2 = r.top();
        l.push(ch2);
        r.pop();
      }
    }
    else if(cmd == "B"){
      if(!l.empty()){
        l.pop();
      }
    }
    else if(cmd[0] == 'P'){
      l.push(cmd[2]);
    }
  }

  while(!l.empty()){
    char ch = l.top();
    l.pop();
    r.push(ch);
  }

  while(!r.empty()){
    cout << r.top();
    r.pop();
  }
  cout << '\n';
  
  return 0;
}
