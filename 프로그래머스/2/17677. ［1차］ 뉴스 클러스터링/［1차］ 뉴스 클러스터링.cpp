#include <string>
#include <algorithm>
#include <iostream>
#include <unordered_map>
using namespace std;

int solution(string str1, string str2) {
    int answer = 0;
    
    // 대소문자 차이 무시
    transform(str1.begin(), str1.end(), str1.begin(), ::toupper);
    transform(str2.begin(), str2.end(), str2.begin(), ::toupper);
    
    // cout<<str1<<" "<<str2;
    
    // 2글자씩 자르기
    // map에 각각 저장
    unordered_map<string, int> m1, m2;
    
    for(int i=0; i<str1.size()-1; i++) { // i는 시작점
        bool flag = true;
        for(int j=0; j<2; j++) { // i부터 2개 선택
            if(str1[i+j]<'A' || str1[i+j]>'Z') flag = false;
        }
        if(!flag) continue;
        
        // 두 알파벳 모두 영어인 경우
        m1[str1.substr(i,2)]++;
    }
    
    for(int i=0; i<str2.size()-1; i++) { // i는 시작점
        bool flag = true;
        for(int j=0; j<2; j++) { // i부터 2개 선택
            if(str2[i+j]<'A' || str2[i+j]>'Z') flag = false;
        }
        if(!flag) continue;
        
        // 두 알파벳 모두 영어인 경우
        m2[str2.substr(i,2)]++;
    }
    
    for(auto cur : m1) cout<<cur.first<<" "<<cur.second<<'\n';
    cout<<'\n';
    for(auto cur : m2) cout<<cur.first<<" "<<cur.second<<'\n';
    
    int m = 0;
    for(auto cur1 : m1) {
        bool flag=false; //겹치는 게 있는지 체크
        
        for(auto cur2 : m2) {
            if(cur1.first==cur2.first) {
                answer+=min(cur1.second, cur2.second);
                m+=max(cur1.second, cur2.second);
                // answer+=cur1.second;
                // answer+=cur2.second;
                flag=true;
                // break;
            }
            else{
                m+=cur2.second;
            }
        }
        if(!flag) m+=cur1.second;
    }
    
    
    m=0;
    for(auto cur : m1) m+=cur.second;
    for(auto cur : m2) m+=cur.second;
    m-=answer;
    
    double d;
    if(m==0&&answer==0) d=1;
    else d = (double)answer/(double)m;
    
    cout<<answer<<" "<<m<<" "<<d<<'\n';
    cout<<d*65536.0<<'\n';
    cout<<(int)d*65536.0<<'\n';
    return (int)(d*65536.0);
}