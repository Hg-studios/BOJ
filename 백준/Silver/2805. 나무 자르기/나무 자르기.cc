#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

ll n, m;
vector<ll> v;

bool solve(ll x) {
    // 절단기 높이가 x 일 때 m 이상의 길이가 나오는지 확인
    ll sum=0;
    for(int i=0; i<n; i++) {
        if(v[i]-x>0) sum += (v[i]-x);
    }
    return sum >= m;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr); cout.tie(nullptr);
    
    cin>>n>>m;
    for(int i=0; i<n; i++) {
        int x; cin>>x;
        v.push_back(x);
    }
    
    // 이분탐색으로 파라매트릭 서치
    ll st = 0;
    ll en = *max_element(v.begin(), v.end());
    
    while(st<en) {
        ll mid = (st+en+1)/2;
        
        if(solve(mid)) st = mid;
        else en = mid-1;
    }
    
    cout<<st;
    
    return 0;
}