#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

int v[102];
bool visited[102];
vector<int> ans;

// start에서 시작한 것이고, 다시 자신에게 돌아가야 함
void dfs(int start, int cur) {
    if(visited[cur]) {
        if(start==cur) {
            ans.push_back(cur);
        }
        return;
    }
    
    visited[cur]=true;
    dfs(start, v[cur]);
}

int main()
{
    int n; cin>>n;
    
    for(int i=1; i<=n; i++) {
        cin>>v[i];
    }
    
    for(int i=1; i<=n; i++) {
        memset(visited, false, sizeof(visited));
        dfs(i,i);
    }
    
    cout<<ans.size()<<'\n';
    for(int x : ans) cout<<x<<'\n';
    
    return 0;
}