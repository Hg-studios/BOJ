#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    
    string x; cin>>x;
    
    int cnt=0;
    string answer="0";
    do {
        cnt++;
        
        if(cnt==2) answer=x;
    } while(next_permutation(x.begin(), x.end()));
    
    cout<<answer;
}