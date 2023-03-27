#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
#define X first
#define Y second 

int l,r,c;
int el, er, ec; //탈출가능한 출구 좌표
char building[32][32][32];
int visited[32][32][32]; //-1 초기화, 0부터 거리측정 
queue<pair<pair<int,int>,int>> q; //3차원 큐 생성
//queue<tuple<int,int,int>> q; //3차원 큐 생성

int dx[6] = {1,-1,0,0,0,0};
int dy[6] = {0,0,-1,1,0,0};
int dz[6] = {0,0,0,0,-1,1};

void BFS(){
    while(!q.empty()){
        auto cur = q.front();
        q.pop();
        //int curZ, curX, curY;
        //tie(curZ, curX, curY) = cur;

        for(int dir=0; dir<6; dir++){
            
            int nz = cur.X.X + dz[dir];
            int nx = cur.X.Y + dx[dir];
            int ny = cur.Y + dy[dir];
            // int nz = curZ + dz[dir];
            // int nx = curX + dx[dir];
            // int ny = curY + dy[dir];

            if(nz<0||nz>=l||nx<0||nx>=r||ny<0||ny>=c) continue;
            if(visited[nz][nx][ny]!=-1||building[nz][nx][ny]=='#') continue;
            
            visited[nz][nx][ny] = visited[cur.X.X][cur.X.Y][cur.Y]+1;
            q.push({{nz,nx},ny});
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    while(1){
        cin>>l>>r>>c;
        if(!(l|r|c)) break;

        //입력 받기
        for(int k=0; k<l; k++){
            for(int i=0; i<r; i++){
                for(int j=0; j<c; j++){
                    cin>>building[k][i][j]; //입력받기
                    visited[k][i][j]=-1; //visited배열 -1로 초기화
                    if(building[k][i][j]=='S') { //출발점 큐에 넣기 
                        q.push({{k,i},j});
                        visited[k][i][j]=0; //출발점은 dist가 0부터 시작
                    }
                    if(building[k][i][j]=='E') { //출구 좌표 저장 
                        el = k; er = i; ec = j;
                    }
                }
            }
        }
        BFS();

        if(visited[el][er][ec]==-1) cout<<"Trapped!"<<'\n';
        else cout<<"Escaped in "<< visited[el][er][ec] <<" minute(s)."<<'\n';
    }
    
    return 0;
}

