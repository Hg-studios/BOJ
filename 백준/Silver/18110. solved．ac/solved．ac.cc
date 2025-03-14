#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

int main()
{
    int n; cin>>n;
    
    vector<int> v(n);
    for(int i=0; i<n; i++) {
        cin>>v[i];
    }
    
    sort(v.begin(), v.end());
    
    // cout<<ceil(v.size()*0.15);
    
    int start = round(v.size()*0.15);
    // cout<<start<<'\n';
    
    if(n==0) {
        cout<<"0";
    }
    else {
        int sum = 0;
        for(int i=start; i<v.size()-start; i++) {
            sum += v[i];
        }
        
        double result = (double)sum / (v.size()-start*2);
        
        cout<<round(result);
    }
    
    return 0;
}


// 0 1 2 3 4

// start = 1

// 0 1 2 3 4 5 ... 20 21 22 23 24

// start = 4

// 0
// start = 0