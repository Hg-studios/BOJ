#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

string n; 
int k; 
vector<char> cand;
// string pick;
string ans="-1";

void recur(int cur, int depth, string result) {
    if(result.size()>=1 && stoi(n)>=stoi(result)) {
        if(stoi(ans)<stoi(result)) ans = result;
    }
    
    if(cur==depth) return;
    
    for(int i=0; i<k; i++) {
        // 현재 뽑힌 수들로 만들기
        // 이렇게 하는 이유는 답이 꼭 n.size() 길이가 되지 않을 수 있기 때문
        recur(cur+1, depth, result+cand[i]);
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(nullptr); cout.tie(nullptr);
    
    cin>>n;
    cin>>k;
    
    cand.resize(k); // 후보 숫자 저장
    for(int i=0; i<k; i++) cin>>cand[i];
    
    // 가장 큰 수부터 작은 수까지 내림차순 정렬
    sort(cand.begin(), cand.end());
    
    // pick.resize(n.size());
    
    recur(0,n.size(),"");
    
    cout<<ans;
    
    return 0;
}