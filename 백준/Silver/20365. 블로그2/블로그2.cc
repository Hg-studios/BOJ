#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
using namespace std;

#define ll long long

int main()
{
    int n; cin>>n;
    string s; cin>>s;
    
    int red=0, blue=0;
    char cur = 'G';
    for(int i=0; i<s.length(); i++) {
        if(s[i]=='R') { // 빨간색일 때
            if(cur!=s[i]) { //전에 칸이랑 다른 색이면 새롭게 칠해줘야 함 
                red++;
                cur = s[i];
            }
        }
        else {
            if(cur!=s[i]) {
                blue++;
                cur = s[i];
            }
        }
    }
    
    cout<<min(red, blue)+1;
    
    return 0;
}