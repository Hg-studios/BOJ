#include <iostream>
#include <string>
using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T; cin>>T;
	
	for(test_case = 1; test_case <= T; ++test_case)
	{
        string tmp;
        string str; cin>>str;
        for(int i=0; i<str.size(); i++) tmp+='0'; 
        
        int cnt=0;
        while(tmp!=str){
        	cnt++;
            int st;
            for(int i=0; i<str.size(); i++){
                if(str[i]!=tmp[i]){ //str와 start에서 다른 부분이 있다면 
                	st=i; //그 부분부터 바꿔줌
                    break;
                }
            }
            for(int i=st; i<str.size(); i++){
            	tmp[i]=str[st];
            }
        }
        cout<<"#"<<test_case<<" "<<cnt<<'\n';
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}