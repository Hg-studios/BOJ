#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<int> wallet, vector<int> bill) {
    int answer = 0;
    
    int wallet1 = wallet[0];
    int wallet2 = wallet[1];
    int bill1 = bill[0];
    int bill2 = bill[1];
    
    while(min(bill1,bill2)>min(wallet1,wallet2) || max(bill1,bill2)>max(wallet1,wallet2)) {
        if(bill1>bill2) bill1/=2;
        else bill2/=2;
        
        answer++;
    }
    
    return answer;
}