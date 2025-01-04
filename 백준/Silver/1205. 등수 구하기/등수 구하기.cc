#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int curNum, taesuScore, maxNum;
vector<int> scores;
int main()
{
    cin>>curNum>>taesuScore>>maxNum;
    
    scores.resize(curNum);
    for(int i=0; i<curNum; i++) {
        cin>>scores[i];
    }
    
    if(curNum==maxNum && (scores[curNum-1]>=taesuScore)) { //현재 꽉 채워져 있는데 마지막 요소보다 작으면 -1
        cout<<-1;
    }
    else { // 그 이외의 경우에는 몇 등인지 확인하기
        scores.push_back(taesuScore);
        sort(scores.begin(), scores.end(), greater<int>());
        
        int cnt=1;
        for(int x : scores) {
            if(x==taesuScore) break;
            cnt++;
        }
        cout<<cnt<<'\n';
    }
    return 0;
}