#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n,m; cin>>n>>m;
    
    vector<int> v(n);
    for(int i=0; i<n; i++) cin>>v[i];
    
    int en=0, sum=v[0], ans=0;
    
    for(int st=0; st<n; st++) {
        // 현재 st와 en까지의 범위의 합이 m보다 작다면 
        // en을 계속 증가시켜줌
        while(sum<m && en<n) {
            en++;
            sum+=v[en];
        }
        
        if(sum==m) ans++;
        
        sum-=v[st];
    }
    
    cout<<ans;
    
    return 0;
}