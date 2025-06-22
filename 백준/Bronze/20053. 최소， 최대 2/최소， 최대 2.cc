#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(nullptr); cout.tie(nullptr);
    
    int t; cin>>t;
    
    while(t--) {
        int n; cin>>n;
        // cout<<n<<" ";
        
        vector<int> v(n);
        for(int i=0; i<n; i++) cin>>v[i];
        
        sort(v.begin(), v.end());
        
        // for(int x : v) cout<<x<<" ";
        
        cout<<v[0]<<" "<<v[v.size()-1]<<'\n';
    }
    
    return 0;
}