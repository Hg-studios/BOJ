#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<vector<int> > land)
{
    int answer = 0;

    int n = land.size();
    if(!n) return 0;
    
    int dp[100001][4]; // dp[a][b]=c : a행에 b번째 칸을 밟을 때 최댓값 c
    
    
    for(int i=0; i<4; i++) {
        dp[0][i] = land[0][i];
    }
    
    for(int i=1; i<n; i++) {
        for(int j=0; j<4; j++) {
            if(j==0) dp[i][j] = max({dp[i-1][1],dp[i-1][2],dp[i-1][3]}) + land[i][j];
            else if(j==1) dp[i][j] = max({dp[i-1][0],dp[i-1][2],dp[i-1][3]}) + land[i][j];
            else if(j==2) dp[i][j] = max({dp[i-1][0],dp[i-1][1],dp[i-1][3]}) + land[i][j];
            else if(j==3) dp[i][j] = max({dp[i-1][0],dp[i-1][1],dp[i-1][2]}) + land[i][j];
        }
    }

    return max({dp[n-1][0],dp[n-1][1],dp[n-1][2],dp[n-1][3]});
}