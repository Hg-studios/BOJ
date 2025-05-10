#include <iostream>
#include <vector>
using namespace std;

int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};

int main()
{
    // 가운데서부터하면 너무 어려움.. 
    // (0,0) 부터 시작하기
    
    int n,k; cin>>n>>k;
    
    vector<vector<int>> v(n, vector<int>(n,0));
    int x=0, y=0;
    int dir=0;
    pair<int,int> p;
    
    for(int i=n*n; i>0; i--) {
        v[x][y]=i;
        
        if(i==k) p = {x,y};
        
        // 다음으로 가는 좌표가 범위를 벗어나거나 이미 방문한 적이 있는 좌표로 갔다면 방향을 바꿔줌
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        
        if(nx<0 || ny<0 || nx>=n || ny>=n || v[nx][ny]!=0) dir = (dir+1)%4;
        
        x = x + dx[dir];
        y = y + dy[dir];
    }
    
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cout<<v[i][j]<<" ";
        }
        cout<<'\n';
    }
    cout<<p.first+1<<" "<<p.second+1;
    
    return 0;
}