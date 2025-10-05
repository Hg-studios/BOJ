#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

#define ll long long

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    
    ll s, c; cin>>s>>c;
    
    vector<ll> v(s);
    for(ll i=0; i<s; i++) cin>>v[i];
    
    // 이분 탐색
    // 최대한 큰 정수로 자르면서, c개의 파를 만들 수 있는 지 봐야함 
    
    ll l=1, r=*max_element(v.begin(), v.end());
    ll mx=0; // 파의 양
    
    while(l<=r) {
        ll mid = (l+r)/2;
        
        // mid 크기로 파를 몇 개 얻을 수 있는지
        ll tmp=0;
        for(auto cur : v) tmp += (cur/mid);
        
        if(tmp<c) { // 너무 크게 자른 경우
            r = mid-1;
        }
        else { // 너무 작게 자른 경우 (파의 크기가 작은 경우임)
            // 필요한 파의 개수를 얻긴 함
            l = mid+1;
            mx = max(mx, mid);
        }
    }
    
    ll ans=0;
    
    ll tmp=0; // 현재까지 몇 개의 파를 만들었는지 임시 저장 
    
    // ** 파를 c개만큼 만들었으면 더이상 파를 쓰면 안됨 -> 라면에 넣어야 하므로!!
    for(int i=0; i<s; i++) {
        
        // 현재 mx 길이만큼 파를 자르면 
        while(v[i]>0 && tmp<c) {
            tmp++;
            v[i]-= mx;
        }
        
        ans += v[i];
    }
    
    
    cout<<ans;
    // cout<<'\n';
    // cout<<mx;
    
    return 0;
}