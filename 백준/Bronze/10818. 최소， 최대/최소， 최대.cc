#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> v;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n; cin>>n;
    while(n--){
        int x; cin>>x;
        v.push_back(x);
    }

    cout<<*min_element(v.begin(),v.end())<<" "<<*max_element(v.begin(), v.end());

    return 0;
}