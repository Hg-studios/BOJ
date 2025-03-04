#include <iostream>
#include <algorithm>
#include <limits.h>
#include <vector>
#include <queue>

#define X first
#define Y second

using namespace std;

int main()
{
    int v,e; cin>>v>>e;
    int start; cin>>start;
    
    vector<int> d(v+1,INT_MAX);
    
    vector<vector<pair<int,int>>> adj(v+1); // {거리, 정점번호}
    for(int i=1; i<=e; i++) {
        int u,v,w; cin>>u>>v>>w;
        
        adj[u].push_back({w,v});
    }
    
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    
    d[start]=0;
    pq.push({d[start], start});
    
    while(!pq.empty()) {
        auto cur = pq.top(); 
        pq.pop();
        
        if(d[cur.Y] != cur.X) continue;
        for(auto next : adj[cur.Y]) {
            // cur과 연결되어있는 정점 중 나를 거쳐서 가는 것이 더 짧아지게 되는지 확인 
            // 현재 next까지의 거리 : d[next.Y]
            // cur을 거쳐서 가게 될 때 = cur까지의 거리 + cur에서 next까지의 거리
            if(d[next.Y] <= d[cur.Y] + next.X) continue;
            d[next.Y] = d[cur.Y] + next.X;
            pq.push({d[next.Y], next.Y});
        }
    }
    
    for(int i=1; i<=v; i++) {
        if(d[i]==INT_MAX) cout<<"INF"<<'\n';
        else cout<<d[i]<<'\n';
    }
    
    return 0;
}