#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr); cout.tie(nullptr);
    
    int n; cin>>n;
    vector<int> v(n);
    for(int i=0; i<n; i++) cin>>v[i];
    
    sort(v.begin(), v.end()); // 정렬 필수 
    
    int start=0, end=v.size()-1;
    vector<int> ans(2);
    int mn = INT_MAX; //현재 가장 0에 가까운 두 수의 합
    while(start<end) {
        int sum = v[start] + v[end];
        
        if(sum==0) {
            cout<<v[start]<<" "<<v[end];
            return 0;
        }
        
        if(abs(sum) < abs(mn)) {
            ans[0] = v[start];
            ans[1] = v[end];
            mn = sum;
        }
        
        // 합이 0보다 크다면 end를 왼쪽으로 한칸씩 옮겨야 함
        if(sum>0) {
            end--;
        }
        // 합이 0보다 작다면 start를 오른쪽으로 한칸씩 옮겨야 함 
        else {
            start++;
        }
    }
    
    for(auto x : ans) cout<<x<<" ";
    
    return 0;
}