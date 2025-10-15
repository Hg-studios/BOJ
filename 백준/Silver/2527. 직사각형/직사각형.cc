#include <iostream>
using namespace std;

int main()
{
    int tc=4;
    while(tc--) {
        int x1,y1,x2,y2,x3,y3,x4,y4; cin>>x1>>y1>>x2>>y2>>x3>>y3>>x4>>y4;
        
        if(x2<x3 || x4<x1 || y2<y3 || y4<y1) cout<<"d"<<'\n';
        else if((x1==x4 && (y2==y3||y1==y4)) || (x2==x3&&(y2==y3||y1==y4))) cout<<"c"<<'\n';
        else if((x3<x2 && x1<x4) && (y1==y4 || y2==y3)) cout<<"b"<<'\n';
        else if((y1<y4 && y3<y2) && (x1==x4 || x2==x3)) cout<<"b"<<'\n';
        else cout<<"a"<<'\n';
    }
    
    return 0;
}