#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n; cin>>n;
    string s1; cin>>s1;
    vector<vector<int>> dp(n+1, vector<int>(n+1,0)); // dp[i][j] : 인덱스 i부터 j 최장 공통 부분의 길이 
    
    string s2 = s1;
    reverse(s2.begin(), s2.end());
    s1 = ' ' + s1;
    s2 = ' ' + s2;
    
    //공통적으로 가장 긴 부분 구하기
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            if(s1[i]==s2[j]) dp[i][j] = dp[i-1][j-1]+1;
            else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }
    
    cout<<n-dp[n][n];
    
    return 0;
}