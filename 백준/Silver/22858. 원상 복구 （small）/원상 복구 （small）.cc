#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n,k; cin>>n>>k;
    
    vector<int> s(n+1);
    vector<int> d(n+1);
    
    for(int i=1; i<=n; i++) cin>>s[i];
    for(int i=1; i<=n; i++) cin>>d[i];
    
    while(k--) {
        vector<int> tmp(n+1);
        
        for(int i=1; i<=n; i++) {
            // n번째 수는 Dn에서 온 것
            tmp[d[i]] = s[i];
        }
        s = tmp;
    }
    
    for(int i=1; i<=n; i++) cout<<s[i]<<" ";
    
    return 0;
}