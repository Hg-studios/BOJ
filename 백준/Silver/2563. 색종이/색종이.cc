/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
using namespace std;

bool arr[101][101];

int main()
{
    int n; cin>>n;
    
    while(n--) {
        int c,r; cin>>c>>r;
        for(int i=r; i<r+10; i++) {
            for(int j=c; j<c+10; j++) {
                arr[i][j]=true;
            }
        }
    }
    
    int ans=0;
    for(int i=0; i<100; i++) {
        for(int j=0; j<100; j++) {
            if(arr[i][j]) {
                ans++;
                // cout<<"#";
            }
            // else cout<<".";
        }
        // cout<<'\n';
    }
    
    cout<<ans;
    return 0;
}