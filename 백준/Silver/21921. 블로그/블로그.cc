#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define ll long long

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr); cout.tie(nullptr);
    
    int n,x; cin>>n>>x;
    vector<int> v(n);
    for(int i=0; i<n; i++) cin>>v[i];
    
    // x일동안의 누적을 보면 됨
    int sum=0;
    for(int i=0; i<x; i++) sum+=v[i];
    
    int left=0, right=x-1;
    int ans = sum; // 일단 가장 큰 값은 sum으로 
    int count=1; // 최대 방문자 수 1로 초기화
    while(1) {
        if(right>=n) break;
        
        sum-=v[left++];
        sum+=v[++right];
        
        if(sum>ans) {
            ans = sum;
            count=1;
        }
        else if(sum==ans) count++;
    }
    
    if(ans==0) cout<<"SAD";
    else cout<<ans<<'\n'<<count;
    
    return 0;
}