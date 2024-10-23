#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <sstream>
#include <algorithm>

using namespace std;

int trade[52][52];
int gift_grade[52];
int cnt[52];

int solution(vector<string> friends, vector<string> gifts) {
    int answer = 0;
    
    //string을 인덱스로 저장하려고 함
    // string -> int (idx)
    map<string, int> m;
    for(int i=0; i<friends.size(); i++) {
        m[friends[i]] = i;
    }
    
    for(string s : gifts) {
        // s를 tokenizing 하기
        stringstream sstream(s);
        string g;
        vector<string> list;
        
        while(getline(sstream, g, ' ')){
            list.push_back(g);
        }
        
        trade[m[list[0]]][m[list[1]]] += 1;
        // cout<<m[list[0]] << " "<<m[list[1]]<<'\n';
    }
    
    // for(int i=0; i<friends.size(); i++) {
    //     for(int j=0; j<friends.size(); j++) {
    //         cout<<trade[i][j]<<' ';
    //     }
    //     cout<<'\n';
    // }
    
    
    
    //선물 지수 구하기
    for(int i=0; i<friends.size(); i++) {
        // 내가 준 선물의 수
        int to=0, from=0;
        for(int j=0; j<friends.size(); j++) {
            if(i==j) continue;
            to += trade[i][j];
            from += trade[j][i];
        }
        
        gift_grade[i] = (to - from);
    }   
    
    for(int i=0; i<friends.size(); i++) {
        cout<<gift_grade[i]<<' ';
    }
     
    // 누가 선물을 많이 받을지 예측하기 
    for(int i=0; i<friends.size(); i++) {
        for(int j=i+1; j<friends.size(); j++){
            int a = trade[i][j];
            int b = trade[j][i];
            
            // 주고받은 수가 같거나, 선물 주고받은 기록이 없다면
            if((a==b) || (a==0 && b==0)) {
                if(gift_grade[i]==gift_grade[j]) continue;
                
                if(gift_grade[i]>gift_grade[j]) cnt[i]++;
                else cnt[j]++;
            }
            
            // 두 사람이 주고 받은 기록이 있다면
            else if(a!=0 || b!=0) {
                if(a>b) cnt[i]++;
                else if(b>a) cnt[j]++;
            }
            
            
        }
    }
    
    cout<<*max_element(cnt, cnt+friends.size());
    
    return *max_element(cnt, cnt+friends.size());
}