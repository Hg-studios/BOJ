#include <string>
#include <vector>
#include <map>
#include <iostream>
using namespace std;

int solution(vector<string> want, vector<int> number, vector<string> discount) {
    int answer = 0;
    
    map<string, int> m;
    
    // discount 1~9일까지의 물품 저장
    for(int i=0; i<9; i++) m[discount[i]]++;
    
    // 10일부터는 제품 하나 넣고, 조건에 맞는지 확인하고, 제품 빼고 <- 이렇게 해야함
    for(int i=9; i<discount.size(); i++) {
        m[discount[i]]++;
        
        // for(auto x : m) cout<<x.first<<" "<<x.second<<'\n';
        // cout<<'\n';
        
        bool flag = true;
        for(int j=0; j<want.size(); j++) {
            if(m[want[j]] < number[j]) {
                flag = false;
                break;
            }
        }
        
        if(flag) answer++;
        
        m[discount[i-9]]--;
    }
    
    
    
    
    return answer;
}