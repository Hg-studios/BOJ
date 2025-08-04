/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

string t;
int n;
vector<int> price;
vector<string> book;
// cnt1 : t의 각 알파벳 개수 저장하는 배열, cnt2 : recur 함수에서 현재까지 추가된 알파벳 개수 저장하는 배열 
vector<int> cnt1(26), cnt2(26);
int ans = INT_MAX;

void recur(int depth, int sum) {
    if(depth==n) {
        bool flag = true;
        
        for(char c: t) {
            if(cnt1[c-'A']>cnt2[c-'A']) {
                flag = false;
                break;
            }
        }
        
        if(flag) {
            if(ans>sum) ans = sum;
        }
        
        return;
    }
    
    
    // 1) 현재 책을 추가하지 않는 경우 
    recur(depth+1, sum);
    
    // 2) 현재 책을 추가하는 경우
    // 현재 책을 추가
    for(char c : book[depth]) cnt2[c-'A']++;
    recur(depth+1, sum+price[depth]);
    // 현재 책 빼기
    for(char c : book[depth]) cnt2[c-'A']--;
}


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(nullptr); cout.tie(nullptr);
    
    cin>>t;
    cin>>n;
    
    price.resize(n); 
    book.resize(n);
    
    for(int i=0; i<t.size(); i++) {
        cnt1[t[i]-'A']++;
    }
    
    for(int i=0; i<n; i++) {
        cin>>price[i]>>book[i];
        // cout<<price[i]<<book[i]<<'\n';
    }
    
    // 현재 책을 추가하거나 혹은 추가하지 않거나 
    recur(0,0);
    
    cout<<(ans==INT_MAX ? -1 : ans);
    
    return 0;
}