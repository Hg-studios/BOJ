#include <iostream>
#include <vector>
using namespace std;
#define ll long long

int main()
{
    int n; cin>>n;
    
    vector<ll> v(n+1);
    v[0]=1;
    
    for(int k=1; k<=n; k++) {
        for(int i=0; i<=k-1; i++) {
            v[k]+=v[i]*v[k-1-i];
        }
    }
    cout<<v[n];
    
    return 0;
}