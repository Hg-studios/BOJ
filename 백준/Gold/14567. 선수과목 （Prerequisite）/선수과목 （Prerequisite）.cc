#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// https://www.youtube.com/watch?v=Th-gLZUrd04

int main()
{
    int n, m; cin>>n>>m;
    
    // 재귀로 50만은 불가능함 
    // 그럼 어차피 선수과목은 고정이므로 dp에 저장할까?
    // 아래와 같은 예시가 있다면 
    // 6 4
    // 1 2
    // 1 3
    // 2 5
    // 4 5
    // dp[2]와 dp[4]를 더하면 되지 않을까? 
    // 근데 문제는 dp[2]와 dp[4]에 같은 과목이 있다면 문제임
    // 따라서 앞에서부터 dp값을 채우고 이걸 dp[2]+dp[4] 처럼 처리하는 건 문제가 됨 
    
    
    // 위상정렬
    
    vector<vector<int>> adj(n+1); // 선수과목 관계를 저장함
    vector<int> indegree(n+1); // 해당 과목이 화살표의 머리 부분인 게 몇 개인지 저장
    // indegree를 저장하는 이유는 indegree가 0이라면 더이상 이 과목보다 미리 들어야 하는 과목이 없다는 의미라서
    // 이 과목을 수강할 수 있다는 의미가 됨
    
    for(int i=0; i<m; i++) {
        int x,y; cin>>x>>y;
        adj[x].push_back(y);
        indegree[y]++;
    }
    
    queue<int> q; // indegree가 0인 과목을 넣어서 선수과목 순서대로 살펴볼 수 있도록 해줌
    vector<int> level(n+1,0); // 각 과목을 몇 학기만에 들을 수 있는지 
    for(int i=1; i<=n; i++) {
        // 선수과목을 들을 게 없어서 당장 수강할 수 있는 과목부터 큐에 넣고 검사 시작
        if(indegree[i]==0) {
            q.push(i);
            level[i]=1; // 1학기부터 시작
        }
    }
    
    while(!q.empty()) {
        int cur = q.front();
        q.pop();
        
        // 현재 과목을 수강하면 그 다음으로 들을 수 있는 과목들을 찾아서 처리해줌 
        for(int next : adj[cur]) {
            indegree[next]--; // cur을 수강하게 되므로, cur와 연결된 next는 indegree가 1 줄음
            
            if(indegree[next]==0) q.push(next); // 더이상 나를 선수과목으로 하는 과목이 없으므로 내 순서가 온것임 
            level[next] = max(level[next], level[cur]+1); // 여러 선수과목을 거쳤다가 나로 올 수 있음
                                                            // 따라서 이전의 선수과목을 거치는 것 vs 현재 선수과목을 거친 것 +1
        }
    }
    
    for(int i=1; i<=n; i++) {
        cout<<level[i]<<" ";
    }
    
    return 0;
}