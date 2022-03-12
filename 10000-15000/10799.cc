#include <iostream>
#include <stack>
#include <string>
using namespace std;

/*
레이저가 되면 현재 존재하는 막대기 개수만큼을 잘라주고 
닫는 괄호가 나올 때 +1 만큼 해주면 됨 
왜냐하면 3번 자르면 4개의 조각이 생기므로 ..
*/

int main(){
  stack<int> s;
  int num=0; //잘려진 조각의 총 개수

  string str;
  getline(cin, str);

  for(int i=0; i<str.length(); i++){
    if(str[i] == '('){
      s.push(i);
    }
    else{ // ')'인 경우
      if(i-s.top()==1){ //'(' 다음에 바로 ')'가 나온 경우 => 레이저가 됨
        s.pop(); //일단, 가장 가까이에 있는 '('를 뺌
        num += s.size(); //그리고 존재하고 있는 막대기 개수만큼 더해줌 (현재 레이저로 쏘면 막대기 개수만큼 자른 게 생기므로)
      }
      else{ //바로 닫는 괄호가 나온 경우가 아니라면
        s.pop();
        num += 1; //3번 레이저로 자르면 4개가 생기니깐 
      }
    }
  }

  cout << num << '\n';
  
  return 0;
}
