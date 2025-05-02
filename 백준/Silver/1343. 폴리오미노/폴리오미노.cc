#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    
    string ans;
    string s; cin>>s;
    
    int cnt=0;
    for(int i=0; i<s.size(); i++) {
        if(s[i]=='X') cnt++;
        else if(s[i]=='.') {
            ans+='.';
            
            if(cnt%2!=0) break; // .을 만나서 X개수만큼 출력해야 되는데 홀수 출력할 수 없음
            else cnt=0;
        }
        
        if(cnt==2 && s[i+1]!='X') {
            ans+="BB";
            cnt=0;
        }
        if(cnt==4) {
            ans+="AAAA";
            cnt=0;
        }
    }
    
    if(cnt%2==1) cout<<-1;
    else cout<<ans;
    
    return 0;
}