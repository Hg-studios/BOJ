#include <iostream>
#include <queue>
using namespace std;

int gcd(int x, int y) {
    if(y==0) return x;
    
    return gcd(y, x%y);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    
    int x,y; cin>>x>>y;
    
    int g = gcd(x,y);
    
    cout<<((x/g-1) + (y/g-1) +1)*g ;
    
    return 0;
}