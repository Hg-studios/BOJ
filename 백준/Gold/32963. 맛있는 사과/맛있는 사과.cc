#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    
    int n,q; cin>>n>>q;
    
    vector<pair<int,int>> v(n);
    vector<int> t(n); // 맛
    vector<int> s(n); // 크기
    
    for(int i=0; i<n; i++) cin>>t[i];
    for(int i=0; i<n; i++) cin>>s[i];
    for(int i=0; i<n; i++) v[i] = {t[i], s[i]};
    
    sort(v.begin(), v.end()); // 오름차순
    
    // 정렬된 순서로 다시 담기
    for(int i=0; i<n; i++) {
        t[i] = v[i].first;
        s[i] = v[i].second;
    }
    
    // 뒤에서 앞으로 보면서, 최대로 큰 값이 몇 개인지 한번에 저장해두기
    vector<int> best(n+1, INT_MIN);
    vector<int> cnt(n+1, 0);
    
    for(int i=n-1; i>=0; i--) {
        // 현재 내 값이 가장 큰 값일 때
        if(s[i] > best[i+1]) {
            best[i] = s[i];
            cnt[i] = 1;
        }
        // 현재 내 값이 다음 큰 값과 같을 때
        else if(s[i] == best[i+1]) {
            best[i] = s[i];
            cnt[i]  = cnt[i+1]+1;
        }
        //  현재 내 값이 작은 값일 때
        else {
            best[i] = best[i+1];
            cnt[i] = cnt[i+1];
        }
    }
    
    // q번 돌면서 O(1)에 구하기
    while(q--) {
        int p; cin>>p;
        
        auto idx = lower_bound(t.begin(), t.end(), p);
        int start = idx-t.begin(); // 시작해야되는 지점
        
        if(start==n) cout<<0<<'\n';
        else cout<<cnt[start]<<'\n';
    }
    
    
    
    return 0;
}