#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(nullptr); cout.tie(nullptr);
    
    int n; cin>>n;
    vector<vector<int>> adj(n+1);
    
    int m; cin>>m;
    while(m--) {
        int a,b; cin>>a>>b;
        
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    
    int x; cin>>x;
    
    // 배신자와 친구 관계인 사람 표시
    vector<bool> check(n+1, false);
    for(int next : adj[x]) {
        check[next]=true;
    }
    
    int ans = 1; // 최소 1명
    vector<bool> visited(n+1, false);
    // x를 제거한 뒤 탐색 시작
    for(int i=1; i<=n; i++) {
        if(i==x) continue;
        if(visited[i]) continue;
        
        int bet=0; // 배신자와 친구인 사람 세기
        int cnt=0; // 현재 파의 총 명 수
        
        queue<int> q;
        
        if(check[i]) bet++;
        cnt++;
        visited[i]=true;
        q.push(i);
        
        while(!q.empty()) {
            int cur = q.front();
            q.pop();
            
            for(int next : adj[cur]) {
                if(next==x) continue;
                if(visited[next]) continue;
                
                if(check[next]) bet++;
                cnt++;
                visited[next]=true;
                q.push(next);
            }
        }
        
        // 배신자와 친구인 유일한 한 명이 있으므로 함께 모일 수 있음
        if(bet==1) cnt+=1;
        // bet>=2 이면 배신자가 퇴출당함 -> 따라서 현재 구해놓은 cnt 그대로임 
        
        if(ans<cnt) ans = cnt;
    }
    
    cout<<ans;
    
    return 0;
}