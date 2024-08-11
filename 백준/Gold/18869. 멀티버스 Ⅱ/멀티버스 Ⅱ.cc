#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define MAX 101

int m,n;
vector<int> v[MAX];
int arr[MAX][10001];
bool check[MAX];

bool compare(int a[], int b[]) {
    for(int k=0; k<n; k++) 
        if(a[k]!=b[k]) return false;
    
    return true;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr); cout.tie(nullptr);
    
    cin>>m>>n;
    
    for(int i=0; i<m; i++) {
        for(int j=0; j<n; j++) {
            cin>>arr[i][j]; //원본 저장
            v[i].push_back(arr[i][j]); //벡터에 저장
        }
    }
    
    // 각 벡터 순서 구하기
    for(int i=0; i<m; i++) {
        // 정렬
        sort(v[i].begin(), v[i].end());
        // 중복 제거
        v[i].erase(unique(v[i].begin(), v[i].end()), v[i].end());
        // 정렬, 중복제거된 v[i]를 이용하여 순서 구하기 
        for(int j=0; j<n; j++) {
            arr[i][j]=(lower_bound(v[i].begin(), v[i].end(), arr[i][j]) - v[i].begin());
        }
    }
    
    int ans=0;
    for(int i=0; i<m-1; i++) {
        for(int j=i+1; j<m; j++) {
            ans+= compare(arr[i], arr[j]);
        }
    }
    
    cout<<ans;

    return 0;
}