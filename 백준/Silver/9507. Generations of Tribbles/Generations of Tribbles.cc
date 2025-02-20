#include <iostream>
#include <vector>
using namespace std;
#define ll long long

vector<ll> dp(70, -1);

ll koong(ll n) {
    if(dp[n]!=-1) return dp[n];
    
    if(n<2) {
        dp[n]=1;
        return dp[n];
    }
    else if(n==2) {
        dp[n]=2;
        return dp[n];
    }
    else if(n==3) {
        dp[n]=4;
        return dp[n];
    }
    else if(n>3) {
        dp[n] = koong(n-1) + koong(n-2) + koong(n-3) + koong(n-4);
        return dp[n];
    }
}

int main()
{
    int t; cin>>t;
    
    while(t--) {
        int n; cin>>n;
        
        if(dp[n]!=-1) cout<<dp[n]<<'\n';
        else {
            cout<<koong(n)<<'\n';
        }
    }
    
    return 0;
}