/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

#define INF 2147483647
#define X first

struct mat {
    int r, c;
};

int main()
{
    int n; cin>>n;
    
    vector<mat> v(n);
    for(int i=0; i<n; i++) {
        int r, c; cin>>r>>c;
        v[i] = {r,c};
        // cout<<v[i].r<<" "<<v[i].c<<'\n';
    }
    
    // dp 테이블은 큰 값으로 초기화
    vector<vector<int>> dp(n, vector<int> (n, INF));
    
    // ABC가 있을 때 순서는 고정되어 있으므로 무조건 *두 덩어리*로 쪼개주면 됨
    // 그래서 (AB)C 혹은 A(BC) 이렇게 나눌 수 있음
    // ABCD 라면 A/BCD, AB/CD, ABC/D 이렇게 3가지로 나눌 수 있음 
    // -> 그럼 쪼개진 거는 어차피 dp값이 구해져 있음
    //      왜냐면 더 짧은 길이의 dp값은 이미 구해놨으므로..!
    
    // 자기 자신 연산은 값이 0 임 
    for(int i=0; i<n; i++) {
        dp[i][i] = 0;     
    }
    
    // 표를 그려봤을 때 대각선에 가까운 칸들부터 채워져야 함
    // 그렇기 때문에 for문에 가장 바깥쪽에는 간격을 나타내는 값으로 정해야 됨
    for(int k=1; k<n; k++) { // 간격
        for(int start=0; start+k<n; start++) { // 시작점
            int end = start+k;
            for(int mid=start; mid<end; mid++) { // (시작점)~(시작점+간격) 사이를 하나하나 쪼개줘야 함 = 두 덩어리로 쪼개기 위한 중간값이 mid임
                dp[start][end] = min(dp[start][end], dp[start][mid] + dp[mid+1][end] + v[start].r*v[mid+1].r*v[end].c);
            }
        }
    }
    
    cout<<dp[0][n-1];
    
    return 0;
}