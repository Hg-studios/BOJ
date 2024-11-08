#include <string>
#include <vector>
#include <map>
#include <iostream>
using namespace std;

string solution(vector<string> survey, vector<int> choices) {
    string answer = "";
    
    map<char,int> m;
    
    for(int i=0; i<survey.size(); i++) {
        int s = choices[i];
        
        if(s<=3) { 
            s = 4-s;
            m[survey[i][0]] += s;
        }
        else if(s>=5) {
            s = s-4;
            m[survey[i][1]] += s;
        }
    }
    
    // for(auto x : m) {
    //     cout<<x.first<< " "<<x.second<<'\n';
    // }
    
    if(m['R']>=m['T']) answer+="R";
    else answer+="T";
    
    if(m['C']>=m['F']) answer+="C";
    else answer+="F";
    
    if(m['J']>=m['M']) answer+="J";
    else answer+="M";
    
    if(m['A']>=m['N']) answer+="A";
    else answer+="N";
    
    return answer;
}