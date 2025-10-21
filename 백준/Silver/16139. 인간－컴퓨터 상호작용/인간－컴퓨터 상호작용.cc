#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

#define ll long long

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    
    string str; cin>>str;
    
    vector<vector<int>> sum(26, vector<int> (str.size(),0));
    for(int i=0; i<str.size(); i++) {
        sum[str[i]-'a'][i]=1; // 1을 표시
    }
    
    // for(int i=0; i<26; i++) {
    //     for(int j=0; j<str.size(); j++) {
    //         cout<<sum[i][j]<<" ";
    //     }
    //     cout<<'\n';
    // }
    
    
    for(int i=0; i<26; i++) {
        for(int j=1; j<str.size(); j++) {
            sum[i][j] += sum[i][j-1];
        }
    }
    
    // for(int i=0; i<26; i++) {
    //     for(int j=0; j<str.size(); j++) {
    //         cout<<sum[i][j]<<" ";
    //     }
    //     cout<<'\n';
    // }
    
    
    int q; cin>>q;
    
    while(q--) {
        char a;
        int l, r;
        cin>>a>>l>>r;
        
        ll tmp = sum[a-'a'][r];
        if(l-1>=0) tmp-=sum[a-'a'][l-1];
        cout<<tmp<<'\n';
    }
    
    return 0;
}