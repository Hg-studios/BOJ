#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};
int main()
{
    int r,c,n; cin>>r>>c>>n;
    
    vector<vector<char>> v(r, vector<char> (c));
    for(int i=0; i<r; i++) {
        string s; cin>>s;
        for(int j=0; j<c; j++) {
            v[i][j] = s[j];
        }
    }
    
    // 폭탄으로 다 채워진 상태
    if(n%2==0) {
        for(int i=0; i<r; i++) {
            for(int j=0; j<c; j++) {
                cout<<'O';
            }
            cout<<'\n';
        }
        return 0;
    }
    
    
    // 계산해야 됨
    int now = 1;
    while(now<n) {
        // 폭탄이 있는 좌표를 저장
        queue<pair<int,int>> q;
        for(int i=0; i<r; i++) {
            for(int j=0; j<c; j++) {
                if(v[i][j]=='O') {
                    q.push({i,j});
                }
            }
        }
        
        // 폭탄으로 다 채우기
        for(int i=0; i<r; i++) {
            for(int j=0; j<c; j++) {
                v[i][j]='O';
            }
        }
        
        // 폭탄이 있던 좌표들의 인접한 부분을 모두 터트림
        while(!q.empty()) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            
            v[x][y]='.';
            for(int dir=0; dir<4; dir++) {
                int nx = x + dx[dir];
                int ny = y + dy[dir];
                
                if(nx<0||ny<0||nx>=r||ny>=c) continue;
                v[nx][ny]='.';
            }
        }
        
        // 폭탄이 채워지고 터지는 걸 처리했으므로 2초가 지나야 함
        now+=2;
    }
    
    for(int i=0; i<r; i++) {
        for(int j=0; j<c; j++) {
            cout<<v[i][j];
        }
        cout<<'\n';
    }
    
    return 0;
}