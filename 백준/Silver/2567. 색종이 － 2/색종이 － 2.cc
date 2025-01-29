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
            // 상하좌우가 색이 변하는지 확인
            if(arr[i][j]) {
                if(i==0 || !arr[i-1][j]) ans++;
                if(i==99 || !arr[i+1][j]) ans++;
                if(j==0 || !arr[i][j-1]) ans++;
                if(j==99 || !arr[i][j+1]) ans++;
            }
        }
        // cout<<'\n';
    }
    
    cout<<ans;
    return 0;
}