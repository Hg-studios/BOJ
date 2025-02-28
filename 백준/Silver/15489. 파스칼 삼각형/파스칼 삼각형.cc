#include <iostream>
#include <vector>
using namespace std;

#define ll long long

int main()
{
    vector<vector<ll>> v(32, vector<ll>(32,0));
    // for(int i=1; i<=31; i++) {
    //     for(int j=1; j<=31; j++) {
    //         cout<<v[i][j]<<" ";
            
    //     }
    //     cout<<'\n';
    // }
    
    for(int i=1; i<=31; i++) {
        v[i][1]=1;
        v[i][i]=1;
    }
    
    for(int i=3; i<=31; i++) {
        for(int j=2; j<=i-1; j++) {
            v[i][j] = v[i-1][j-1] + v[i-1][j];
        }
    }
    
    // for(int i=1; i<=31; i++) {
    //     for(int j=1; j<=31; j++) {
    //         cout<<v[i][j]<<" ";
            
    //     }
    //     cout<<'\n';
    // }
    
    int r,c,w; cin>>r>>c>>w;
    
    ll ans=0;
    int width=0;
    for(int i=r; i<r+w; i++) {
        width++;
        for(int j=c; j<c+width; j++) {
            ans+=v[i][j];
        }
    }
    
    cout<<ans;
    
    return 0;
}