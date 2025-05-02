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
        if(s[i]=='.') {
            // ans+='.';
        
            // 현재 cnt값으로 그리디하게 문자열 구해주기 
            // cnt가 0이면 그 전에도 . 이었다는 말이므로 출력하는 부분을 건너뜀 
            if(cnt==0) {
                ans+='.';
                continue; 
            }
            
            //일단 AAAA를 넣고 나머지 자리에 BB 넣기
            int four = cnt/4;
            for(int i=0; i<four; i++) ans+="AAAA";
            
            int two = (cnt - 4*four)/2;
            for(int i=0; i<two; i++) ans+="BB";
            
            if(cnt-4*four-2*two!=0) {
                cout<<"-1";
                return 0;
            }
            ans+='.';
            cnt=0;
        }
        else {
            cnt++;
        }
    }
    
    // cout<<cnt;
    if(cnt!=0) {
        //일단 AAAA를 넣고 나머지 자리에 BB 넣기
        int four = cnt/4;
        for(int i=0; i<four; i++) ans+="AAAA";
        // cout<<four<<" ";
        
        int two = (cnt - 4*four)/2;
        for(int i=0; i<two; i++) ans+="BB";
        // cout<<two<<" ";
        
        int remain = cnt-4*four-2*two;
        // cout<<remain<<" ";
        if(remain!=0) {
            cout<<"-1";
            return 0;
        }
    }
    cout<<ans;
    
    
    return 0;
}