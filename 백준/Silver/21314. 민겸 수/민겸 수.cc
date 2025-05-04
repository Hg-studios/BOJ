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
    
    // 최대
    // 최대한 K까지 포함하면 최대값임
    int cnt=0; // M의 개수를 셈
    string mx;
    for(int i=0; i<=s.size(); i++) {
        if(i==s.size()) { // M만 계속 오느라고 처리를 못한 경우
            if(cnt==0) continue;
            
            // 뒤에 K가 붙지 않은 경우는 연속된 M은 각각 따로 처리해주는 게 최대임 
            // MMM -> 111 이 100 보다 큼 !
            for(int j=0; j<cnt; j++) mx += "1";
        }
        else if(s[i]=='K') {
            mx += "5";
            for(int j=0; j<cnt; j++) mx+="0";
            cnt=0;
        }
        else if (s[i]=='M') {
            cnt++;
        }
    }
    cout<<mx<<'\n';
    
    
    // 최소
    // 최대한 M을 포함하고 K를 포함하지 않으면 최소값임
    cnt=0;
    string mn;
    for(int i=0; i<=s.size(); i++) {
        if(i==s.size()) {
            if(cnt==0) continue;
            
            mn+="1";
            for(int j=0; j<cnt-1; j++) mn += "0";
        }
        else if(s[i]=='K') {
            // 그동안의 M을 처리하고 K를 붙여줌
            if(cnt!=0) { //M을 함께 처리해줘야 할 때
                mn+="1";
                for(int j=0; j<cnt-1; j++) mn += "0";
                // mn += to_string(tmp);
            }
            mn += "5";
            
            cnt=0;
        }
        else if(s[i]=='M') {
            cnt++;
        }
        // cout<<i<<" "<<mn<<"\n";
    }
    cout<<mn;
    
    
    return 0;
}