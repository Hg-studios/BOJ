#include <iostream>
#include <vector>
#include <queue>
using namespace std;

bool flag = false;

// start에서 시작한 것이고, 다시 자신에게 돌아가야 함
void dfs(int start, int cur, vector<int>& tmp, vector<int>& v) {
    // start=1, cur=3, tmp에 
    if(start==cur) {
        flag = true;
        return;
    }
    
    tmp.push_back(cur);
    dfs(start, v[cur], tmp, v);
}

int main()
{
    int n; cin>>n;
    // cout<<n;
    vector<int> v(n+1, 0);
    for(int i=1; i<=n; i++) {
        cin>>v[i];
        // cout<<i<<" "<<v[i]<<'\n';
    }
    
    // queue를 이용해서 사이클 확인
    queue<int> q;
    
    vector<bool> check(n+1, false); // 이미 뽑힌 수인지 아닌지 확인
    
    for(int i=1; i<=n; i++) {
        if(check[i]) continue;
        // cout<<"==================\n";
        // cout<<"i : "<<i<<'\n';
        
        queue<int> q;
        vector<bool> visited(n+1,false); //현재 사이클에서 방문했는가
        
        // cout<<"next : "<<v[i]<<'\n';
        visited[v[i]]=true;
        q.push(v[i]);
        
        while(!q.empty()) {
            int cur = q.front();
            q.pop();
            // cout<<"cur: " <<cur<<'\n';
            
            if(cur==i) {
                // 사이클이 발생한 경우 
                // cout<<"find!"<<'\n';
                for(int i=1; i<=n; i++) {
                    // ans++;
                    if(visited[i]) check[i]=true;
                }
            }
            
            int next = v[cur];
            
            if(visited[next]) continue;
            
            visited[next] = true;
            q.push(next);
        }
    }
    int ans=0;
    for(int i=1; i<=n; i++) {
        if(check[i]) ans++;
    }
    cout<<ans<<'\n';
    for(int i=1; i<=n; i++) {
        if(check[i]) cout<<i<<'\n';
    }
    
    // for(int i=1; i<=n; i++) {
    //     if(check[i]) continue;
    //     cout<<i<<'\n';
    //     vector<int> tmp;
    //     flag = false;
    //     tmp.push_back(i);
    //     // dfs(i, v[i], tmp, v);
        
    //     // if(flag) {
    //     //     for(int x : tmp) cout<<x<<" ";
    //     // }
    //     // cout<<'\n';
    // }
    
    return 0;
}