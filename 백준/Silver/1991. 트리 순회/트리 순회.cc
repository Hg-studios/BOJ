#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

#define X first
#define Y second

vector<pair<char,char>> arr(26);

void preorder(char cur) {
    if(cur=='.') return;
    
    cout<<cur;
    preorder(arr[cur-'A'].X);
    preorder(arr[cur-'A'].Y);
}

void inorder(char cur) {
    if(cur=='.') return;
    
    inorder(arr[cur-'A'].X);
    cout<<cur;
    inorder(arr[cur-'A'].Y);
}

void postorder(char cur) {
    if(cur=='.') return;
    
    postorder(arr[cur-'A'].X);
    postorder(arr[cur-'A'].Y);
    cout<<cur;
}

int main()
{
    int n; cin>>n;
    
    for(int i=1; i<=n; i++) {
        char x,y,z; cin>>x>>y>>z;
        
        arr[x-'A'].X = y;
        arr[x-'A'].Y = z;
    }
    
    preorder('A');
    cout<<'\n';
    inorder('A');
    cout<<'\n';
    postorder('A');
    cout<<'\n';
    
    return 0;
}