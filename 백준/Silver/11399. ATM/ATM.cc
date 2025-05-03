#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n; cin>>n;
    vector<int> v(n);
    for(int i=0; i<n; i++) cin>>v[i];
    
    sort(v.begin(), v.end());
    
    int ans=0;
    int delay=0;
    for(int i=0; i<v.size(); i++) {
        ans+=delay;
        delay+=v[i];
        
        // cout<<ans<<" "<<delay<<'\n';
    }
    
    cout<<ans+delay;
    
    return 0;
}