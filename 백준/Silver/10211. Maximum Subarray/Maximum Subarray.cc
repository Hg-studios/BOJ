#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int t; cin>>t;
    
    while(t--) {
        int n; cin>>n;
        
        vector<int> v(n,0);
        for(int i=0; i<n; i++) {
            cin>>v[i];
        }
        
        vector<int> dp(n,0);
        for(int i=0; i<n; i++) {
            // dp[i]는 
            dp[i] = max(dp[i-1]+v[i], v[i]);
        }
        // for(int x : dp) cout<<x<<" ";
        // cout<<'\n';
        // cout<<max<<'\n';
        cout<<*max_element(dp.begin(), dp.end())<<'\n';
    }
    
    return 0;
}