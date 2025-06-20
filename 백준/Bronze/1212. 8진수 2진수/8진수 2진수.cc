#include <iostream>
#include <algorithm>
using namespace std;

string convert(int num) {
    // 8진수를 2진수로 바꾸기 위해서는 8진수의 각 수를 2진수 3자리로 표현해주면 된다
    string tmp="";
    
    while(num!=0) {
        tmp+=to_string(num%2);
        num/=2;
    }
    
    reverse(tmp.begin(), tmp.end());
    // cout<<tmp<<" ";
    return tmp;
}

int main()
{
    string s; cin>>s;
    string ans="";
    
    // 반례 : 0일 때 처리해주기 **
    if(s=="0") {
        cout<<0;
        return 0;
    }
    
    for(int i=0; i<s.size(); i++) {
        if(i==0) ans += convert(s[i]-'0');
        else {
            // 처음이 아니라면 무조건 0을 채워서 3자리를 만들어줘야 함
            string tmp = convert(s[i]-'0');
            
            // 3자리가 되어야 함 
            // 즉, 3자리가 되지 않았다면 계속 돔
            while(tmp.size()<3) {
                tmp = '0' + tmp;
            }
            
            ans += tmp;
        }
    }
    
    cout<<ans;
    
    return 0;
}

