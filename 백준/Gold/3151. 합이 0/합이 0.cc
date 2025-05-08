#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define ll long long
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr); cout.tie(nullptr);
    
    int n;  cin>>n;
    
    // 원래는 n^3이지만 두 개의 합(sum)을 구해서 
    // -sum이 있는지 확인해보면 n^2logn 이므로 4초 안에 가능함
    
    vector<int> v(n);
    for(int i=0; i<n; i++) cin>>v[i];
    
    sort(v.begin(), v.end());
    
    ll ans=0;
    for(int i=0; i<n-1; i++) {
        for(int j=i+1; j<n; j++) {
            int sum = v[i] + v[j];
            
            // cout<<v[i]<<" "<<v[j]<<" "<<-sum<<'\n';
            ans += (upper_bound(v.begin()+j+1, v.end(), -sum) - lower_bound(v.begin()+j+1, v.end(), -sum));
        }
    }
    
    cout<<ans;
    
    return 0;
}