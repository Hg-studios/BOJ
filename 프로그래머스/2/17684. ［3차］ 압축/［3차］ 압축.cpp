#include <string>
#include <vector>
#include <map>
#include <iostream>
using namespace std;

vector<int> solution(string msg) {
    vector<int> answer;
    
    map<string, int> m;
    
    string s[] = {"A", "B", "C", "D", "E", 
                  "F", "G", "H", "I", "J", 
                  "K", "L", "M", "N", "O", 
                  "P", "Q", "R", "S", "T", 
                  "U", "V", "W", "X", "Y", "Z"};
    
    for(int i=0; i<26; i++) {
        m[s[i]] = i+1;
    }
    
    int turn=27; // 27번부터 채워줌
    int idx = 0;
    
    for(int i=0; i<msg.size(); i++) {
        // i 인덱스부터 하나씩 길이를 늘려가면서, map에 있는 string을 찾아야함
        int len = 0;
        while(1) {
            if (i+len+1>msg.size()) break; // 인덱스의 범위가 현재 메세지의 범위를 넘어가면 안됨
            
            string str = msg.substr(i, len+1); // 현재 인덱스에서부터 몇 개를 더 볼 수 있는지 (이미 map에 있는지)
            if(m[str]==0) break; // 없다면 멈춤
            len++; // 있다면 길이 늘려줌
        }
        
//         cout<<" "<<len<<'\n';
//         break;
        string str = msg.substr(i,len);
        // cout<<"str "<<str<<'\n';
        answer.push_back(m[str]);
        
        i+=(len-1); // 어디까지 검사한 것인지 저장하기, len 길이만큼은 본 것이므로 검사하지 않고 넘어감 
        // cout<<"i:"<<i<<'\n';
        // 마지막 문자만 아니라면, w+c를 저장해줘야함
        // i+1 번째 알파벳을 더해서 그걸 사전에 추가해줌
        if(i != msg.size()-1) {
            // cout<<"사전추가 "<<str + msg.substr(i+1,1)<<'\n';
            m[str + msg.substr(i+1,1)] = turn++;
        }
        
        // if(i==3) break;
        // break;
    }
    
    return answer;
}