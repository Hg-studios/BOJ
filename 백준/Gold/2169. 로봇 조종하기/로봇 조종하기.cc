#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N, M;
    cin >> N >> M;
    
    vector<vector<int>> grid(N, vector<int>(M));
    for(int i=0; i<N; ++i){
        for(int j=0; j<M; ++j){
            cin >> grid[i][j];
        }
    }
    
    vector<long long> previous_dp(M, 0);
    previous_dp[0] = grid[0][0];
    for(int j=1; j<M; ++j){
        previous_dp[j] = previous_dp[j-1] + grid[0][j];
    }
    
    for(int i=1; i<N; ++i){
        vector<long long> left(M, LLONG_MIN);
        vector<long long> right(M, LLONG_MIN);
        
        // Left to Right
        left[0] = previous_dp[0] + grid[i][0];
        for(int j=1; j<M; ++j){
            left[j] = max(left[j-1], previous_dp[j]) + grid[i][j];
        }
        
        // Right to Left
        right[M-1] = previous_dp[M-1] + grid[i][M-1];
        for(int j=M-2; j>=0; --j){
            right[j] = max(right[j+1], previous_dp[j]) + grid[i][j];
        }
        
        // Combine
        vector<long long> current_dp(M, 0);
        for(int j=0; j<M; ++j){
            current_dp[j] = max(left[j], right[j]);
        }
        
        previous_dp = current_dp;
    }
    
    cout << previous_dp[M-1];
}