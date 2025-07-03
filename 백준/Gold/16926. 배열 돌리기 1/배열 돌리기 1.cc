#include <iostream>
#include <vector>
using namespace std;

int n,m,r;
int v[301][301];

// 순서 중요함
// 오 아 왼 위
int dx[] = {0,1,0,-1};
int dy[] = {1,0,-1,0};

void rotate(int cnt) {
    for(int i=0; i<cnt; i++) {
        int tmp = v[i][i];
        int r = i;
        int c = i;
        
        int dir=0;
        while(dir<4) {
            // ** 코딩할때는 중요한 게 옮길 대상을 찾는 것임
            // 차례로 옮길 대상을 보면 옮기려는 방향의 반대 방향으로 찾아야함
            int nr = r + dx[dir]; // 옮길 대상
            int nc = c + dy[dir];
            
            if(nr==i && nc==i) break;
            if(i<=nr && nr<n-i && i<=nc && nc<m-i) { // 범위를 벗어나지 않았다면
                v[r][c] = v[nr][nc];
                r = nr;
                c = nc;
            }
            else { // 범위를 벗어나면 다음 방향으로 전환
                dir++;
            }
        }
        v[i+1][i] = tmp;
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(nullptr); cout.tie(nullptr);
    
    cin>>n>>m>>r;
    
    // vector<vector<int>> v(n, vector<int> (m));

    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cin>>v[i][j];
            // cout<<v[i][j]<<" ";
        }
        // cout<<'\n';
    }
    
    int cnt = min(n,m)/2;
    
    for(int i=0; i<r; i++) {
        rotate(cnt);
    }
    
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            // cin>>v[i][j];
            cout<<v[i][j]<<" ";
        }
        cout<<'\n';
    }
    
    return 0;
}