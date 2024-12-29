#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

#define ll long long
#define MOD 1000000007

ll cnt; 
int n, k;
int from, tmp, to;
vector<ll> dp;

int main()
{
    cin>>n>>k;
    vector<int> input(n+1);
    
    for(int i=1; i<=n; i++) {
        cin>>input[i];
    }
    
    // 미리 2의 제곱수의 값 구해놓기
    dp.resize(n+1);
    dp[0]=1;
    for(int i=1; i<=n; i++) {
        dp[i] = (dp[i-1]*2)%MOD;
    }
    
    from=k;
    for(int i=n; i>0; i--) {
        if(from==input[i]) continue; // 가장 큰 원판의 목적지가 현재 위치라면 이동할 필요 없음
        
        // 큰 원판을 목적지로 옮기기 위해서는 from, tmp, to만 잘 설정하면 됨 
        tmp = input[i]; // 큰 원판을 input으로 옮기려면 i-1번째까지의 원판들은 모두 input을 중간지로 사용해야됨
        to = 6-from-tmp;
        
        cnt = (cnt + dp[i-1])%MOD;
        
        
        from = to;
    }

    cout<<cnt;
    
    return 0;
}