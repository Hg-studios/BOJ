#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define MAX 100001

int n;
int ans[MAX];
bool visited[MAX];
vector<int> graph[MAX];

void input() {
    cin>>n;
    
    for(int i=2; i<=n; i++) {
        int x, y;
        cin>>x>>y;
        
        graph[x].push_back(y);
        graph[y].push_back(x);
        
    }
}

void solve() {
    queue<int> q;
    
    visited[1] = true;
    q.push(1);
    
    while(!q.empty()) {
        int cur = q.front();
        q.pop();
        
        for(int next : graph[cur]) {
            if(visited[next]) continue;
            
            ans[next] = cur;
            
            visited[next]=1;
            q.push(next);
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    input();
    solve();
    
    for(int i=2; i<=n; i++) {
        cout<<ans[i]<<'\n';
    }
    return 0;
}

