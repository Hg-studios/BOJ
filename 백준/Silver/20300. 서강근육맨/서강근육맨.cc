#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define ll long long
int main()
{
    int n; cin>>n;
    vector<ll> v(n);
    for(int i=0; i<n; i++) cin>>v[i];
    
    if(v.size()%2==1) v.push_back(0);
    sort(v.begin(), v.end());
    
    ll mx = -1;
    for(int i=0; i<v.size()/2; i++) {
        mx = max(mx, v[i]+v[v.size()-i-1]);
    }
    
    cout<<mx;
    
    return 0;
}