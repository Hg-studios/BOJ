#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n; cin>>n;
    
    vector<int> v(n+1,-1);
    
    int cnt=0;
    for(int i=0; i<n; i++) {
        int x, dir; 
        cin>>x>>dir;
        
        
        if(v[x]==-1) {
            v[x] = dir;
        }
        else{
            if(v[x]!=dir) {
                cnt++;
                v[x] = dir;
            }
        }
    }
    
    cout<<cnt;
    
    return 0;
}