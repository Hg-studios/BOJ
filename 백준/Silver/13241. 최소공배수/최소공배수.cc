#include <iostream>
using namespace std;
#define ll long long

ll gcd (ll a, ll b) {
    if(a%b==0) return b;
    return gcd(b, a%b);
}

int main()
{
    ll a, b; cin>>a>>b;
    
    int g=0;
    if(a>=b) g = gcd(a,b);
    else g = gcd(b,a);
    
    cout<<a*b/g;

    return 0;
}