#include <iostream>
#include <algorithm>
using namespace std;

int t, w; //자두가 떨어지는 총 t초, 움직일 수 있는 최대 w번 
int s[1005];
int d[1005][35]; //d[a][b]=k : a초일 때 b번 움직인 경우 얻을 수 있는 자두의 최대개수는 k개

//1에서 시작했으니깐 0,2,4,6,..초에 1번 나무에 위치함
//1,3,5,7,9,..초에는 2번 나무에 위치하게 됨

//b(0부터 w까지)랑 s[i]가 같으면, +1...
//b%2가 0이면 1번나무에 있는 것이고, 1이면 2번나무에 있는 것임
//d[a][b] = max(d[a-1][b-1], d[a-1][b])


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>t>>w;
    for(int i=1; i<=t; i++) cin>>s[i];


    //자두가 한 번도 움직이지 않았을 때
    int cnt=0;
    for(int i=1; i<=t; i++){
        if(s[i]==1) cnt++;
        d[i][0]=cnt;
    }

    for(int i=1; i<=t; i++){
        for(int j=1; j<=w; j++){
            d[i][j] = max(d[i-1][j-1], d[i-1][j]) + (s[i]==1+j%2);
        }
    }

    cout<<*max_element(d[t], d[t]+w+1);
}