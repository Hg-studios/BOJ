#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int n; cin>>n;
    
    while(n--) {
        string s1, s2; cin>>s1>>s2;
        
        int mx = max(s1.size(), s2.size());
        int mn = min(s1.size(), s2.size());
        
        for(int i=0; i<mx-mn; i++) {
            if(s1.size()<s2.size()) s1 = "0" + s1;
            else s2 = "0" + s2;
        }
        
        // cout<<s1<<" "<<s2<<'\n';
        
        int ca = 0;
        int sz = s1.size();
        string ans;
        for(int i=sz-1; i>=0; i--) {
            // cout<<s1[i]<<" ";
            if(s1[i]=='0' && s2[i]=='0') {
                if(ca==0) ans+="0";
                else {
                    ans+="1";
                    ca = 0;
                }
            }
            else if(s1[i]=='1' && s2[i]=='0') {
                if(ca==0) ans+="1";
                else {
                    ans+="0";
                    ca = 1;
                }
            }
            else if(s1[i]=='0' && s2[i]=='1') {
                if(ca==0) ans+="1";
                else {
                    ans+="0";
                    ca = 1;
                }
            }
            else { //s1[1]=='1' && s2[2]=='1'
                if(ca==0) {
                    ans+='0';
                    ca = 1;
                }
                else {
                    ans+='1';
                    ca=1;
                }
            }
        }
        if(ca==1) ans+='1';
        reverse(ans.begin(), ans.end());
        
        // 주어지는 수의 앞에 0이 들어올 수 있으므로 
        // 001 001 -> 10 
        // 위와 같은 예시도 만족해야 함 
        
        int s = ans.size()-1; // 모두 000 0000 이렇게만 왔을 때를 대비해서.. 
        for(int i=0; i<ans.size(); i++) {
            if(ans[i]=='1') {
                s= i;
                break;
            }
        }
        
        // cout<<s<<'\n';
        
        for(int i=s; i<ans.size(); i++) {
            cout<<ans[i];
        }
        cout<<'\n';
        
        // cout<<ans<<'\n';
        // cout<<'\n';
        
    }

    return 0;
}