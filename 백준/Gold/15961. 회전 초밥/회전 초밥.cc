#include <iostream>
#include <vector>
#include <limits.h>
#include <unordered_map>
using namespace std;
#define ll long long

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr); cout.tie(nullptr);
    
    int n, d, k, c;  cin>>n>>d>>k>>c;

    vector<int> v(n);
    for(int i=0; i<n; i++) cin>>v[i];
    
    unordered_map<int, int> m; //초밥 종류, 개수
    
    int kind=0;
    
    // 초밥 k-1개를 넣어둠
    for(int i=0; i<k-1; i++) {
        if(m[v[i]]==0) kind++;
        m[v[i]]++;
    }
    
    //쿠폰도 넣기
    if(m[c]==0) kind++;
    m[c]++;
    
    int mx = -1;
    // k번째부터 최대값을 구해주기
    // i가 k까지인줄 알았으나 초밥판은 순환하기 때문에 총 n번을 돌아야 함
    // 매번 이런 슬라이딩 윈도우는 인덱스때문에 시간이 너무 많이 걸렸는데 그냥 for문의 인덱스와 내부에서 쓰는 인덱스를 따로 두자!
    
    int start=0, end=k-1; //둘은 인덱스를 의미
    for(int i=0; i<n; i++) { //n번을 돌자 -> 그냥 n번을 카운팅하기 위해서만 사용함 
        // end에 해당하는 초밥은 추가해줌 
        int tmp = v[end%n];
        if(m[tmp]==0) kind++;
        m[tmp]++;
        
        if(kind>mx) mx = kind;
        
        //start에 해당하는 초밥은 삭제함
        tmp = v[start%n];
        m[tmp]--;
        if(m[tmp]==0) kind--;
        
        start++;
        end++;
    }
    
    cout<<mx;

    return 0;
}