#include<iostream>
#include <vector>
using namespace std;

int arr[102][102];

int main(int argc, char** argv)
{
	int test_case;
	int T = 10;
	for(test_case = 1; test_case <= T; ++test_case)
	{
        int n; cin>>n;
        for(int i=0; i<n; i++){
        	for(int j=0; j<n; j++){
            	cin>>arr[i][j];
            }
        }
        
        int cnt=0;
        for(int i=0; i<n; i++){
            int npole=0;
        	for(int j=0; j<n; j++){
                if(arr[j][i]==2&&npole==1){
                    cnt++;
                    npole=0;
                }
                else if(arr[j][i]==1) npole=1;
            }
        }
		cout<<"#"<<test_case<<" "<<cnt<<'\n';

	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}