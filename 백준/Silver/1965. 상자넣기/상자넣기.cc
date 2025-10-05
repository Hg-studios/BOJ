#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    
    int n; cin>>n;
    vector<int> v(n);
    
    for(int i=0; i<n; i++) cin>>v[i];
    
    vector<int> dp(n,0); // dp[a]=b : a까지의 최대 상자 개수 b
    
    for(int i=0; i<n; i++) {
        for(int j=i+1; j<n; j++) {
            if(v[i]<v[j]) {
                dp[j] = max(dp[j], dp[i]+1);
            }
        }
    }
    
    cout<<*max_element(dp.begin(), dp.end())+1;
    
    return 0;
}