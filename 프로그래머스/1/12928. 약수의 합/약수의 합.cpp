#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int n) {
    int answer = 0;
    
    for(int i=1; i*i<=n; i++) {
        if(n!=0) {
            if(n%i==0) {
                answer += i;
                if(i*i!=n) answer += n/i;
            }   
        }
    }
    
    return answer;
}