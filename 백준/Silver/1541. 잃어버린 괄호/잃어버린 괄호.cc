#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define ll long long

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr); cout.tie(nullptr);
    
    string s; cin>>s;
    
    string ss; // 피연산자 저장
    bool minus=false;
    int ans=0;
    
    for(int i=0; i<=s.length(); i++) {
        if(s[i]=='+' || s[i]=='-' || i==s.length()) {
            if(minus) ans -= stoi(ss);
            else ans += stoi(ss);
            
            ss="";
        }
        else {
            ss += s[i];
        }
        
        if(s[i]=='-') minus=true;
    }
    
    cout<<ans;
    
    return 0;
}