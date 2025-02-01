#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main()
{
    int n; cin>>n;
    vector<double> v(n);
    for(int i=0; i<n; i++) cin>>v[i];
    
    double ans=0;
    for(int i=0; i<n; i++) {
        double result = 1;
        for(int j=i; j<n; j++) {
            result *= v[j];
            ans = max(ans, result);
        }
    }
    
    printf("%.3lf", ans);
    
    return 0;
}