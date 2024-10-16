#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(string video_len, string pos, string op_start, string op_end, vector<string> commands) {
    string answer = "";
    
    // string -> int
    int current = stoi(pos.substr(0,2))*60 + stoi(pos.substr(3,2));
    int totalLen = stoi(video_len.substr(0,2))*60 + stoi(video_len.substr(3,2));
    int opStart = stoi(op_start.substr(0,2))*60 + stoi(op_start.substr(3,2));
    int opEnd = stoi(op_end.substr(0,2))*60 + stoi(op_end.substr(3,2));
    
    
    
    // 명령어 하나씩 돌면서 수행
    for(string s : commands) {
        // 오프닝 구간인지 확인
        if(current>=opStart && current<=opEnd) {
            current = opEnd;
        }
        if(s=="next") {
            if(current+10>=totalLen) {
                current = totalLen;
            }
            else {
                current+=10;
            }
        }   
        else { // "prev"
            if(current-10<=0) {
                current = 0;
            }
            else {
                current-=10;
            }
        }
        
        // 오프닝 구간인지 확인
        if(current>=opStart && current<=opEnd) {
            current = opEnd;
        }
        
        string tmp;
        int hour = current/60;
        int min = current%60;

        if(hour<10) tmp+="0"; 
        tmp+=to_string(hour);
        tmp+=":";
        if(min<10) tmp+="0";
        tmp+=to_string(min);

        cout<<tmp<<" ";
        
    }
    
    // 최종 값 int -> string 
    int hour = current/60;
    int min = current%60;
    
    if(hour<10) answer+="0"; 
    answer+=to_string(hour);
    answer+=":";
    if(min<10) answer+="0";
    answer+=to_string(min);
    
    cout<<answer;
    return answer;
}