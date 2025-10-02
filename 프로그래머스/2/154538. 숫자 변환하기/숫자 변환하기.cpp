#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(int x, int y, int n) {
    // BFS
    vector<int> dist(y+1, -1);
    queue<int> q;
    
    dist[x]=0;
    q.push(x);
    
    while(!q.empty()) {
        auto cur = q.front();
        q.pop();
        
        if(cur==y) return dist[cur];
        
        int next=0;
        for(int i=0; i<3; i++) {
            if(i==0) next = cur+n;
            else if(i==1) next = cur*2;
            else next = cur*3;
            
            if(next>y) continue;
            if(dist[next]!=-1) continue;
            
            dist[next] = dist[cur]+1;
            q.push(next);
        }
    }
    
    return -1;
}