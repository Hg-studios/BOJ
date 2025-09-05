#include <string>
#include <vector>
#include <map>
#include <iostream>
using namespace std;

int solution(vector<vector<string>> clothes) {
    map<string, int> m;
    
    for(auto cloth : clothes) {
            m[cloth[1]]++;
    }
    
    int tmp = 1;
    for(auto x : m) tmp *= (x.second+1);
    // for(auto x : m) cout<<x.first<<" "<<x.second<<'\n';
    
    return tmp-1;
}