#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n,m;
int a[500005];
vector<int> v, ans;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>n>>m;
    while(n--) {
        int x; cin>>x;
        v.push_back(x);
    }
    sort(v.begin(), v.end());

    for(int i=0; i<m; i++){
        cin>>a[i];
    }
    sort(a,a+m);

    for(int i=0; i<v.size(); i++){
        if(!binary_search(a,a+m,v[i])){
            ans.push_back(v[i]);
        } 
    }

    cout<<ans.size()<<'\n';
    for(auto i : ans) cout<<i<<" ";
}