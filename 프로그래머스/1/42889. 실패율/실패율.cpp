#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool cmp (pair<double,int>&a, pair<double,int>& b) {
    // 실패율이 같으면 작은 번호의 스테이지부터 오도록 (오름차순)
    if(a.first==b.first) return a.second<b.second;
    // 실패율은 내림차순
    return a.first>b.first;
}

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    
    vector<pair<int,int>> v(N+1); //현재 이 스테이지에 있는 사람, 이 스테이지를 도전한 사람 
    
    for(int stage : stages) {
        for(int i=1; i<=min(N,stage); i++) v[i].second++; // 이 스테이지를 도전한 사람 모두 구하기
        if(stage<=N) v[stage].first++;
    }
    
    for(auto x : v) {
        cout<<x.first<<" "<<x.second<<'\n';   
    }
    
    vector<pair<double,int>> rate; // 실패율과 스테이즈 번호 저장
    for(int i=1; i<=N; i++) {
        if(v[i].first==0) rate.push_back({0,i});
        else rate.push_back({double(v[i].first)/double(v[i].second), i});
        // cout<<r<<" "<<i<<'\n';
    }
    sort(rate.begin(), rate.end(), cmp);
    for(auto x : rate) cout<<x.first<<" "<<x.second<<'\n';;
    
    for(auto x : rate) answer.push_back(x.second);
    
    return answer;
}