#include <iostream>
#include <algorithm>
using namespace std;

int n, k;
int w[105];
int v[105];
int d[105][100005]; //d[a][b]=k : a번 물건까지 왔고 가방의 무게가 b일 때 가방에 담긴 물건의 가치가 c

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>n>>k;
    for(int i=1; i<=n; i++) cin>>w[i]>>v[i];

    for(int i=1; i<=n; i++){ //배낭에 넣을 물건 번호
        for(int j=1; j<=k; j++){ //현재 배낭의 무게 
            //가방에 이번 물건을 넣을 수 있는 경우
            //기존에 탐색했던 물건들로만 무게j를 만드는 경우와
            //기존에 탐색했던 물건들로는 무게j-w[i]를 만들고, 현재 물건을 가방에 넣는 경우 중 큰 값 선택
            //즉, 현재 물건을 넣을지 말지를 판단해줘야 함
            if(j-w[i]>=0) d[i][j] = max(d[i-1][j], d[i-1][j-w[i]]+v[i]);
            //가방에 이번 물건을 넣을 수 없는 경우 
            else d[i][j] = d[i-1][j];
        }
    }

    cout<<d[n][k]<<'\n';
}