#include <iostream>

using namespace std;

int solution(int n, int a, int b)
{
    int answer = 0;

    // 0~(n-1) 인덱스가 있을 때, a와 b를 계속 2로 나누어서 그 값의 차이가 1이면 서로 붙게 됨
    
    // 인덱스화
    a-=1;
    b-=1;
    
    while(1) {
        answer++;
        
        // 둘이 붙게 되는 경우
        // 서로 번호가 1 차이나면서, 합이 1+4n 의 값일 때
        if(abs(a-b)==1 && (a+b-1)%4==0) return answer;
        
        // 아직 붙지 않은 경우
        a/=2;
        b/=2;
    }

    return answer;
}