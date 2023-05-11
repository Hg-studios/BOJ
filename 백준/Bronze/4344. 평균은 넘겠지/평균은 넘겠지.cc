#include <iostream>
using namespace std;

int arr[1002];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int c;
    cin>>c; 

    while(c--){
        int n; cin>>n;
        int score=0;
        for(int i=0; i<n; i++) {
            cin>>arr[i];
            score+=arr[i];
        }
        double avg = score/n;
        int cnt=0;
        for(int i=0; i<n; i++){
            if(arr[i]>avg) cnt++;
        }
        cout<<fixed;
        cout.precision(3);
        cout<<cnt*100.0/n<<"%"<<'\n';
    }
}