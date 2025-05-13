#include <iostream>
#include <regex>
using namespace std;

bool isSlump(string s) {
    regex re1("([DE]F+)+G");
    return regex_match(s, re1);
}

bool isSlimp(string s) {
    // A로 시작, H나 C로 끝남 
    
    if(s[0]!='A' || s.length()<2) return false;
    
    if(s.length()==2) {
        if(s[1]=='H') return true;
        else return false;
    }
    
    if(s[s.length()-1]!='C') return false;
    
    if(s[1]=='B') {
        string tmp1 = s.substr(2, s.length()-3);
        return isSlimp(tmp1);
    }
    else {
        string tmp2 = s.substr(1, s.length()-2);
        return isSlump(tmp2);
    }
    
    return false;
}


bool isSlurpy(string s) {
    for(int i=0; i<s.size(); i++) {
        string s1 = s.substr(0, i); //0부터 i개만큼 
        string s2 = s.substr(i); //i부터 끝까지
        
        if(isSlimp(s1) && isSlump(s2)) return true;
    }
    return false;
}

int main()
{
    int n; cin>>n;
    
    cout<<"SLURPYS OUTPUT\n";
    while(n--) {
        string s; cin>>s;
        
        if(isSlurpy(s)) cout<<"YES\n";
        else cout<<"NO\n";
    }
    cout<<"END OF OUTPUT\n";
    
    return 0;
}