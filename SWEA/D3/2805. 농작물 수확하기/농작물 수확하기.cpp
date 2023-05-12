
#include<iostream>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;
	
	cin>>T;
	/*
	   여러 개의 테스트 케이스가 주어지므로, 각각을 처리합니다.
	*/
	for(test_case = 1; test_case <= T; ++test_case)
	{
        int arr[50][50];
		int n; cin>>n;
        
        for(int i=0; i<n; i++){
        	for(int j=0; j<n; j++){
            	scanf("%1d", &arr[i][j]);
            }
        }
        
        int ans=0;
        //마름모 절반 위
        for(int i=0; i<n/2; i++){
        	for(int j=n/2-i; j<=n/2+i; j++){
                ans+=arr[i][j];
            	//if(test_case==1) cout<<i<<" "<<j<<'\n';
            }
        }
        //마름모 절반 아래
        for(int i=0; i<=n/2; i++){
        	for(int j=i; j<n-i; j++){
                ans+=arr[i+n/2][j];
            	//if(test_case==1) cout<<i+n/2<<" "<<j<<'\n';
            }
        }
        cout<<"#"<<test_case<<" "<<ans<<'\n';

	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}