#include <iostream>
#include <stack>
#include <string>
using namespace std;

#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main(){
    int n;
    cin >> n;
    cin.ignore(); //이거안쓰면 틀림 
    
    while(n--){
        string str;
        getline(cin,str);
        stack<int> s;
        string result;

        for(int i=0; i<str.length(); i++){
            if(str[i] == '('){ //'(' 일때는 스택에 넣음
                s.push(1);
            }
            else if(str[i] == ')'){ //')' 일때는 스택에서 빼줘야함
              if(s.empty()){ //아무것도 없다면 틀린 것임
                result = "NO";
                break;
              }
              else{
                s.pop();
              }
            }

            if(i==str.length()-1){ //마지막거까지 다 하고 나서
              if(s.empty()) result = "YES";
              else result = "NO";
            }
        }
        cout << result << '\n';
    }
    
    return 0;
}