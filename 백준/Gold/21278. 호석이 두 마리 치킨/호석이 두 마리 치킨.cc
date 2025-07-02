#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(nullptr); cout.tie(nullptr);
    
    int n, m; cin>>n>>m;
    
    vector<vector<int>> v(n+1);
    for(int i=0; i<m; i++) {
        int x, y; cin>>x>>y;
        
        v[x].push_back(y);
        v[y].push_back(x);
    }
    
    // 치킨집 2개 뽑기
    int mn = INT_MAX; // 모든 건물에서 가장 가까운 치킨집까지 왕복하는 최단 시간의 총합
    int n1,n2; // 최단 시간일 때의 건물 2개 번호 
    for(int i=1; i<=n-1; i++) {
        for(int j=i+1; j<=n; j++) {
            // cout<<i<<" "<<j<<'\n';
            
            // 각 치킨집에서 BFS 돌리기 
            
            // 치킨집 i에서 BFS 돌리기 
            vector<bool> visited1(n+1, false);
            vector<int> dist1(n+1, -1); // 거리배열이자 방문배열 
            queue<int> q1;
            
            dist1[i]=0;
            q1.push(i);
            
            while(!q1.empty()) {
                auto cur = q1.front();
                q1.pop();
                
                for(int next : v[cur]) {
                    if(dist1[next]!=-1) continue; // 이미 방문했다면 탐색 종료
                    
                    dist1[next] = dist1[cur]+1;
                    q1.push(next);
                }
            }
            
            
            // 치킨집 j에서 BFS 돌리기
            vector<bool> visited2(n+1, false);
            vector<int> dist2(n+1, -1); // 거리배열이자 방문배열 
            queue<int> q2;
            
            dist2[j]=0;
            q2.push(j);
            
            while(!q2.empty()) {
                auto cur = q2.front();
                q2.pop();
                
                for(int next : v[cur]) {
                    if(dist2[next]!=-1) continue; // 이미 방문했다면 탐색 종료
                    
                    dist2[next] = dist2[cur]+1;
                    q2.push(next);
                }
            }
            // for(int x : dist1) cout<<x<<" "; cout<<'\n';
            // for(int x : dist2) cout<<x<<" "; cout<<'\n';
            
            // 각 건물에서 어떤 치킨집이 더 가까운지 구함
            int tmp = 0;
            for(int i=1; i<=n; i++) {
                tmp += min(dist1[i], dist2[i])*2;
            }
            // cout<<tmp<<" ";
            
            if(tmp<mn) {
                mn = tmp;
                n1 = i;
                n2 = j;
            }
            
            // return 0;
            
        } 
    }
    // cout<<'\n';
    cout<<n1<<" "<<n2<<" "<<mn;
    
    
    return 0;
}