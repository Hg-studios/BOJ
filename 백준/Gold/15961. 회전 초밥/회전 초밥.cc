#include <iostream>
#include <vector>
#include <limits.h>
#include <map>
using namespace std;
#define ll long long

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr); cout.tie(nullptr);
    
    int n, d, k, c;  cin>>n>>d>>k>>c;

    vector<int> v(n);
    for(int i=0; i<n; i++) cin>>v[i];
    
    map<int, int> m; //초밥 종류, 개수
    
    int kind=0;
    
    // 초밥 k-1개를 넣어둠
    for(int i=0; i<k-1; i++) {
        if(m[v[i]]==0) kind++;
        m[v[i]]++;
    }
    
    //쿠폰도 넣기
    if(m[c]==0) kind++;
    m[c]++;
    
    int mx = -1;
    // k번째부터 최대값을 구해주기
    // i가 k까지인줄 알았으나 초밥판은 순환하기 때문에 총 n번을 돌아야 함
    for(int i=k-1; i<=n+k-2; i++) {
        // i를 포함해서 총 k개가 포함된 상태
        int tmp = i%n;
        if(m[v[tmp]]==0) kind++;
        m[v[tmp]]++;
        
        // cout<<kind<<'\n';
        // for(auto x : m) {
        //     cout<<x.first<<" "<<x.second<<'\n';
        // }
        // cout<<'\n';
        if(kind>mx) mx = kind;
        
        tmp = (i-k+1)%n;
        m[v[tmp]]--;
        if(m[v[tmp]]==0) kind--;
    }
    
    cout<<mx;

    return 0;
}