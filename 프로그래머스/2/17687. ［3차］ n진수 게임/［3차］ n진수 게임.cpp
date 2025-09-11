#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

string convert(int n, int turn) {
    string tmp="";
    
    while(1) {
        // 나머지 값 구하기
        int rem = turn%n;
        if(rem<=9) tmp += to_string(rem);
        else {
            if(rem==10) tmp+='A';
            else if(rem==11) tmp+='B';
            else if(rem==12) tmp+='C';
            else if(rem==13) tmp+='D';
            else if(rem==14) tmp+='E';
            else if(rem==15) tmp+='F';
        }
        
        // 값을 n으로 나눈 몫으로 업데이트
        turn/=n;
        
        if(turn==0) break;
    }
    
    reverse(tmp.begin(), tmp.end());
    return tmp;
}

string solution(int n, int t, int m, int p) {
    // 총 구해야 되는 문자열의 길이
    // len 길이만큼은 구해야 됨
    int len = p + m * (t-1);
    
    string tmp="";
    int turn=0;
    while(tmp.size()<len) { // 구해야되는 길이보다 작을 때 계속 구함 
        tmp += convert(n, turn); // turn이라는 숫자를 n진수로 구했을 때 문자열을 계속 더함
        // cout<<convert(n,turn)<<'\n';
        turn++;
    }
    // cout<<tmp<<'\n';
    
    string answer = "";
    int cnt=0;
    for(int i=p-1; cnt<t; cnt++,i+=m) {
        answer+=tmp[i];
    }
    
    return answer;
}