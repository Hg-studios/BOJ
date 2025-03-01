#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer(n);
    
    vector<int> tmp(n,0);
    for(int i=0; i<arr1.size(); i++) {
        tmp[i] |= arr1[i];
        tmp[i] |= arr2[i];
    }
    
    for(int i=0; i<tmp.size(); i++) {
        for(int j=0; j<n; j++) {
            // 결과가 2의 거듭제곱일 수 있기 때문에 !! 0이 아닌지로 확인
            if((tmp[i]&(1<<j))==0) answer[i]+=' ';
            else answer[i]+='#';
        }
        reverse(answer[i].begin(), answer[i].end());
    }
    
    return answer;
}