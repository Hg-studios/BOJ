#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int n;
int d[100005];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>n;

    for(int i=1; i<=n; i++){
        d[i]=0x7fffffff; //아주 큰수로 초기화
        for(int j=1; j*j<=i; j++){
            d[i] = min(d[i], d[i-j*j]+1);
        }
    }
    
    cout<<d[n];
}