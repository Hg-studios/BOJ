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
    
    int n,k,b; cin>>n>>k>>b;
    
    vector<bool> v(n+1,false); // 고장났는지 체크
    for(int i=0; i<b; i++) {
        int x; cin>>x;
        v[x]=true;
    }
    
    int cnt=0;
    // k개를 모두 봄
    for(int i=1; i<=k; i++) {
        if(v[i]) cnt++;
    }
    
    int ans = cnt;
    for(int i=k+1; i<=n; i++) {
        // i번째 값은 넣고
        if(v[i]) cnt++;
        
        // i-k번째 값은 빼고
        if(v[i-k]) cnt--;
        
        if(cnt<ans) ans = cnt;
    }
    
    cout<<ans;
    
    
    return 0;
}