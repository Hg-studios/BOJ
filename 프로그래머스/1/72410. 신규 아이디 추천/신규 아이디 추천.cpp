#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(string new_id) {
    string answer = "";
    
    vector<char> v;
    
    for(char c : new_id) {
        v.push_back(c);
    }
    
    // 1단계 검사
    for(int i=0; i<v.size(); i++) {
        char c = v[i];
        if(c>='A' && c<='Z') v[i] += ('a'-'A');
        
    }
    for(char c : v) cout<<c<<" ";
    cout<<'\n';
    
    // 2단계 검사
    vector<char> tmp;

    for(int i=0; i<v.size(); i++) {
        char c = v[i];
        
        if(c>='a' && c<='z') {
            tmp.push_back(c);
        }
        if(c>='0' && c<='9'){
            tmp.push_back(c);
        }
        if(c=='-' || c=='_' || c=='.') {
            tmp.push_back(c);
        }
    }
    v = tmp;
    
    // 3단계
    tmp.clear();
    
    int cnt=0;
    bool flag=false; //연속으로 나온 것인지 저장
    for(int i=0; i<v.size(); i++) {
        if(v[i]=='.') {
            if(flag) continue;
            else {
                flag=true;
                tmp.push_back(v[i]);
            }
        }
        else {
            flag=false;
            tmp.push_back(v[i]);
        }
    }
    v = tmp;
    
    // 4단계
    if(v.size()>0 && v[0]=='.') v.erase(v.begin());
    if(v.size()>0 && v[v.size()-1]=='.') v.erase(v.begin()+v.size()-1);
    
    // 5단계
    if(v.size()==0) v.push_back('a');
    
    // 6단계
    if(v.size()>=16) {
        v.erase(v.begin()+15, v.end());
    }
    if(v[v.size()-1]=='.') v.erase(v.end()-1);
    
    // 7단계
    if(v.size()<=2) {
        while(v.size()<3) {
            v.push_back(v.back());
        }
    }
    
    for(char c : v) {
        answer += c;
    }    
    
    return answer;
}