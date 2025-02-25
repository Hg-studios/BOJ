#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

string binary(int n) {
    string s;
    while(n>1) {
        s+=to_string(n%2);
        n/=2;
    }
    s+=to_string(n);
    
    reverse(s.begin(), s.end());
    
    return s;
}

vector<int> solution(string s) {
    vector<int> answer;
    
    int cnt=0;
    int turn=0;
    while(1) {
        turn++;
        int tmp=0;
        for(int i=0; i<s.size(); i++) {
            if(s[i]=='1') tmp+=1;
            else cnt++;    
        }
        //길이가 1이되면 중지
        if(tmp==1) break;
        
        // tmp만큼의 길이를 이진 변환해야 함
        s = binary(tmp);
        // cout<<s<<" ";
    }
    // cout<<binary(8)<<" ";
    answer.push_back(turn);
    answer.push_back(cnt);
    
    return answer;
}