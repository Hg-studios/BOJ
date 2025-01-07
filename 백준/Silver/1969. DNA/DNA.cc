#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

int main()
{
    int n, m; cin>>n>>m;
    
    vector<string> v(n);
    for(int i=0; i<n; i++) {
        cin>>v[i];
    }
    
    string ans;
    int sum=0;
    for(int j=0; j<m; j++) {
        // int arr[4] = {0,0,0,0};
        vector<int> arr(4,0);
        for(int i=0; i<n; i++) {
            if(v[i][j]=='A') arr[0]++;
            else if(v[i][j]=='C') arr[1]++;
            else if(v[i][j]=='G') arr[2]++;
            else arr[3]++;
        }
        sum+=(n-*max_element(arr.begin(), arr.end()));
        
        int result = max_element(arr.begin(), arr.end()) - arr.begin();
        if(result==0) ans+="A";
        else if(result==1) ans+="C";
        else if(result==2) ans+="G";
        else ans+="T";
    }
    
    cout<<ans<<'\n';
    cout<<sum;
    return 0;
}