#include <iostream>
#include <vector>
using namespace std;

#define ll long long 

string s;
ll ans;

void recur(int idx, ll cnt, int cum, int kind, bool inc) {
    if(idx==s.size()) { // 문자열 끝까지 온 상황 
        // H가 없다면 답이 될 수 없음 
        if(inc) ans += cnt; // 최종적으로 답으로 더해줌 
        
        return;
    }
    
    if(s[idx]=='_') {
        // 빈칸에 알파벳을 넣어줌
        // 알파벳 넣고 나서 조건 부합한지 확인해주기!!
        
        if(idx==0) {
            // 모음 넣기
            recur(idx+1, cnt*5, 1, 0, inc);
            // L 넣기
            recur(idx+1, cnt, 1, 1, true);
            // 나머지 자음 넣기
            recur(idx+1, cnt*20, 1, 1, inc);
        }
        
        else {
            // 1. 빈칸에 모음 넣기
            // 이전에 연속한 알파벳이 모음이면서 1개 이하거나
            if(kind==0 && cum<=1) recur(idx+1, cnt*5, cum+1, kind, inc);
            // 자음인 경우 진행 가능
            if(kind==1) recur(idx+1, cnt*5, 1, 0, inc);
            
            
            // 2. 빈칸에 H 넣기
            // 이전에 모음이 연속됐 경우 진행 가능
            if(kind==0) recur(idx+1, cnt, 1, 1, true);
            // 이전에 자음이 연속됐다면
            if(kind==1 && cum<=1) recur(idx+1, cnt, cum+1, 1, true);
            
            // 3. 빈칸에 나머지 자음 넣기
            // 이전에 모음이 연속됐거나 맨처음칸이 빈칸인 경우 진행 가능
            if(kind==0) recur(idx+1, cnt*20, 1, 1, inc);
            // 이전에 자음이 연속됐다면 
            if(kind==1 && cum<=1) recur(idx+1, cnt*20, cum+1, 1, inc);
        }
        
        
    }
    // 첫번째가 빈칸이 아니면서 알파벳인 경우 
    else if(idx==0) {
        char c = s[idx];
        // 현재 알파벳이 모음인 경우
        if(c=='A' || c=='E' || c=='I' || c=='O' || c=='U') {
            recur(idx+1, cnt, 1, 0, inc);
        }
        else if(c=='L') {
            recur(idx+1, cnt, 1, 1, true);
        }
        else {
            recur(idx+1, cnt, 1, 1, inc);
        }
    }
    
    // 알파벳이 온 상황
    else {
        char c = s[idx];
        // 현재 알파벳이 모음인 경우
        if(c=='A' || c=='E' || c=='I' || c=='O' || c=='U') {
            // 여태까지 연속해오던 알파벳이 모음이라면
            if(kind==0) {
                // 이미 모음 2개가 연속한 상황 -> 더이상 진행 불가
                if(cum>=2) return;
                // 모음이 1개 연속한 상황 -> 연속된 알파벳 종류 바뀌지 않음 
                else recur(idx+1, cnt, cum+1, kind, inc);
            }
            // 여태까지 연속해오던 알파벳이 자음이라면
            else {
                recur(idx+1, cnt, 1, 1-kind, inc);
            }
        }
        // 현재 알파벳이 H인 경우
        else if(c=='L') {
            // 연속해오던 알파벳이 모음이라면
            if(kind==0) {
                recur(idx+1, cnt, 1, 1-kind, true);
            }
            // 연속해오던 알파벳이 자음이라면
            else {
                if(cum>=2) return;
                else recur(idx+1, cnt, cum+1, kind, true);
            }
        }
        // 현재 알파벳이 나머지 자음인 경우
        else {
            // 연속해오던 알파벳이 모음이라면
            if(kind==0) {
                recur(idx+1, cnt, 1, 1-kind, inc);
            }
            // 연속해오던 알파벳이 자음이라면
            else {
                if(cum>=2) return;
                else recur(idx+1, cnt, cum+1, kind, inc);
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(nullptr); cout.tie(nullptr);
    
    cin>>s;

    recur(0, 1, 0, 0, false); // 인덱스 위치, 현재까지 경우의 수, 연속해서 오고 있는 문자의 누적 수, 연속한 문자 종류(0,1), H 포함 여부부
    
    // 문자열 종류
    // 0 : 모음 (5개)
    // 1 : 자자음 (21개)
    cout<<ans;
    
    return 0;
}