#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n; cin>>n;
    
    vector<int> v(n,0);
    for(int i=0; i<n; i++) cin>>v[i];
    
    // 순열 만들어야 함
    vector<int> order(n);
    for(int i=0; i<n; i++) order[i]=i+1;
    
    do {
        // for(auto x : order) cout<<x<<" ";
        // cout<<'\n';
        
        // 해당 순서에서 왼쪽에 나보다 큰 숫자가 몇 개있는지 확인
        vector<int> cnt(n+1,0);
        
        for(int i=0; i<n; i++) {
            for(int j=0; j<i; j++) {
                if(order[j]>order[i]) cnt[order[i]]++;
            }
        }
        
        // cnt가 답이랑 같은지 확인
        bool flag = true;
        for(int i=0; i<n; i++) {
            if(v[i]!=cnt[i+1]) {
                flag = false;
                break;
            }
        }
        
        // for(auto x : cnt) cout<<x<<" ";
        // cout<<'\n';
        // for(auto x : order) cout<<x<<" ";
        // cout<<'\n';
        
        if(flag) {
            for(auto x : order) cout<<x<<" ";
            break;
        }
        
        // cout<<'\n';
        // cout<<'\n';
    } while(next_permutation(order.begin(), order.end()));
    
    return 0;
}