#include <iostream>
#include <vector>
#include <map>
using namespace std;

#define R first
#define C second

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(nullptr); cout.tie(nullptr);
    
    map<char, pair<int,int>> m;
    m['q'] = {1, 1};
    m['w'] = {1, 2};
    m['e'] = {1, 3};
    m['r'] = {1, 4};
    m['t'] = {1, 5};
    m['y'] = {1, 6};
    m['u'] = {1, 7};
    m['i'] = {1, 8};
    m['o'] = {1, 9};
    m['p'] = {1, 10};
    
    m['a'] = {2, 1};
    m['s'] = {2, 2};
    m['d'] = {2, 3};
    m['f'] = {2, 4};
    m['g'] = {2, 5};
    m['h'] = {2, 6};
    m['j'] = {2, 7};
    m['k'] = {2, 8};
    m['l'] = {2, 9};
    
    m['z'] = {3, 1};
    m['x'] = {3, 2};
    m['c'] = {3, 3};
    m['v'] = {3, 4};
    m['b'] = {3, 5};
    m['n'] = {3, 6};
    m['m'] = {3, 7};
    
    char sl, sr; cin>>sl>>sr;
    
    pair<int, int> l, r;
    l = m[sl];
    r = m[sr];
    
    int ans=0;
    string s; cin>>s;
    for(int i=0; i<s.size(); i++) {
        pair<int, int> p = m[s[i]];
        
        int dis=0;
        
        // 모음인 경우
        if((p.R==1 && p.C>=6) || (p.R==2 && p.C>=6) || (p.R==3 && p.C>=5)) {
            // 오른손 손가락 움직이기
            dis = abs(r.R - p.R) + abs(r.C - p.C);
            ans += dis; 
            r = p;
        }
        // 자음인 경우
        else {
            // 왼손 손가락 움직이기
            dis = abs(l.R - p.R) + abs(l.C - p.C);
            ans += dis;
            l = p;
        }
        // 움직이고 나서 누르는 데에도 1초 걸린
        ans++;
    }
    
    cout<<ans;
    
    
    return 0;
}