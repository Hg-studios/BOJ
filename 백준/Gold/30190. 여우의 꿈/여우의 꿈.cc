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

ll dp[1000001];

ll moveN(int n) {
    // if (n == 0) return 1; // base case
    
    if(dp[n]!=-1) return dp[n];
    
    if(n%2==0) {
        dp[n] = (int) (((long) moveN(n / 2) * moveN(n/ 2)) % MOD);
    }
    else {
        dp[n] = (int) (((long) 2 * moveN(n-1)) % MOD);
    }
    
    return dp[n];
}

int main()
{
    cin>>n>>k;
    vector<int> input(n+1);
    fill(dp, dp + 1000001, -1);
    
    dp[0]=1;
    for(int i=1; i<=n; i++) {
        cin>>input[i];
    }
    
    from=k;
    // 가장 큰 원판을 기준으로 생각해서 옮겨야 함
    // 그래서 가장 큰 원판부터 어디로 옮겨야 할지 봐야하는 것이고,
    // 큰 원판을 옮기기 위해서는 나보다 작은 원판을 모두 옮기면 되는 것임
    // 그 옮기는 비용은 n^2-1이고 가장 큰 원판을 원하는 목적지로 옮겨지면(이 비용은 1) 총 n^2-1+1 = n^2임
    for(int i=n; i>0; i--) {
        if(from==input[i]) continue; // 가장 큰 원판의 목적지가 현재 위치라면 이동할 필요 없음
        
        // 큰 원판을 목적지로 옮기기 위해서는 from, tmp, to만 잘 설정하면 됨 
        tmp = input[i]; // 큰 원판을 input으로 옮기려면 i-1번째까지의 원판들은 모두 input을 중간지로 사용해야됨
        to = 6-from-tmp;
        
        // 내가 i일 때 나보다 작은 1~(i-1)번째 원판을 모두 tmp로 옮겨야 하므로 그 연산은 pow(2, i-1) -1 
        // 그리고 나서 나를 from에서 to로 옮기는 것이 +1
        // 따라서 총 pow(2, i-1) -> 이 값의 반환값이 double이라서 강제형변환 필요함 
        // cout<<(int)pow(2, i-1)<<'\n';
        // cout<<moveN(i-1);
        cnt = (cnt + moveN(i-1))%MOD;
        
        // cnt = (cnt + ((int)pow(2, i-1)%MOD)) % MOD;
        
        // 여기가 중요함!!
        // 옮기고 나서는 from에 있던 나보다 작은 원판들은 모두 tmp로 가 있음 
        // 그래서 나보다 작은 원판들의 시작점은 다시 to 기둥이 되는 것임
        from = to;
    }
    
    // 추가로 문제가 훼이크인 게 아름다운 모양을 못만드는 경우는 없음
    // 왜냐면 가장 큰 원판만 원하는 곳으로 옮기면 되는데, 그러기 위해서는 나보다 작은 원판들을 
    // 나의 목적지를 중간지로 둔 채 다 옮겨주면 됨
    // 이 과정은 모두 하노이 탑 규칙을 만족하면서 이동할 수 있고, 각 단계별로 생각했을 때 안되는 경우는 없으므로

    cout<<cnt;
    
    return 0;
}