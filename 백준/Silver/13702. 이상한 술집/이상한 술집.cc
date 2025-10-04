#include <iostream>
#include <vector>
#include <cstring>
#include <limits.h>
#include <algorithm>
using namespace std;

#define ll long long 

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    
    int n, k; cin>>n>>k;
    
    vector<int> v(n);
    int mx = INT_MIN;
    for(int i=0; i<n; i++) {
        cin>>v[i];
        mx = max(mx, v[i]);
    }
    
    ll l=1, r=mx;
    ll ans = 0;
    while(l<=r) {
        ll mid = (l+r)/2;
        
        // mid 용량만큼 나눠주면 몇 명한테 나눠줄 수 있는지 확인
        
        ll tmp=0;
        for(auto x : v) tmp += x/mid;
        
        if(tmp<k) { // k명한테 나눠줄 수 없을 정도로 큰 숫자인 경우
            r = mid-1;
        }
        else { // k명한테 충분히 나눠줄 수 있을 정도로 작은 숫자라면, 최대한 큰 숫자가 되도록 해야됨
            ans = max(ans, mid);
            l = mid+1;
        }
    }
    
    // if(ans==0) cout<<
    cout<<ans;
    
    
    
    return 0;
}