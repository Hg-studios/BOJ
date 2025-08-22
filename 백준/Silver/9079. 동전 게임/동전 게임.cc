#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// 000 000 111, 000 111 000, 111 000 000, 100 100 100, 010 010 010, 001 001 001, 100 010 001, 001 010 100
int mask[] = {7, 56, 448, 73, 146, 292, 273, 84};

int make_bit(string& s) {
    int tmp=0;
    
    // s에서 높은 쪽은 왼쪽이고 낮은 쪽은 오른쪽이므로 
    // 마지막 인덱스부터 봐야함
    for(int i=8; i>=0; i--) {
        if(s[i]=='H') tmp |= (1<<(8-i));
    }
    
    return tmp;
}

int main()
{
    int n; cin>>n;
    
    while(n--) {
        // 입력 받기
        string str;
        for(int i=0; i<3; i++) {
            for(int j=0; j<3; j++) {
                char x; cin>>x;
                str+=x;
            }
        }
        
        // 입력받은 문자열을 숫자로 표현
        int x = make_bit(str);
        // cout<<x<<'\n';
        
        // bfs로 가능한 경우 탐색하기 (최단 경로이므로)
        vector<bool> visited(512, false); // 2^8-1 (111 111 111) 까지 인덱스가 있음
        queue<int> q;
        bool success = false;
        int ans=-1;
        int cnt=0;
        
        visited[x]=true;
        q.push(x);
        
        while(!q.empty() && !success) {
            int sz = q.size();
                cnt++;
            
            while(sz--) {
                auto cur = q.front();
                q.pop();
                
                if(cur==0 || cur==(1<<9)-1) {
                    success = true;
                    ans = cnt;
                    break;
                }
                
                for(int dir=0; dir<8; dir++) {
                    int next = cur ^ mask[dir]; // 동전을 뒤집는 것은 XOR 연산을 하는 것과 같음!!!
                    
                    if(visited[next]) continue;
                    
                    visited[next]=true;
                    q.push(next);
                }
            }
        }
        
        cout<<(ans==-1? -1 : ans-1)<<'\n';
    }
    
    
    return 0;
}