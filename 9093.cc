#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main(){
    int n;
    cin >> n;
    cin.ignore(); //이걸 안쓰면 틀림
		  //왜냐면 n을 받고 남아있는 공백~\n 까지를 밑에 str에서 getline으로 가져오기 때문
    
    while(n--){
        string str;
        getline(cin,str);
        str += '\n';
        stack<char> s;
        
        for(char ch : str){
            if(ch==' ' || ch=='\n'){
                while(!s.empty()){
                    cout << s.top();
                    s.pop();
                }
                cout << ch;
            }
            else{
                s.push(ch);
            }
        }
    }
    
    return 0;
}