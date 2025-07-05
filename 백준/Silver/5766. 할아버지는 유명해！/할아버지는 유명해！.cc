#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

bool cmp(pair<int,int>& a, pair<int,int>& b) {
    if(a.first == b.first) return a.second < b.second;
    return a.first>b.first;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(nullptr); cout.tie(nullptr);
    
    vector<pair<int,int>> v;
    while(1) {
        int n,m; cin>>n>>m;
        
        if(n==0 && m==0) break;
        
        // 매주 갱신이 되네요 ..?
        // 왜 랭킹에 이름이 오를 때마다 1포인트씩 오른다고 한거지 .. 마치 누적인거처럼 ?!
        map<int, int> mp;
        
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                int x; cin>>x;
                mp[x]++;
            }
        }
        
        // for(auto x : mp) cout<<x.first<<" ";
        // cout<<'\n';
        // for(auto x : mp) cout<<x.second<<" ";
        // cout<<'\n';
        
        // sort(v.begin()+1, v.end(), greater<int>());
        
        vector<pair<int,int>> v;
        for(auto x : mp) {
            v.push_back({x.second, x.first});
        }
        
        sort(v.begin(), v.end(), cmp);
        // for(auto x : v) {
        //     cout<<x.first<<" "<<x.second<<'\n';
            
        // }
        // cout<<'\n';
        
        int mx = -1;
        int next_mx=-1;
        for(auto x : v) {
            if(mx<x.first) {
                mx = x.first;
            }
            else if(next_mx<x.first) {
                next_mx = x.first;
                break;
            }
        }
        
        // cout<<"next"<<next_mx<<'\n';
        
        for(auto x : v) {
            if(x.first == mx) continue;
            if(x.first == next_mx) cout<<x.second<<" ";
            else break;
        }
        cout<<'\n';
    }
    
    
    
    return 0;
}