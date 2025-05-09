#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
using namespace std;
#define ll long long

struct snow {
    int sum;
    int i;
    int j;
};


// bool cmp (const snow& a, const snow& b)  {
//     if(a.sum==b.sum && a.i==b.i) return a.j<b.j;
//     if(a.sum==b.sum) return a.i<b.i;
//     return a.sum<b.sum;
// }

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr); cout.tie(nullptr);
    
    int n; cin>>n;
    
    vector<int> v(n);
    for(int i=0; i<n; i++) cin>>v[i];
    
    // 1. 두 개씩 쌍을 지어 눈사람을 만들 것이므로 일단 두개씩 묶어 합을 구한다.
    // 이때 중요한 것은 더해진 두 인덱스도 함께 저장하는 것이다.
    
    vector<snow> s;
    // vector<pair<int, pair<int,int>>> ss;
    for(int i=0; i<n-1; i++) {
        for(int j=i+1; j<n; j++) {
            s.push_back({v[i]+v[j], i, j});
        }
    }
    
    // 2. snow 배열을 정렬해줌
    sort(s.begin(), s.end(), [] (const snow& a, const snow& b) {
        if(a.sum==b.sum && a.i==b.i) return a.j<b.j;
        if(a.sum==b.sum) return a.i<b.i;
        return a.sum<b.sum;
    }); // 정렬은 람다로 하는 것이 더 간편함
    
    // for(auto x : s) {
    //     cout<<x.sum<<" "<<x.i<<" "<<x.j<<'\n';
    // }
    
    // 3. 정렬된 배열에서 하나를 뽑아서 기준으로 잡고 또 다른 포문에서 하나를 더 뽑고 
    // 4개의 인덱스가 모두 다르다면 가장 가까운 높이 차를 찾았으므로 바로 빠져나옴
    ll mn = INT_MAX;
    for(int i=0; i<s.size()-1; i++) {
        snow s1 = s[i];
        for(int j=i+1; j<s.size(); j++) {
            snow s2 = s[j];
            if(s1.i!=s2.i && s1.j!=s2.j && s1.i!=s2.j && s1.j!=s2.i) {
                // 가장 가까운 높이 차인 두 눈사람을 찾았으므로
                mn = min(mn, (ll)abs(s1.sum-s2.sum));
                break;
            }
        }
    }
    
    cout<<mn;
    
    return 0;
}