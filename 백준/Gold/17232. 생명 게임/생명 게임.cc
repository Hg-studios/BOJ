#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n, m, t; cin>>n>>m>>t;
    int k, a, b; cin>>k>>a>>b;
    
    vector<vector<char>> map(n+1, vector<char>(m+1));
    for(int i=1; i<=n; i++) {
        string str; cin>>str;
        for(int j=1; j<=str.size(); j++) {
            map[i][j] = str[j-1];
        }
    }
    
    while(t-- > 0) {
        vector<vector<int>> sum(n+1, vector<int>(m+1,0));
        // 1. 누적합을 이용해서 각 T시간의 누적합 누하기
        // 각 칸마다 몇 개의 생명이 존재하는지 찾아야 됨
        for(int i=1; i<=n; i++) {
            for(int j=1; j<=m; j++) {
                sum[i][j] = sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1];
                if(map[i][j]=='*') sum[i][j]++;
            }
        }
        
        // 2. O(1) 에 현재 각 칸의 누적합인 개수 구하기
        // vector<vector<char>> newMap = map;
        
        for(int i=1; i<=n; i++) {
            for(int j=1; j<=m; j++) {
                int r1 = max(i-k, 1);
                int r2 = min(i+k, n);
                int c1 = max(j-k, 1);
                int c2 = min(j+k, m);
                
                int cnt = sum[r2][c2] - sum[r2][c1-1] - sum[r1-1][c2] + sum[r1-1][c1-1];
                
                
                // 어떤 조건에 부합하는지 확인
                if(map[i][j]=='*') {
                    cnt--; // 현재 칸은 포함시키지 않음 
                    if(cnt<a) map[i][j] = '.';
                    else if(cnt>b) map[i][j] = '.';
                }
                else {
                    if(a<cnt && cnt<=b) map[i][j]='*';
                }
            }
        }
        
        // map = newMap;
    }
    
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++) {
            cout<<map[i][j];
        }
        cout<<'\n';
    }
    
    
    return 0;
}