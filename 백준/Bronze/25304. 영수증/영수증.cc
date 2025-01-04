#include <iostream>
using namespace std;

int main()
{
    int x,n;
    cin>>x>>n;
    
    int tmp=0;
    for(int i=0; i<n; i++) {
        int a, b; cin>>a>>b;
        
        tmp+=a*b;
    }
    
    cout<<(tmp==x?"Yes":"No");
    
    return 0;
}