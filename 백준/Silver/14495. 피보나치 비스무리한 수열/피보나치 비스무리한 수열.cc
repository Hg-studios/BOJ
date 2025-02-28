#include <iostream>
#include <vector>
using namespace std;

#define ll long long

int main()
{
    int n; cin>>n;
    
    if(n<=3) cout<<1;
    else {
        vector<ll> v(n+1,0);
        v[1]=v[2]=v[3]=1;
    
        for(int i=4; i<=n; i++) {
            v[i] = v[i-1]+v[i-3];
        }
        
        cout<<v[n];
    }
    
    return 0;
}