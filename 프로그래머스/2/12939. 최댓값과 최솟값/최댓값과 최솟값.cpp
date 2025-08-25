#include <string>
#include <vector>
#include <limits.h>
#include <sstream>
#include <iostream>
using namespace std;

#define ll long long 

string solution(string s) {
    string answer = "";
    
    istringstream input;
    input.str(s);
    
    ll mx = INT_MIN;
    ll mn = INT_MAX;
    
    for(string line; getline(input,line, ' '); ) {
        ll x = stoi(line);
        
        if(x>mx) mx = x;
        if(x<mn) mn = x;
    }
    
    answer += to_string(mn);
    answer += " ";
    answer += to_string(mx);
    
    return answer;
}