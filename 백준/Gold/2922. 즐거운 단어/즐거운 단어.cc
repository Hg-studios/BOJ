#include <iostream>
#include <vector>
using namespace std;

#define ll long long 

string s;
ll ans;

void recur(int idx, ll cnt, int mo, int ja, bool inc) {
    if(idx==s.size()) { // 문자열 끝까지 온 상황 
        // H가 없다면 답이 될 수 없음 
        if(inc) ans += cnt; // 최종적으로 답으로 더해줌 
        
        return;
    }
    
    if(s[idx]=='_') {
        // 빈칸에 알파벳을 넣어줌
        
        // 1. 모음을 넣을 수 있는 경우 
        // 모음이 2개 이상일 때 빼고 가능
        bool mo_avil = true;
        if(mo>=2) mo_avil = false;
        // 어차피 모음이 1개였거나 자음이었거나 모음+1이 되는 건 똑같음 
        if(mo_avil) recur(idx+1, cnt*5, mo+1, 0, inc);
        
        // 2. 자음을 넣을 수 있는 경우 
        bool ja_avil = true;
        if(ja>=2) ja_avil = false;
        if(ja_avil) {
            // L을 넣는 경우
            recur(idx+1, cnt, 0, ja+1, true);
            recur(idx+1, cnt*20, 0, ja+1, inc);
        }
    }
    
    // 알파벳이 온 상황
    else {
        char c = s[idx];
        
        // 현재 알파벳이 모음인 경우
        if(c=='A' || c=='E' || c=='I' || c=='O' || c=='U') {
            if(mo==2) return;
            recur(idx+1, cnt, mo+1, 0, inc);
        }
        // 자음인 경우
        else {
            if(ja==2) return;
            if(c=='L') recur(idx+1, cnt, 0, ja+1, true);
            else recur(idx+1, cnt, 0, ja+1, inc);
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(nullptr); cout.tie(nullptr);
    
    cin>>s;

    recur(0, 1, 0, 0, false); // 인덱스 위치, 현재까지 경우의 수, 연속한 모음 개수, 연속한 자음 개수, H 포함 여부

    // 문자열 종류
    // 0 : 자음 (5개)
    // 1 : 모음 (21개)
    cout<<ans;
    
    return 0;
}