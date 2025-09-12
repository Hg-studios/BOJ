#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

#define ll long long

string convert(int n, int k) {
    string tmp;
    
    while(1) {
        tmp = to_string(n%k) + tmp;
        n/=k;
        
        if(n==0) break;
    }
    
    return tmp;
}

bool is_prime(string str) {
    if(str=="" || str=="1") return false;
    
    // *** 여기서 stoi 하고 나면, int 범위를 넘어설 수 있기 때문에 ㅋ...
    // *** 꼭 ll로 변환하기 
    ll n = stoll(str);
    
    for(ll i=2; i*i<=n; i++) {
        if(n%i==0) return false;
    }
    
    return true;
}

int solution(int n, int k) {
    string str = convert(n, k);
    // cout<<str<<'\n';
    
    string tmp="";
    int answer = 0;
    for(int i=0; i<str.size(); i++) {
        // 0이 아닌 경우
        if(str[i]!='0') tmp+=str[i];
        
        // 0을 만난 경우
        else {
            // 여태까지 수가 소수인지 판단하고, 소수라면 answer++
            if(is_prime(tmp)) {
                // cout<<tmp<<'\n';
                answer++;
            }
            tmp=""; // 초기화
        }
    }
    
    // tmp가 "" 가 아니면서 소수라면 0P 형태이므로 답에 추가해줌
    if(tmp!="" && is_prime(tmp)) answer++;
    
    return answer;
}
