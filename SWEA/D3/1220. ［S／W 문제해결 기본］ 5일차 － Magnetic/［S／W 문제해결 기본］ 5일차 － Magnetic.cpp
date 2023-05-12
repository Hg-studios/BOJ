#include<iostream>
using namespace std;

int arr[102][102];

int main(int argc, char** argv)
{
	int test_case;
	int T = 10;
	for(test_case = 1; test_case <= T; ++test_case)
	{
        int n; cin>>n;
        for(int i=0; i<100; i++){
        	for(int j=0; j<100; j++){
            	cin>>arr[i][j];
            }
        }
        int cnt=0;
        for(int i=0; i<100; i++){
        	for(int j=0; j<99; j++){
                for(int k=j+1; k<100; k++){
                    //이미 짝이 세어진 N극은 세지 않고 넘어감
                    if(arr[j][i]==1&&arr[k][i]==-1) break;
                    //아직 짝이 세어지지 않아서 세어줘야함
                	if(arr[j][i]==1&&arr[k][i]==2) {
                        cnt++;
                        arr[k][i]=-1; //이미셌으니 중복으로 세지 않도록 값을 바꿔줌
                        break;
                    }
                    
                }
            	
            }
        }
		cout<<"#"<<test_case<<" "<<cnt<<'\n';

	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}