#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <map>
using namespace std;

#define X first
#define Y second

struct record {
    string num;
    int min;
    string state;
};

bool cmp (record &a, record &b) {
    if(a.num==b.num) return a.min<b.min;
    return a.num<b.num;
}

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    
    // 일단 records 에 있는 내용들을 토그나이징해줌 
    vector<record> history;
    
    for(auto record : records) {
        istringstream input; 
        input.str(record);
        
        int cnt=0;
        int min=0; string num, state;
        for(string line; getline(input, line, ' ');) {
            if(cnt==0) { // 시간은 : 을 기준으로 쪼개서 분으로 변환하기
                int cnt2=0;
                
                istringstream input2;
                input2.str(line);
                
                for(string line2; getline(input2,line2,':');) {
                    if(cnt2==0) min+=stoi(line2)*60;
                    else min+=stoi(line2);
                    cnt2++;
                }
            }
            else if(cnt==1) {
                num = line;
            }
            else {
                state = line;
            }
            cnt++;
        }
        
        // cout<<min<<" "<<num<<" "<<state<<'\n';
        history.push_back({num, min, state});
    }
    
    sort(history.begin(), history.end(), cmp);
    
    map<string, int> m; // 각 차량별로 주차요금
    
    int n = history.size();
    for(int i=0; i<n; i++) {
        // 그 다음 OUT 거까지를 보고 계산하면 됨
        
        // 그 다음 OUT이 있는지 확인하기
        
        // 1. 그 다음 자동차 기록이 다른 차량이거나 가장 마지막 기록이 IN인 경우
        // OUT이 23:59으로 계산해주면 됨
        if(history[i+1].num != history[i].num || i==n-1) {
            m[history[i].num] += (23*60+59)-history[i].min;
        }
        // 2. 그 다음 기록이 정상적으로 OUT인 경우 
        else {
            m[history[i].num] += (history[i+1].min - history[i].min);
            i++; // 그 다음 OUT까지 봤으니깐 그 기록을 건너뜀
        }
    }
    
    for(auto cur : m) {
        cout<<cur.X<<" "<<cur.Y<<'\n';
        // 기본 시간을 넘지 않은 경우, 기본 요금
        if(cur.Y <= fees[0]) answer.push_back(fees[1]);
        else {
            int tmp = fees[1];
            
            tmp += ((cur.Y - fees[0])/fees[2] + ((cur.Y-fees[0])%fees[2]>0 ? 1 : 0)) * fees[3];
            
            cout<<"*"<<cur.Y - fees[0]/fees[2]<<" ";
            cout<<cur.Y - fees[0]%fees[2]<<'\n';
            
            answer.push_back(tmp);
        }
        
        
         // cout<<cur.first<<" "<<cur.second<<'\n';
    
    }
    return answer;
}