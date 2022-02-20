#include <iostream>
#include <string>
using namespace std;

int main()
{
    int n;
    cin>>n;
    
    char turn; //가장 최근에 검사한 char
    int count=0; //그룹 체커 단어 개수
    
    for(int i=0; i<n; i++){
        string word;
        cin>>word; //n번에 걸쳐서 단어를 입력받음
        int count_wrong=0; //그룹단어를 아니게 만든 알파벳 개수 
        
        for(int j=0; j<word.length(); j++){
		//첫번째 char은 할 게 없음
            if(j!=0){ //두번째 char부터
                if(turn!=word[j]){ //바로 이전 거랑 다르면 앞에 나왔던 애들을 쭉 검사해야 함
                    for(int k=0; k<j; k++){
                        if(word[j]==word[k]){ //앞에 나왔던 거랑 같게 되면 그룹단어가 아님
                            count_wrong++;
                        }
                    }
                }
            }
            turn = word[j]; //모든 경우든 turn은 가장 최근에 검사한 char로 업데이트해줌
        }
        if(count_wrong!=0) count++; //count_wrong이 0보다 크면 그룹단어가 아님 
    }
    cout<<(n-count)<<'\n';
}