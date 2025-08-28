#include <string>
#include <vector>
#include <iostream>

using namespace std;

// n을 2진수로 표현했을 때 1의 개수 
int check(int n) {
    int cnt=0;
    while(1) {
        if(n%2==1) cnt++;
        n/=2;
        if(n==0) break;
    }
    
    return cnt;
}

int solution(int n) {
    int answer = 0;
    
    int tmp=1;
    while(1) {
        if(check(n) == check(n+tmp)) {
            answer = n+tmp;
            break;
        }
        tmp++;
    }
    
    return answer;
}