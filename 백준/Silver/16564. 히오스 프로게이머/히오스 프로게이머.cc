#include <iostream>
#include <vector>
using namespace std;

#define ll long long

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    
    ll n,k; cin>>n>>k;
    
    vector<ll> v(n);
    for(ll i=0; i<n; i++) {
        cin>>v[i];
    }
    
    ll l=1, r=1e9*2; // 20억까지
    
    ll ans=0;
    
    while(l<=r) {
        ll mid = (l+r)/2;
        
        // 팀의 목표 레벨이 mid일 때 필요한 레벨 총합
        ll tmp=0;
        for(auto cur : v) {
            if(mid<=cur) continue; // 목표보다 이미 큰 레벨인 경우
            tmp+=(mid-cur);
        }
        
        if(tmp>k) { // 목표하는 레벨에 필요한 양이 k보다 큰 경우 -> 답이 될 수 있음 
            r = mid-1; // 목표하는 레벨을 줄여야 됨
        }
        else {
            l = mid+1;
            ans = max(ans, mid);
        }
    }
    
    cout<<ans;
    
    return 0;
}