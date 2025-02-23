#include <iostream>
#include <vector>
using namespace std;

// 시작좌표 (s,s), 길이 n
void recur(int s, int n, vector<vector<char>>& v) {
    // cout<<s<<" "<<n<<'\n';
    
    // s기준으로 첫줄과 마지막 줄은 모두 별 찍기
    for(int j=s; j<=s+n-1; j++) {
        v[s][j]='*';
        v[s+n-1][j]='*';
    }
    
    
    // for(int i=1; i<=n; i++) {
    //     for(int j=1; j<=n; j++) {
    //         cout<<v[i][j];
    //     }
    //     cout<<'\n';
    // }
    
    // 둘째줄부터 마지막에서 위로 두번째 줄 양쪽에만 별 찍기
    for(int i=s+1; i<s+n-1; i++) {
        v[i][s]='*';
        v[i][s+n-1]='*';
        // v[s+n-1][s]='*';
        // v[s+n-1][s+n-1]='*';
    }
    
    // for(int i=1; i<=n; i++) {
    //     for(int j=1; j<=n; j++) {
    //         cout<<v[i][j];
    //     }
    //     cout<<'\n';
    // }
    // v[s+1][s]='*';
    // v[s+1][s+n-1]='*';
    // v[s+n-1][s]='*';
    // v[s+n-1][s+n-1]='*';
    
    // for(int i=1; i<=n; i++) {
    //     for(int j=1; j<=n; j++) {
    //         cout<<v[i][j];
    //     }
    //     cout<<'\n';
    // }
    if(n==1) return;
    
    recur(s+2, n-4, v);
}

int main()
{
    int a; cin>>a;
    
    int n = 4*a-3;
    vector<vector<char>> v(n+1, vector<char>(n+1,' '));
    
    recur(1,n,v);
    
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            cout<<v[i][j];
        }
        cout<<'\n';
    }
    
    return 0;
}