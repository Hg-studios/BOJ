#include <iostream>
#include <algorithm>
using namespace std;

#define MAX 100
int ans;
char map[102][102];

void check_garo(int x, int y, int len){
	int sx = x; int sy = y; //왼쪽글자
    int ex = x; int ey = y+len-1; //오른쪽글자
    bool flag=0;
    
    while(1){
    	if(sy>ey) {
        	flag=1;
            break;
        }
        if(map[sx][sy]==map[ex][ey]){
        	sy++;
            ey--;
        }
        else break;
    }
    if(flag) ans = max(ans, len);
}

void check_sero(int x, int y, int len){
	int sx=x; int sy=y; //위쪽글자
    int ex=x+len-1; int ey=y; //아랫쪽글자
    bool flag=0;
    
    while(1){
    	if(sx>ex){
        	flag=1;
            break;
        }
        if(map[sx][sy]==map[ex][ey]){
        	sx++;
            ex--;
        }
        else break;
    }
    if(flag) ans = max(ans, len);
}

int main(int argc, char** argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
	int test_case;
	int T=10;
	
	for(test_case = 1; test_case <= T; ++test_case)
	{
        int tc; cin>>tc;
        ans=1;
        for(int i=0; i<MAX; i++){
        	for(int j=0; j<MAX; j++){
            	cin>>map[i][j];
            }
        }
        
        for(int i=0; i<MAX; i++){
        	for(int j=0; j<MAX; j++){
            	for(int k=2; k<MAX; k++){
                	if(j+k<=MAX) check_garo(i,j,k);
                    if(i+k<=MAX) check_sero(i,j,k);
                }
            }
        }
        
        cout<<"#"<<test_case<<" "<<ans<<'\n';
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}