#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n; cin>>n;
    vector<int> v(n);
    for(int i=0; i<n; i++) cin>>v[i];
    
    sort(v.begin(), v.end(), greater<int>());
    
    int ans=0;
    for(int i=0; i<=(v.size()-1)/3; i++) {
        ans += v[i*3];
        if(i*3+1<=v.size()-1) ans += v[i*3+1];
    }
    
    cout<<ans;
    
    return 0;
}