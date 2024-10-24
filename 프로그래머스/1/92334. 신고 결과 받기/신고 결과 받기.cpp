#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <sstream>

using namespace std;

int arr[1002][1002];

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer(id_list.size(), 0);
    
    // id_list -> map에 저장
    map<string, int> m;
    for(int i=0; i<id_list.size(); i++) {
        m[id_list[i]] = i;
    }
    
    for(string s : report) {
        stringstream sstream(s);
        vector<string> list;
        string one;
        
        while(getline(sstream, one, ' ')){
            list.push_back(one);
        }
        
        arr[m[list[0]]][m[list[1]]] = 1;
    }
    
    for(int j=0; j<id_list.size(); j++) {
        int cnt=0;
        for(int i=0; i<id_list.size(); i++) {
            // j 고정 i가 하나씩 커짐 
            if(arr[i][j]==1) cnt++;
        }
        
        // 신고가 k번 이상이면
        if(cnt>=k) {
            for(int i=0; i<id_list.size(); i++) {
                if(arr[i][j]==1) answer[i]++;
            }
        }
    }
    
    return answer;
}