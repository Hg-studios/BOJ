#include <iostream>
#include <algorithm>
using namespace std;

int n,m;
int arr[100005];
int mn=0x7fffffff;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>n>>m;
    for(int i=0; i<n; i++) cin>>arr[i];
    sort(arr,arr+n);

    int st=0, en=0;
    while(en<n){
        if(arr[en]-arr[st]<m) en++;
        else{
            mn= min(mn, arr[en]-arr[st]);
            st++; 
        }
    }
    cout<<mn;
}