#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define X first
#define Y second 

int main()
{
    int n, m; cin>>n>>m;
    string a,b; cin>>a>>b;
    int t; cin>>t;
    
    reverse(a.begin(), a.end());

    vector<pair<char, int>> vec;
    for(int i=0; i<a.size(); i++) vec.push_back({a[i], 1});
    for(int i=0; i<b.size(); i++) vec.push_back({b[i], 2});
    
    while(t--) {
        for(int i=0; i<vec.size()-1; i++) {
            if(vec[i].Y==vec[i+1].Y) continue;
            else {
                if(vec[i].Y==1) { //오른쪽으로 이동하는 개미이면 
                    char tmpC = vec[i].X;
                    int tmpD = vec[i].Y;
                    vec[i].X = vec[i+1].X;
                    vec[i].Y = vec[i+1].Y;
                    vec[i+1] = {tmpC, tmpD};
                    i++; // 이거 중요함 ***
                }
            }
        }
    }
    
    for(int i=0; i<vec.size(); i++) cout<<vec[i].X;
    
    return 0;
}