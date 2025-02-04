#include <iostream>
using namespace std;

int main()
{
    int n; cin>>n;
    
    int q = n/5;
    int ans=0;
    for(int i=q; i>=0; i--) {
        int r = n - i*5;
        
        if(r%3==0) {
            ans = i + r/3;
            cout<<ans<<" ";
            return 0;
        }
        
        ans -= 5;
    }
    
    cout<<"-1";
    return 0;
}