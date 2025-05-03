#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define ll long long

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    
    int n; cin>>n;
    vector<int> v(n);
    for(int i=0; i<n; i++) cin>>v[i];
    
    sort(v.begin(), v.end(), greater<int>());
    
    ll ans=0;
    for(int i=0; i<v.size(); i++) {
        if(v[i]-i<0) continue;
        
        ans+=(v[i]-i);
    }
    
    cout<<ans;
    
    return 0;
}