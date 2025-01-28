#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n; cin>>n;
    
    vector<int> v(n);
    for(int i=0; i<n; i++) cin>>v[i];
    
    int ans = 1;
    int incre=1;
    int decre=1;
    
    for(int i=0; i<n-1; i++) {
        if(v[i]<=v[i+1]) incre++;
        else incre=1;
        
        if(v[i]>=v[i+1]) decre++;
        else decre=1;
        
        int result = max(incre, decre);
        ans = max(ans, result);
    }
    cout<<ans;
    
    return 0;
}