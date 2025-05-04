#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define ll long long

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr); cout.tie(nullptr);
    
    int n, m; cin>>n>>m;
    
    vector<int> v1(n), v2(m);
    for(int i=0; i<n; i++) cin>>v1[i];
    for(int i=0; i<m; i++) cin>>v2[i];

    int idxn=0, idxm=0;
    while(idxn<n && idxm<m) {
        if(v1[idxn] < v2[idxm]) {
            cout<<v1[idxn]<<" ";
            idxn++;
        }
        else {
            cout<<v2[idxm]<<" ";
            idxm++;
        }
    }
    
    while(idxn<n) {
        cout<<v1[idxn]<<" ";
        idxn++;
    }
    
    while(idxm<m) {
        cout<<v2[idxm]<<" ";
        idxm++;
    }
    
    return 0;
}