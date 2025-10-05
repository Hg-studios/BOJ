/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include <map>
#include <vector>
using namespace std;

string solve(string str) {
    
    // 한 문장 안에서 각 알파벳이 몇 번에 나왔는지 표시
    int idx=1;
    vector<int> cnt(str.size(), 0);
    
    for(int i=0; i<str.size(); i++) {
        if(cnt[i]!=0) continue;
        
        // 현재 알파벳이랑 같은 알파벳을 모두 idx로 저장해줌
        cnt[i]=idx;
        for(int j=i+1; j<str.size(); j++) {
            if(str[i]==str[j]) cnt[j]=idx;
        }
        
        idx++;
    }
    
    string tmp;
    for(int i=0; i<str.size(); i++) {
        tmp += to_string(cnt[i]);
    }
    
    // cout<<tmp<<'\n';
    
    return tmp;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    
    int n; cin>>n;
    
    map<string, int> m;
    
    while(n--) {
        string str; cin>>str;
        
        m[solve(str)]++;
    }
    
    int ans = 0;
    for(auto cur : m) {
        int cnt = cur.second;
        
        if(cnt==1) continue; // 쌍이 없는 경우
        else if(cnt>=2) { // 모든 쌍의 개수 
            ans += cnt*(cnt-1)/2;
        }
    }
    
    cout<<ans;
    
    return 0;
}