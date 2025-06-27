#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#include <limits.h>

using namespace std;

#define MAX 10001

int n,m,maxCnt=INT_MIN;
vector<int> v[MAX];
bool visited[MAX];
vector<int> ans; //ans값보다 큰 경우가 나오면 ans에 있는 값을 다 없애고.. 
                //그렇지 않으면 뒤에 붙이기 

void solve() {
    
    for(int i=1; i<=n; i++) {
        queue<int> q;
        memset(visited, false, sizeof(visited));
        
        int cnt=1;
        visited[i]=true;
        q.push(i);
        
        while(!q.empty()) {
            int cur = q.front();
            q.pop();
            
            for(int next : v[cur]) {
                if(visited[next]) continue;
                
                cnt++;
                visited[next]=true;
                q.push(next);
            }
        }
        
        if(maxCnt<cnt) {
            maxCnt = cnt;
            ans = vector<int>();
            ans.push_back(i);
        }
        else if(maxCnt==cnt) ans.push_back(i);
        
    }
}

int main() {
    ios_base::sync_with_stdio;
    cin.tie(nullptr); cout.tie(nullptr);
    
    cin>>n>>m;
    
    for(int i=0; i<m; i++) {
        int x,y; cin>>x>>y;
        
        v[y].push_back(x);
    }
    
    solve();
    
    for(auto x : ans) {
        cout<<x<<" ";
    }
}