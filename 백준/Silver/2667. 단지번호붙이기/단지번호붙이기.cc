#include <iostream>
#include <string.h>
#include <algorithm>
#include <stdio.h>
#include <queue>
#include <vector>
using namespace std;

constexpr int N = 26;
bool mat[N][N]; //1: 집있음, 0: 집없음
bool visited[N][N]; //방문 체크
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
int house=0; //한 단지내 집 개수
vector<int> v; //각 단지의 집 개수 저장
int n; 

void dfs(int r, int c){
    visited[r][c] = 1;
    for(int i=0; i<4; i++){
        int nx = r + dx[i];
        int ny = c + dy[i];

        if(nx>=0 && ny>=0 && nx<n && nx<n){
            if(mat[nx][ny] && !visited[nx][ny]){
                //visited[nx][ny] = 1;
                house++;
                dfs(nx, ny);
            }
        }
    }
}
int main() {
    cin>>n;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            scanf("%1d", &mat[i][j]);
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(mat[i][j] && !visited[i][j]){
                //visited[i][j]=1;
                house++;
                dfs(i,j);
                v.push_back(house);
                house=0; //각 단지내 집 수는 초기화
            }
        }
    }

    cout<<v.size()<<'\n';
    sort(v.begin(), v.end());
    for(int i=0; i<v.size(); i++){
        cout<<v[i]<<'\n';
    }
}