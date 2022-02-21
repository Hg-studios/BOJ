#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main(){
    int n;
    cin >> n;
    cin.ignore(); //�̰� �Ⱦ��� Ʋ��
		  //�ֳĸ� n�� �ް� �����ִ� ����~\n ������ �ؿ� str���� getline���� �������� ����
    
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