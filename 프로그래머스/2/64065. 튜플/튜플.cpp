#include <string>
#include <vector>
#include <cctype>
#include <map>
#include <algorithm>
#include <sstream>
#include <iostream>
using namespace std;


vector<int> solution(string s) {
    vector<int> answer;
    map<string, int> m;
    
    string tmp;
    for(int i=0; i<s.size(); i++) {
        // 숫자면 tmp에 더해나감
        if('0'<=s[i] && s[i]<='9') tmp+=s[i];
        
        // 숫자가 아니라면 tmp는 초기화
        else {
            // 여태까지 저장되어있던 tmp가 있다면 map에 저장해줌
            if(tmp!="") m[tmp]++;
            
            tmp = "";
        }
    }
    
    if(tmp!="") m[tmp]++;
    
    vector<pair<int,string>> v;
    
    for(auto x : m) {
        // cout<<x.first<<" "<<x.second<<'\n';
        v.push_back({x.second, x.first});
    }
    
    sort(v.begin(), v.end(), greater<>());
    
    for(auto x : v) {
        cout<<x.first<<" "<<x.second<<'\n';
        answer.push_back(stoi(x.second));
    }
    
    return answer;
}