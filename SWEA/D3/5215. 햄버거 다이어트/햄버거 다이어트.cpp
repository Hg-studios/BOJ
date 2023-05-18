#include <iostream>
#include <algorithm>
using namespace std;

int taste[22];
int kal[22];
int dp[22][10002]; //dp[a][b]=c : a번째 재료까지 왔고 b칼로리일 때 점수가 c임
int main(int argc, char** argv)
{
	int test_case;
	int T; cin>>T;
	
	for(test_case = 1; test_case <= T; ++test_case)
	{
        //초기화
        for(int i=0; i<22; i++){
        	for(int j=0; j<10002; j++){
            	dp[i][j]=0;
            }
        }
        //입력받기
        int n, l; cin>>n>>l;
        for(int i=1; i<=n; i++){
        	cin>>taste[i]>>kal[i];
        }
        
        //dp테이블채우기
        for(int i=1; i<=n; i++){ //n개의 재료를 살펴볼 것임
        	for(int j=1; j<=l; j++){ //칼로리 1~k를 만들 것임
            	//i번째 재료로 칼로리j를 만들 수 있다면
                //i번째 재료가 들어가는 경우와 그렇지 않은 경우 중 큰 맛점수를 택함
                //i번째 재료가 들어간다면 i-1까지의 재료를 가지고 j-kal[i]만큼의 칼로리를 
                //만들었을 때의 맛점수에다가 i번째 맛점수를 더해주면 됨
                if(kal[i]<=j) dp[i][j] = max(dp[i-1][j], dp[i-1][j-kal[i]]+taste[i]);
                //i번째 재료로 칼로리j를 만들 수 없다면
                //i-1번째 재료로 칼로리 j를 만들었을 때의 맛점수와 같음
                else dp[i][j] = dp[i-1][j];
            }
        }
        cout<<"#"<<test_case<<" "<<dp[n][l]<<'\n';
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}