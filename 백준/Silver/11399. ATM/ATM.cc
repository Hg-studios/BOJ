#include <iostream>
#include <algorithm>
using namespace std;

int n;
int a[1002];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>n;
    for(int i=1; i<=n; i++) cin>>a[i];

    sort(a+1,a+n+1);
    int sum=0;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=i; j++){
            sum +=a[j];
        }
    }

    cout<<sum;
}