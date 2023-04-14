#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int n,m;
int board[1005][1005];
int d[1005][1005];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>n>>m;
    for(int i=1; i<=n; i++){
        string s;
        cin>>s;
        for(int j=1; j<=m; j++){
            board[i][j] = s[j-1]-'0';
        }
    }

    int ans=0;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(board[i][j]){
                d[i][j]=min({d[i-1][j],d[i][j-1],d[i-1][j-1]})+1;
                ans = max(ans, d[i][j]);
            }
        }
    }

    cout<<ans*ans;
}