#include <iostream>
#include <algorithm>
using namespace std;

double s[1002], avg;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n; cin>>n;
    for(int i=0; i<n; i++) {
        cin>>s[i];
    }
    double mx = *max_element(s,s+n);

    for(int i=0; i<n; i++) {
        s[i]=s[i]/mx*100;
        avg+=s[i];
    }

    cout<<avg/n;

}