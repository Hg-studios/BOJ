#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    
    // 짝수는 홀수 + 홀수로 나타낼 수 있음
    // 4를 제외하고 짝수 + 짝수는 안됨 -> 짝수인 소수는 2뿐이기 때문
    
    // 두 소수의 차이가 가장 작은 것 -> n/2부터 보기?
    
    
    // 소수인지 구해놓기
    // 최대 10000 이므로 5000 까지 소수판별을 해놓는 것임
    vector<bool> prime(10001, true);
    
    // 2부터 각 수의 배수는 false로 바꿔줌
    for(int i=2; i<=10000; i++) { // i의 배수들은 소수가 될 수 없음
        for(int j=i*2; j<=10000; j+=i) { // 따라서 j는 i를 더하면서 체크함
            prime[j]=false;
        }
    }
    
    int tc; cin>>tc;
    while(tc--) {
        int n; cin>>n;
        
        for(int i=n/2; i>=2; i--) {
            if(prime[i] && prime[n-i]) {
                cout<<i<<" "<<n-i<<'\n';
                break;
            }
        }
    }
    
    return 0;
}