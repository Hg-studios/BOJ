#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
#define X first
#define Y second

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int n,m;
int year; //year:최초의시간
int area[303][303];
int visited[303][303];
queue<pair<int,int>> q;

bool OOB(int x, int y){
    return x<0||x>=n||y<0||y>=m;
}

void initVis(){
    for(int i=0; i<n; i++) fill(visited[i], visited[i]+m, 0);
}

//빙산 녹이기 
void melting(){
    //현재 빙산 상태를 cur배열에 복사하고, 이 배열을 보고 area배열을 바꿈
    int cur[303][303];
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cur[i][j]=area[i][j];
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            //area값이 1이상인, 빙하가 있는 칸만 확인함 
            if(cur[i][j]==0) continue;
            
            int cnt=0; //상하좌우 중 0인 곳을 카운트함 
            for(int dir=0; dir<4; dir++){
                int nx = i + dx[dir];
                int ny = j + dy[dir];

                if(OOB(nx,ny)) continue;
                if(cur[nx][ny]==0) cnt++;
            }
            area[i][j] -= cnt; //상하좌우 중 바닷물의 개수만큼 뺌
            if(area[i][j]<0) area[i][j]=0; //그 값이 음수가 되면 0으로 처리
        }
    }
}

//return값 0 : 빙하가 모두 녹았는데도 한 덩어리인 경우
//return값 1 : 빙하가 아직 한 덩어리인 경우
//return값 2 : 빙하가 두 덩어리로 분리됨
int status(){
    //일단 빙하가 몇 덩어리인지 세고, 2개이면 바로 2리턴
    //1개이면 빙하가 모두 녹은 상태인지를 확인하여 0인지 1인지 확인
    int cnt=0;
    
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(visited[i][j]||area[i][j]==0) continue;

            cnt++;
            visited[i][j]=1;
            q.push({i,j});

            while(!q.empty()){
                auto cur = q.front();
                q.pop();

                for(int dir=0; dir<4; dir++){
                    int nx = cur.X + dx[dir];
                    int ny = cur.Y + dy[dir];

                    if(OOB(nx,ny)) continue;
                    if(visited[nx][ny]||area[nx][ny]==0) continue;

                    visited[nx][ny]=1;
                    q.push({nx,ny});
                }
            }
        }
    }
    if(cnt>=2) return 2;

    bool zero=1;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(area[i][j]!=0) zero=0; //빙하를 하나라도 찾으면 zero=0
        }
    }

    //모두 녹았으면서 덩어리가 하나인 경우
    if(zero) return 0;
    //모두 녹진 않았는데 덩어리가 하나인 경우
    return 1;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>n>>m;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>area[i][j];
        }
    }

    while(1){
        year++; //1년 추가 
        melting(); //빙산 녹이기
        initVis(); //visited배열 초기화 
        int check = status(); //빙산의 상태 확인

        if(check==0){ //빙하가 모두 녹았는데도 한 덩어리인 경우 
            cout<<0;
            return 0;
        }
        else if(check==1) continue; //빙하가 아직 한 덩어리인 경우
        else break; //check==2, 빙하가 두 덩어리로 분리됨 
    }
    cout<<year;

    return 0;
}