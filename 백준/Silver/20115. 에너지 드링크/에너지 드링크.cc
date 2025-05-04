#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
using namespace std;

#define ll long long

int main()
{
    int n; cin>>n;
    vector<ll> v(n);
    
    ll sum=0;
    for(int i=0; i<n; i++) {
        cin>>v[i];
        sum+=v[i];
    }
    ll mx = *max_element(v.begin(), v.end());
    // cout<<sum<<" "<<mx<<" ";
    cout<<sum-(double)(sum-mx)/2;
    
    return 0;
}