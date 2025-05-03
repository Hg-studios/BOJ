#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
using namespace std;

#define ll long long

int main()
{
    int n; cin>>n;
    
    vector<ll> dist(n-1);
    vector<ll> cost(n);
    
    for(int i=0; i<n-1; i++) cin>>dist[i];
    for(int i=0; i<n; i++) cin>>cost[i];
    
    ll mn = INT_MAX;
    ll ans=0;
    for(int i=0; i<n-1; i++) {
        mn = min(mn, cost[i]);
        ans += mn * dist[i];
    }
    
    cout<<ans;
    
    return 0;
}