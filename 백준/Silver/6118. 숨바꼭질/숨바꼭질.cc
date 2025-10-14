#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    
    int n, m; cin>>n>>m;
    vector<vector<int>> v(n+1);
    
    while(m--) {
        int a,b; cin>>a>>b;
        
        v[a].push_back(b);
        v[b].push_back(a);
    }
    
    // BFS START!
    
    queue<int> q;
    vector<int> dist(n+1, -1);
    
    dist[1]=0;
    q.push(1);
    int mx=0;
    
    while(!q.empty()) {
        auto cur = q.front();
        q.pop();
        
        for(auto next : v[cur]) {
            if(dist[next]!=-1) continue;
            
            dist[next] = dist[cur] + 1;
            q.push(next);
            mx = max(dist[next], mx);
        }
    }
    
    vector<int> tmp;
    for(int i=1; i<=n; i++) {
        if(dist[i]!=mx) continue;
        tmp.push_back(i);
    }
    
    cout<<tmp[0]<<" "<<mx<<" "<<tmp.size()<<'\n';
    
    return 0;
}