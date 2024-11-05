#include <string>
#include <vector>
#include <map>
#include <sstream>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    vector<int> answer;
    
    // '.'을 기준으로 today 자르기
    vector<int> tdate;
    istringstream s(today);
    for(string line; getline(s, line, '.'); ) {
        tdate.push_back(stoi(line));
    }
    
    // terms 처리
    // 약관에 대한 유효기간을 map에 저장
    map<char, int> m;
    for(const auto& term : terms) {
        istringstream ss(term);
        char c; int t;
        ss>>c>>t;
        
        m[c]=t;
    }

    int count=1;
    // privacies 처리
    for(string privacy : privacies) {
        // 날짜와 약관 종류를 구분
        istringstream ss(privacy);
        string d; char c;
        ss>>d>>c;
        
        // 날짜를 '.'를 기준으로 자르기
        istringstream ss2(d);
        vector<int> date;
        for (string line; getline(ss2, line, '.'); ) {
            date.push_back(stoi(line));
        }
        
        // 유효기간만큼 더할건데 1일이면 예외 처리해줌
        if(date[2]==1) {
            date[2] = 28;
            date[1] += (m[c]-1);
        }
        else {
            date[2] -= 1;
            date[1] += m[c];
        }
        
        // 월이 12를 넘어가면 년도를 올려줌
        if(date[1]>12) {
            if(date[1]%12==0) { //24월 이런 숫자는 따로 처리
                date[0] += (date[1]/12)-1;
                date[1] = 12;
            }
            else {
                date[0] += date[1]/12;
                date[1] -= (date[1]/12)*12;
            }
        }
        
        for(int x : date) cout<<x<<" ";
        cout<<'\n';
        
        // 오늘과 유효기간 비교하기 
        // 유효기간이 지난 것을 찾기
        if(tdate[0]>date[0]) { // 연도가 지났으면 무조건 추가
            answer.push_back(count);
        }
        else if(tdate[0]==date[0]) { // 연도가 같으면
            // 월이 지났으면 무조건 추가
            if(tdate[1]>date[1]) answer.push_back(count);
            
            // 월이 같으면 
            else if(tdate[1]==date[1]) {
                if(tdate[2]>date[2]) answer.push_back(count);
            }
        }
        
        count++;
    }
    
    return answer;
}