#include <iostream>
#include <string>
#include <map>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(nullptr); cout.tie(nullptr);
    
    int n; cin>>n;
    
    map<string, int> m;
    
    while(n--) {
        string s; cin>>s;
        
        int idx = s.find('.');
        string ss = s.substr(idx+1);
        m[ss]++;
    }
    
    for(auto x : m) cout<<x.first<<" "<<x.second<<'\n';
    
    return 0;
}