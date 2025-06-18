#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define ll long long 

int dx[] = {-1,1,0,0}; // 상 하 좌 우 
int dy[] = {0,0,-1,1};

struct alarm {
    ll t, k;
};

ll gcd(ll d1, ll d2) {
    if(d2==0) return d1;
    
    return gcd(d2, d1%d2);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(nullptr); cout.tie(nullptr);
    
    ll n, d; cin>>n>>d;
    
    vector<alarm> alarms(n);
    for(int i=0; i<n; i++) {
        cin>>alarms[i].t>>alarms[i].k;
    }
    
    // 2개 뽑기
    ll ans1 = -1;
    ll ans2=-1, ans3=-1;
    
    for(int i=0; i<n-1; i++) {
        for(int j=i+1; j<n; j++) {
            alarm alarm1 = alarms[i];
            alarm alarm2 = alarms[j];
            
            ll cnt1 = d/alarm1.k;
            cnt1 -= (alarm1.t/alarm1.k - 1);
            // 시작 6 간격 3
            // 시작 0 간격 3
            // cout<<cnt1;
            
            ll cnt2 = d/alarm2.k;
            cnt2 -= (alarm2.t/alarm2.k - 1);
            
            // 최소공배수 구하기
            ll lcm = (alarm1.k * alarm2.k) / gcd(alarm1.k, alarm2.k);
            // 2 3 -> 6
            ll cnt3 = d/lcm;
            // 30/6 = 5번 -> 0 이 포함x
            
            ll cnt = cnt1+cnt2-cnt3;
            
            // 둘 다 0초부터 시작하면 1번 빼줘야함
            // 0 2 4 6 8 ...
            // 0 3 6 9 12 ...
            // 6부터 시작해서 30까지 5개를 뺌
            // if(alarm1.t==0 && alarm2.t==0) cnt-=1;
            
            // 둘의 최소공배수보다 시작점이 늦어지는 경우
            ll mx = max(alarm1.t, alarm2.t);
            // 6
            
            cnt += (mx/lcm);
            if(mx%lcm==0) cnt-=1;
            
            // 24 6
            
            // 6/6 = 1
            
            // cout<<i+1<<" "<<j+1<<'\n';
            // cout<<cnt1<<" "<<cnt2<<" "<<cnt3<<'\n';
            // cout<<cnt<<'\n';
            // cout<<'\n';
            
            if(ans1<cnt) {
                ans1 = cnt;
                ans2 = i+1;
                ans3 = j+1;
            }
        }
    }
    
    cout<<ans2<<" "<<ans3<<'\n'<<ans1;
    
    return 0;
}