#include <iostream>
#include <queue>
using namespace std;

struct node {
    int l,r,c;
};

int dx[] = {1,-1,0,0,0,0};
int dy[] = {0,0,1,-1,0,0};
int dz[] = {0,0,0,0,-1,1};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    
    while(1) {
        int l,r,c; cin>>l>>r>>c;
        if(l==0 && r==0 && c==0) break;
        
        char arr[32][32][32];
        int dist[32][32][32];
        queue<node> q;
        
        // visited 배열 -1로 초기화
        for(int i=0; i<l; i++) {
            for(int j=0; j<r; j++) {
                for(int k=0; k<c; k++) {
                    dist[i][j][k]=-1;
                }
            }
        }
        
        // 입력받기 & 시작점 찾기
        for(int i=0; i<l; i++) {
            for(int j=0; j<r; j++) {
                string str; cin>>str;
                for(int k=0; k<str.size(); k++) {
                    arr[i][j][k]=str[k];
                    
                    if(arr[i][j][k]=='S') {
                        dist[i][j][k]=0;
                        q.push({i,j,k});
                    }
                }
            }
        }
        
        
        // 입력 잘 받았나 검사용 
        // for(int i=0; i<l; i++) {
        //     for(int j=0; j<r; j++) {
        //         for(int k=0; k<c; k++) {
        //             cout<<arr[i][j][k]<<" ";
                    
        //         }
        //         cout<<'\n';
        //     }
        //     cout<<'\n';
        // }
        
        bool flag=false; // 탈출구 찾는지 확인
        
        while(!q.empty()) {
            auto cur = q.front();
            q.pop();
            
            // 탈출구를 찾은 경우
            if(arr[cur.l][cur.r][cur.c]=='E') {
                cout<<"Escaped in "<<dist[cur.l][cur.r][cur.c]<<" minute(s)."<<'\n';
                flag=true;
                break;
            }
            
            // 다음 이동할 칸 찾기
            for(int dir=0; dir<6; dir++) {
                int nl = cur.l + dz[dir];
                int nr = cur.r + dx[dir];
                int nc = cur.c + dy[dir];
                
                if(nl<0||nr<0||nc<0||nl>=l||nr>=r||nc>=c) continue; // 범위 벗어남
                if(dist[nl][nr][nc]!=-1) continue; // 이미 방문한 경우
                if(arr[nl][nr][nc]=='#') continue; // 벽이면 통과 못함
                
                dist[nl][nr][nc] = dist[cur.l][cur.r][cur.c]+1;
                q.push({nl,nr,nc});
            }
        }
        
        if(!flag) cout<<"Trapped!"<<'\n';
    }
    
    return 0;
}