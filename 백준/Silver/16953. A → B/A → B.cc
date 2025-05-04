#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define ll long long

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    
    string a, b; cin>>a>>b;
    
    int cnt=0;
    while(1) {
        if(a==b) break;
        if(stoi(b)<=0) {
            cout<<-1;
            return 0;
        }
        
        int numb = stoi(b);
        
        if(b[b.length()-1]=='1') b = to_string(numb/10);
        else if (numb%2==0) b = to_string(stoi(b)/2);
        else {
            cout<<-1;
            return 0;
        }
        cnt++;
        // cout<<b<<" ";
    }
    
    cout<<cnt+1;
    
    return 0;
}