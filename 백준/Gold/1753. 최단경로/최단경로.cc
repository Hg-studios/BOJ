/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define X first
#define Y second
#define INF 99999999

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(nullptr); cout.tie(nullptr);
    
    int v,e; cin>>v>>e;
    int s; cin>>s;
    
    vector<vector<pair<int,int>>> adj(v+1);
    while(e--) {
        int u,v,w; cin>>u>>v>>w;
        
        adj[u].push_back({w,v});
    }
    
    // 다익스트라 시작
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq; //** 최소힙으로 만들어야함**
    vector<int> dist(v+1, INF);
    
    dist[s]=0;
    pq.push({0,s});
    
    while(!pq.empty()) {
        auto [d,u] = pq.top(); //d는 현재 거리, u는 현재 인덱스
        pq.pop();
        
        for(auto next : adj[u]) { // 현재 인덱스와 연결이 되어있는 정점을 모두 봄 
            // 현재 cur을 거쳐서 가는 것이 더 빨라진다면 next를 가기 전에 cur을 들렀다가 감
            int w = next.X; // 다음 정점까지의 거리
            int v = next.Y; // 다음 정점 인덱스 
            
            if(dist[v] > d + w) { // 원래 v를 가는 거리보다 현재 u를 지나가는데 더 짧으면 갱신해줌
                dist[v] = d + w;
                pq.push({dist[v], v});
            }
        }
    }
    
    for(int i=1; i<=v; i++) {
        if(dist[i]==INF) cout<<"INF\n";
        else cout<<dist[i]<<'\n';
    }
    
    return 0;
}