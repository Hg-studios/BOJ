#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define ll long long

int main()
{
    ll x,y,k; cin>>x>>y>>k;
    
    ll a = min(x,y);
    ll b = max(x,y);
    
    ll sum = a+b;
    
    vector<ll> v;
    for(ll i=1; i*i<=sum; i++) {
        if(sum%i==0) {
            v.push_back(i);
            v.push_back(sum/i);
        }
    }
    sort(v.begin(), v.end(), greater<ll>());
    
    // a의 범위 구하기
    ll mina = a - k;
    if(mina<0) mina = 0;
    ll maxa = a + k;
    if(maxa>sum) maxa = sum;
    // cout<<mina<<" "<<maxa<<'\n';
    bool flag = false;
    for(auto x : v) {
        if(min(a%x, x-a%x)<=k) {
            flag=true;
            cout<<x;
        }
        if(flag) break;
    }
    
    return 0;
}