#include <iostream>
#include <vector>
using namespace std;

vector<string> v;

void recur(int x, int y, int n) {
    if(n<=1) {
        cout<<v[x][y];
        return;
    }
    
    // 일단 현재 모든 칸이 하나의 수로 이뤄져있는지 체크
    char tmp = v[x][y];
    bool same = true;
    for(int i=x; i<x+n; i++) {
        for(int j=y; j<y+n; j++) {
            if(v[i][j]!=tmp) {
                same = false;
                break;
            }
        }
    }
    
    // 모든 칸이 다 같은 수라면 바로 출력!
    if(same) {
        cout<<tmp;
        return;
    }
    
    // 만약에 다른 수라면, 4사분면으로 쪼개서 검사해야됨
    cout<<'(';
    recur(x, y, n/2);
    recur(x, y+n/2, n/2);
    recur(x+n/2, y, n/2);
    recur(x+n/2, y+n/2, n/2);
    cout<<')';
    
}

int main()
{
    int n; cin>>n;
    
    v.resize(n);
    for(int i=0; i<n; i++) cin>>v[i];
    
    recur(0,0,n);
    
    return 0;
}