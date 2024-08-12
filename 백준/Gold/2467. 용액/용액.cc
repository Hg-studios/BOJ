#include <iostream>
#include <algorithm>
#include <limits.h>
using namespace std;

typedef long long ll;

int n;
ll arr[100001];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr); cout.tie(nullptr);
    
    cin>>n;
    for(int i=0; i<n; i++) cin>>arr[i];
    
    ll ans1 = INT_MAX;
    ll ans2 = INT_MAX;
    
    for(int i=0; i<n; i++) {
        // 특성값이 0에 가장 가까운 것은 arr[idx] 혹은 arr[idx+1] 혹은 arr[idx-1]
        int idx = lower_bound(arr, arr+n, -arr[i]) - arr;
        
        // idx가 가장 작은 경우 
        if(i!=idx && idx<n && abs(arr[idx]+arr[i])<abs(ans1+ans2)) {
            ans1 = arr[i];
            ans2 = arr[idx];
        }
        // idx+1이 가장 작은 경우 
        if(i!=idx+1 && idx+1<n && abs(arr[idx+1]+arr[i])<abs(ans1+ans2)) {
            ans1 = arr[i];
            ans2 = arr[idx+1];
        }
        // idx-1이 가장 작은 경우
        if(i!=idx-1 && idx-1>0 && abs(arr[idx-1]+arr[i])<abs(ans1+ans2)) {
            ans1 = arr[i];
            ans2 = arr[idx-1];
        }
    }
    
    if(ans1<ans2) {
        cout<<ans1<<" "<<ans2;
    }
    else cout<<ans2<<" "<<ans1;
    
    return 0;
}