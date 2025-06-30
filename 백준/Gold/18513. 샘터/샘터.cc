#include <iostream>
#include <unordered_set>
#include <queue>
using namespace std;
#define ll long long

int dx[] = {-1,1};

int n,k;
unordered_set<int> s;
queue<int> q;
ll misfortune=1, ans=0;

ll bfs() {
    while(!q.empty()) {
        int curSize = q.size();
        
        // 현재 후보군에서 왼쪽 오른쪽 한칸씩 간 곳이 샘터의 위치가 됨
        // 따라서 후보군들을 모두 뽑고 얘네들 기준 왼,오른쪽을 보고 구하야 하는 샘터의 개수를 하나씩 줄여나가면 됨
        // 그러다가 샘터를 모두 구했으면 끝
        for(int i=0; i<curSize; i++) {
            int cur = q.front();
            q.pop();
            
            for(int dir=0; dir<2; dir++) {
                int nx = cur + dx[dir];
                
                if(s.find(nx)!=s.end()) continue; //이미 그 곳에 샘터가 있거나 집이 있는 경우
                
                s.insert(nx); 
                q.push(nx);
                ans+=misfortune;
                
                k--;
                if(k<=0) return ans; // 모든 집을 다 설치했으므로
            }
        }
        misfortune++; // 동일한 거리는 다 처리했으니 +1 해서 그 다음 거리들을 처리해주기 
    }
    return ans;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(nullptr); cout.tie(nullptr);
    
    cin>>n>>k;
    
    for(int i=0; i<n; i++) {
        int x; cin>>x;
        
        s.insert(x);
        q.push(x); //샘터의 위치를 큐에 넣음
    }
    
    cout<<bfs();

    
    return 0;
}