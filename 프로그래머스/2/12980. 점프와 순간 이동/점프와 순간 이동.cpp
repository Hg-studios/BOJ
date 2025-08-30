#include <iostream>
using namespace std;

int solution(int n)
{
    int ans = 0;
    
    // n부터 시작해서 0을 만들기!!
    // 무조건 2로 나누는 게 이득임
    
    while(1) {
        if(n%2==1) {
            ans++;
            n-=1;
        }
        else {
            n/=2;
        }
        
        if(n==0) break;
    }
    

    return ans;
}