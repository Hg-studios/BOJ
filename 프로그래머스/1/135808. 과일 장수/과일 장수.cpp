#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <limits.h>

using namespace std;

int solution(int k, int m, vector<int> score) {
    int answer = 0;
    
    sort(score.begin(), score.end(), greater<>());
    
    for(int i=0; i<score.size()/m; i++) {
        int mn=INT_MAX;
        for(int j=i*m; j<i*m+m; j++) {
            if(mn>score[j]) mn=score[j];
        }
        answer += mn * m;
    }
    
    return answer;
}