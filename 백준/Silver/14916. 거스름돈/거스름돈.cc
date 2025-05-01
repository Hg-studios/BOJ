#include <iostream>
#include <limits.h>
using namespace std;

int main()
{
    int n; cin>>n;
    
    if(n%5==0) {
        cout<<n/5;
        return 0;
    }
    
    int five = n/5;
    int remain = n - 5*five;
    
    // cout<<five<<" "<<remain<<" ";
    
    while(five>=0) {
        if(remain%2==0) {
            cout<<five+remain/2;
            return 0;
        }
        
        five-=1;
        remain+=5;
    }
    
    cout<<"-1";
    
    return 0;
}