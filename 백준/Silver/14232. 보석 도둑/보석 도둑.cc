#include <iostream>
#include <vector>
using namespace std;

#define ll long long 

ll cnt=0;
vector<ll> ans;

int main()
{
    ll k; cin>>k;
    
    for(ll i=2; i*i<=k; i++) {
        // 해당 인수로 나눌 수 있을 때까지
        while(k%i==0) {
            ans.push_back(i);
            k/=i;
        }
    }
    
    // 마지막 남은 소수
    if(k>1) ans.push_back(k);
    
    cout<<ans.size()<<'\n';
    for(auto c : ans) cout<<c<<" ";
    
    return 0;
}