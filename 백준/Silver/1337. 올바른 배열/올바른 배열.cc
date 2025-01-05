#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <limits.h>
using namespace std;

int main()
{
    int n; cin>>n;
    map<int,int> m;
    vector<int> v(n);
    
    for(int i=0; i<n; i++) {
        int x; cin>>x;
        v[i]=x;
        m[x]=x;
    }
    
    sort(v.begin(), v.end());
    
    int ans=INT_MAX;
    // 각 요소를 봄
    // 이 요소를 기준으로 삼으면 연속된 5개가 정해지게 됨 
    // 그 요소들이 map 안에 있는지만 확인해주면 됨
    for(int i=0; i<n; i++) { 
        int cnt = 0;
        
        for(int j=1; j<=4; j++) { // 나보다 i만큼 큰 수가 있는지 확인
            if(m[v[i]+j]==0) cnt++; 
        }
        
        if(cnt<ans) ans=cnt;
    }
    
    cout<<ans;
    
    return 0;
}