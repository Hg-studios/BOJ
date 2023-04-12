#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;

int n;
ll d[1500002];
ll t[1500002];
ll p[1500002];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>n;
    for(int i=1; i<=n; i++){
        cin>>t[i]>>p[i];
    }

    for(int i=n; i>=1; i--){
        if(i+t[i]-1<=n){
            d[i] = max(d[i+t[i]]+p[i], d[i+1]);
        }
        else{
            d[i] = d[i+1];
        }
    }

    cout<<*max_element(d+1, d+1+n);
}