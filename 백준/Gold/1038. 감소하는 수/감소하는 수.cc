#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define ll long long

ll n;
vector<ll> v;

void recur(string num) {
    if(num > "9876543210") return;
    
    v.push_back(stoll(num));
    
    for(int i=0; i<=num.back()-'0'-1; i++) {
        recur(num + to_string(i));
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    
    cin>>n;
    
    // i는 시작하는 수
    // i부터 시작해서 i보다 큰 수를 뒤에 붙일 것임 
    for(int i=0; i<=9; i++) {
        recur(to_string(i));
    }
    
    sort(v.begin(), v.end());
    
    if(v.size()<=n) cout<<"-1";
    else cout<<v[n];
    
    return 0;
}