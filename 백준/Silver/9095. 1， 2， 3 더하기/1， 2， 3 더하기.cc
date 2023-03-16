#include <iostream>
using namespace std;

int d[20];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int tc, n;
    cin>>tc;

    d[1]=1, d[2]=2, d[3]=4;

    while(tc--){
        cin>>n;

        for(int i=4; i<=n; i++){
            if(!d[i]) d[i] = d[i-1]+d[i-2]+d[i-3];
        }

        cout<<d[n]<<'\n';
    }
}