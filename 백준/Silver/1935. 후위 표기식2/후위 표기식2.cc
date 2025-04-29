#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main()
{
    stack<double> s;
    
    int n; cin>>n;
    string str; cin>>str;
    
    vector<double> v(n);
    for(int i=0; i<n; i++) cin>>v[i];
    
    for(int i=0; i<str.length(); i++) {
        if(str[i]>='A' && str[i]<='Z') {
            s.push(v[str[i]-'A']);
        }
        else {
            // 연산자가 나오면 수 2개를 꺼내서 계산 후 결과를 다시 넣어줌 
            double op2 = s.top();
            s.pop();
            
            double op1 = s.top();
            s.pop();
            
            double result=0;
            if(str[i]=='+') result = op1+op2;
            else if(str[i]=='-') result = op1-op2;
            else if(str[i]=='*') result = op1*op2;
            else result = op1/op2;
            
            s.push(result); 
            // cout<<op1<<" "<<op2<<" "<<result<<'\n';
        }
    }
    
    // cout<<s.top();
    printf("%.2f", s.top());
    
    return 0;
}