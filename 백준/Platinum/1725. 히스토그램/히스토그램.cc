#include <iostream>
#include <vector>
#include <cstring>
#include <limits.h>
#include <stack>
using namespace std;

int main()
{
    int n; cin>>n;
    
    vector<int> v(n+2,0);
    for(int i=1; i<=n; i++) cin>>v[i];
    
    stack<int> s;
    vector<int> len(n,0);
    int ans=0;
    
    s.push(0);
    // 단조 스택을 이용해서 현재 높이가 길이 몇만큼 이어지는지 확인
    for(int i=1; i<=n+1; i++) {
        while(!s.empty() && v[s.top()]>v[i]) { // 스택에는 값이 커지도록만 들어와야 하는데, 더 작은 값이 온 경우임
            int idx = s.top();
            s.pop();
            ans = max(ans, v[idx] * (i-s.top()-1));
            // len[s.top()] = i-s.top();
            // s.pop();
        }
        
        s.push(i); // 현재 인덱스 넣음
    }
    
    // 남아있는 것들 처리
    // while(!s.empty()) {
    //     len[s.top()] = n-s.top();
    //     s.pop();
    // }
    
    // for(auto cur : len) cout<<cur<<" ";
    
    // int ans = -1;
    
    // for(int i=0; i<n; i++) {
    //     ans = max(ans, len[i]*v[i]);
    // }
    
    cout<<ans;
    
    
    return 0;
}