#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

string to_binary (int n) {
    string tmp="";
    
    while(1) {
        tmp = to_string(n%2) + tmp;
        n/=2;
        
        if(n==0) break;
    }
    
    return tmp;
}

vector<int> solution(string s) {
    vector<int> answer;
    
    int turn=0;
    int cnt=0;
    
    string cur = s;
    
    while(1) {
        turn++;
        
        int tmp = 0;
        
        for(auto c : cur) { // 0의 개수 세기
            if(c=='0') tmp++;
        }
        
        cnt+=tmp; // 이번 턴에서의 0의 개수 저장
        
        cur = to_binary(cur.size() - tmp); // 1의 개수를 이진 변환하기
        
        if(cur=="1") break; // 1이 되면 탈출
    }
    
    answer.push_back(turn);
    answer.push_back(cnt);
    
    return answer;
}