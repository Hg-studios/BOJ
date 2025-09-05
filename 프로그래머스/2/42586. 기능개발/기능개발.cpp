#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    
    int n = progresses.size();
    vector<int> day(n);
    
    for(int i=0; i<n; i++) {
        int tmp = (100-progresses[i])/speeds[i];
        tmp += ((100-progresses[i])%speeds[i]!=0? 1:0);
        cout<<tmp<<" ";
        day[i] = tmp;
    }
    
    int d=0;
    int mn=-1;
    for(int i=0; i<n; i++) {
        //다시 새 시작일을 찾아야 하는 경우
        if(mn==-1) {
            d++;
            mn=day[i];
        }
        // mn보다 빨리 배포 가능한 일인 경우 
        else if(day[i]<=mn) {
            d++;
        }
        // mn보다 늦은 배포일인 경우
        else if(day[i]>mn) {
            answer.push_back(d);
            mn = day[i];
            d=1;
        }
    }
    
    if(mn!=-1 && d!=0) answer.push_back(d);
    
    return answer;
}