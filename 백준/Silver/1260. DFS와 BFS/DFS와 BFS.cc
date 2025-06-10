#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector<vector<int>> v;
vector<bool> visited1, visited2;

void dfs(int x) {
    cout<<x<<" ";
    
    for(int nxt : v[x]) {
        if(visited1[nxt]) continue;
        
        visited1[nxt] = true;
        dfs(nxt);
    }
}


int main()
{
    int n,m,s; cin>>n>>m>>s;
    v.resize(n+1);
    visited1.resize(n+1);
    visited2.resize(n+1);
    
    while(m--) {
        int x, y; cin>>x>>y;
        
        v[x].push_back(y);
        v[y].push_back(x);
    }
    
    // 정렬해주기
    for(int i=1; i<=n; i++) {
        sort(v[i].begin(), v[i].end());
    }
    
    //dfs
    visited1[s]=true;
    dfs(s);
    
    cout<<'\n';
    
    //bfs
    queue<int> q;
    
    visited2[s] = true;
    q.push(s);
    
    while(!q.empty()) {
        int cur = q.front();
        q.pop();
        
        cout<<cur<<" ";
        
        for(int next : v[cur]) {
            if(visited2[next]) continue;
            
            visited2[next]=true;
            q.push(next);
        }
    }
    
    return 0;
}