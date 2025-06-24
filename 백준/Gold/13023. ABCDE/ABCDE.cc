#include <iostream>
#include <vector>
using namespace std;

bool dfs(int cur, int depth, vector<bool>& visited, vector<vector<int>>& v) {
    if(depth>=4) {
        return true;
    }
    
    for(int next : v[cur]) {
        if(visited[next]) continue;
        
        visited[next]=true;
        if(dfs(next, depth+1, visited, v)) return true;
        visited[next] = false;
    }
    
    return false;
    
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(nullptr); cout.tie(nullptr);
    int n, m; cin>>n>>m;
    
    vector<vector<int>> v(n); // 각각의 친구를 저장함
    for(int i=0; i<m; i++) {
        int x, y; cin>>x>>y;
        
        v[x].push_back(y);
        v[y].push_back(x);
    }
    
    // 각 정점에서 dfs를 이용해서, 깊이가 4가 되는 관계가 있는지 확인하기!
    for(int i=0; i<n; i++) {
        vector<bool> visited(n, false);
        
        visited[i]=true;
        
        if(dfs(i,0, visited, v)) {
            cout<<1;
            
            return 0;
        }
    }
    
    
    cout<<0;
    
    return 0;
}