#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

#define ll long long 

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    
    ll n, k; cin>>n>>k;
    
    vector<ll> v(n);
    for(ll i=0; i<n; i++) cin>>v[i];
    
    // 헉 이분탐색....??!!?!
    
    // 시간 많을수록 풍선은 많이 만들 수 있어서 k보다 많아지고, 적을수록 k개보다 작아짐
    // 즉, 계단형태!!!!
    // 추가로 범위가 넘 큼i
    // 1초부터 1000000까지 돌면서 확인하려고 했는데, i초에 스태프도 100만이라서 .. 넘 큼
    
    ll l=1, r=1000000000000;
    ll ans=0;
    
    while(l<=r) {
        ll mid = (l+r)/2;
        
        // mid 시간에 스태프가 몇 개 풍선 만들 수 있는지 확인
        ll tmp = 0;
        for(auto cur : v) tmp += mid/cur;
        
        if(tmp<k) { // 아직 시간이 짧아서 풍선을 다 못 만듦 -> 무조건 답이 아님
            l = mid+1;
        }
        else { // 시간이 너무 길어서 풍선을 많이 만듦 
            // -> 조건을 만족하긴 하는데 최소 시간을 찾아야 하므로 l<=r가 될 떄까지 계속 돌림
            r = mid-1;
            ans = mid; 
        }
    }
    
    cout<<ans;
    
    return 0;
}