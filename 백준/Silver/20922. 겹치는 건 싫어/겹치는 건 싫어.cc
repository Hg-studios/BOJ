#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr); cout.tie(nullptr);
    
    int n,k; cin>>n>>k;
    
    vector<int> v(n);
    for(int i=0; i<n; i++) cin>>v[i];
    
    unordered_map<int, int> cnt;
    // end가 요소를 추가하는 느낌
    // start가 요소를 빼는 느낌임 
    int start=0, mx=-1;
    for(int end=0; end<n; end++) {
        cnt[v[end]]++;
        
        // 조건 위반 시 start 이동 
        while(cnt[v[end]] > k) {
            cnt[v[start]]--;
            start++;
        }
        // 최대 길이 갱신
        mx = max(mx, end-start+1);
    }
    
    cout<<mx;
    
    return 0;
}