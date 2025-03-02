#include <iostream>
#include <vector>
#include <limits.h>
#define ll long long 
using namespace std;
int main()
{
    int n; cin>>n;
    
    vector<ll> v(n+1,0);
    for(int i=1; i<=n; i++) cin>>v[i];
    
    vector<ll> sum = v;
    for(int i=2; i<=n; i++) sum[i] += sum[i-1];
    
    // for(int x : sum) cout<<x<<" ";
    
    ll ans=INT_MAX;
    int ans_k=-1;
    // k는 1부터 n-1까지 가능함
    for(int k=1; k<n; k++) {
        vector<ll> vv;
        
        for(int i=k; i<=n; i++) {
            // if(i-k<1) vv.push_back(sum[i]);
            // else vv.push_back(sum[i]-sum[i-k]);
            ll x = sum[i]-sum[i-k];
            // cout<<"k "<<i<<'\n';
            // cout<<"x "<<x<<'\n';
            for(int j=i+k; j<=n; j++) {
                ll y = sum[j]-sum[j-k];
                // cout<<"y "<<y<<'\n';
                if(abs(x-y)<ans) {
                    ans = abs(x-y);
                    ans_k = k;
                }
                else if(abs(x-y)==ans) {
                    if(ans_k<i) ans_k = k;
                }
            }
        }
        
        
        // cout<<ans;
        // for(ll x : vv) cout<<x<<" ";
        // cout<<'\n';
        
        // for(ll x : vv) {
        //     ans = min(ans, abs(x-vv[0]));
        // }
    }
    
    cout<<ans_k<<'\n';
    cout<<ans;
    
    return 0;
}