#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector<vector<int>> v;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(nullptr); cout.tie(nullptr);
    
    int n; cin>>n;
    
    vector<vector<int>> v(n+1);
    
    for(int i=0; i<n-1; i++) {
        int x, y; cin>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    
    queue<int> q;
    vector<bool> visited(n+1);
    
    visited[1]=true;
    q.push(1);
    
    vector<int> parent(n+1);
    
    while(!q.empty()) {
        int cur = q.front();
        q.pop();
        
        for(int next : v[cur]) {
            if(visited[next]) continue;
            
            parent[next] = cur;
            visited[next] = true;
            q.push(next);
        }
    }
    
    for(int i=2; i<=n; i++) {
        cout<<parent[i]<<'\n';
    }
    
    return 0;
}