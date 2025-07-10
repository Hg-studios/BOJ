/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct state {
    int idx, pos, sec;
    // 서있는 칸의 위치, 왼쪽인지 오른쪽인지, 몇 초가 흘렀는지 
};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(nullptr); cout.tie(nullptr);
    
    int n,k; cin>>n>>k;
    
    // bfs로 매 초마다 3가지 행동을 모두 해보는 것임 
    // 흐른 시간도 함께 저장하도록 함
    // 그렇게 n+1칸으로 이동하게 되면 클리어이고, 큐 안에 값이 다 사라질 때까지 n+1에 도달하지 못했다면 0을 출력 
    
    string s1, s2; cin>>s1>>s2;
    
    
    // 1-indexed 로 만들어줌
    s1 = "0" + s1;
    // cout<<s1<<'\n';
    // cout<<s1[1]<<" "<<s1[n];
    s2 = "0" + s2;
    // cout<<s1<<" "<<s2<<'\n';
    
    queue<state> q;
    int dx[] = {1,-1,k};
    vector<vector<bool>> visited(2, vector<bool>(n+1, false));
    
    visited[0][1]=true;
    q.push({1,0,1}); // 1칸에 왼쪽 (0)의 1인덱스에서 출발
    
    while(!q.empty()) {
        auto cur = q.front();
        // cout<<cur.idx<< " "<<cur.pos<<" "<<cur.sec<<'\n';
        q.pop();
        
        if(cur.idx>=n+1) {
            cout<<1;
            return 0;
        }
        
        // 지금 위치에서 갈 수 있는 행동을 취함
        for(int dir=0; dir<3; dir++) {
            int nx = cur.idx + dx[dir];
            int npos;
            
            if(dir<2) npos = cur.pos; 
            else npos = 1-cur.pos;
            
            if(nx<1) continue; // 범위를 벗어남
            if(nx>=n+1) { // n번 칸보다 더 큰 칸으로 이동한 경우
                cout<<1;
                return 0;
            }
            if(visited[npos][nx]) continue;
            if(nx<=cur.sec) continue; // nx는 그 다음 초에 가는 것인데 그러면 cur의 sec 칸은 없어지게 됨
            if(dir==0||dir==1) { // 현재 줄을 그대로 가는 경우 
                if(cur.pos==0) { // 현재 줄이 왼쪽인 경우 
                    if(s1[nx]=='0') continue;
                }
                else { // 현재 줄이 오른쪽인 경우 
                    if(s2[nx]=='0') continue;
                }
            }
            else { // 옆의 줄로 이동하는 경우 
                if(cur.pos==0) { // 현재 줄이 왼쪽인 경우 
                    if(s2[nx]=='0') continue;
                }
                else { // 현재 줄이 오른쪽인 경우 
                    if(s1[nx]=='0') continue;
                }
            }
            
            visited[npos][nx] = true;
            // 그 다음 칸으로 이동할 수 있다고 판단된 경우
            if(dir==0||dir==1) q.push({nx, cur.pos, cur.sec+1});
            else q.push({nx, 1-cur.pos, cur.sec+1});
        }
    }
    
    cout<<0;
    
    return 0;
}