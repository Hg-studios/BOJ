#include <iostream>
using namespace std;

int main(){
    int n,sum=0;
    cin>>n;
    for(int i=0; i<n; i++){
        int x; scanf("%1d", &x);
        sum+=x;
    }
    cout<<sum;
}