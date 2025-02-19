#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define X first
#define Y second 

int dx[] = {-1,0,1,0,-1,-1,1,1};
int dy[] = {0,1,0,-1,-1,1,-1,1};

int main()
{
    int n; cin>>n;
    
    vector<string> v(n);
    
    for(int i=0; i<n; i++) {
        cin>>v[i];
    }
    
    vector<vector<char>> ans(n, vector<char>(n, ' '));
    bool flag=false;
    
    for(int i=0; i<n; i++) {
        string s; cin>>s;
        
        for(int j=0; j<n; j++) {
            if(s[j]=='.') ans[i][j]='.';
            else {
                // 이미 열린 칸인데 폭탄이 있으면 지뢰가 있는 칸이 있다면 표시함
                if(v[i][j]=='*') {
                    flag = true;
                }
                else {
                    int cnt=0;
                    
                    // 현재 좌표의 8방향 확인하기 
                    for(int dir=0; dir<8; dir++) {
                        int nx = i + dx[dir];
                        int ny = j + dy[dir];
                        
                        if(nx<0||ny<0||nx>=n||ny>=n) continue;
                        if(v[nx][ny]=='*') cnt++;
                    }
                    ans[i][j]=cnt+'0';    
                }
            }
        }
    }
    
    // 지뢰가 있는 모든 칸을 별로 표시
    if(flag) {
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                if(v[i][j]=='*') ans[i][j]='*';
            }
        }
    }
    
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cout<<ans[i][j];
        }
        cout<<'\n';
    }
    
    return 0;
}