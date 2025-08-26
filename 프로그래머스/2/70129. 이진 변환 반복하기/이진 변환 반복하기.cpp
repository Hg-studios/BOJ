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
        
        if(n==0) {
            break;
        }
    }
    // cout<<tmp;
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
        
        for(auto c : cur) {
            if(c=='0') tmp++;
        }
        
        cnt+=tmp;
        
        cur = to_binary(cur.size() - tmp);
        
        if(cur=="1") break;
    }
    
    answer.push_back(turn);
    answer.push_back(cnt);
    
    return answer;
}