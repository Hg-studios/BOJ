#include <iostream>
#include <algorithm>
using namespace std;

int a[102];
int c[102];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin>>n>>m;
    for(int i=0; i<n; i++) cin>>a[i];
    sort(a,a+n);

    int ans=0;
    for(int i=0; i<n-2; i++){
        for(int j=i+1; j<n-1; j++){
            for(int k=j+1; k<n; k++){
                //cout<<i<<j<<k;
                int sum = a[i]+a[j]+a[k];
                if(sum>m) continue; //m을 넘으면 안됨
                ans = max(ans, sum);
            }
        }
    }

    cout<<ans;
}