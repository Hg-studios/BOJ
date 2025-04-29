#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    
    int n,m; cin>>n>>m;
    
    map<string, int> mp;
    for(int i=1; i<=n; i++) {
        string s; cin>>s;
        mp[s]=i;
    }
    
    int cnt=0;
    while(m--) {
        string s; cin>>s;
        if(mp[s]) cnt++;
    }
    
    cout<<cnt;
    
    return 0;
}