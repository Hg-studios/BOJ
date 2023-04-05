#include <iostream>
#include <algorithm>
using namespace std;

int l, c, cnt;
char arr[18];
int choose[18];
char mo[5]={'a','e','i','o','u'};

bool check(){
    int cnt=0; //모음개수 카운트

    for(int i=0; i<c; i++){
        for(int j=0; j<5; j++){
            //예제1로 보면 6개 중 선택된 4개만 모음하고 비교하기
            if(choose[i]==0){
                if(arr[i]==mo[j]) cnt++;
            }
        }
    }
    if(cnt>=1 && l-cnt>=2) return 1; //모음 1개, 자음 2개 이상일 때만 참
    return 0;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    //next_permutation함수로 6개 중 4개를 뽑는 조합을 만듦
    //그 중에서 모음 최소 한 개, 자음 최소 두 개인지 조건 체크한 후 cnt++
    cin>>l>>c;
    for(int i=0; i<c; i++) cin>>arr[i];
    
    //choose배열 전부 1로 초기화하고 앞에서부터 L개만 0으로 채움
    for(int i=0; i<18; i++) choose[i]=1;
    for(int i=0; i<l; i++) choose[i]=0;

    //정렬하기
    sort(arr, arr+c);

    do
    {
        if(check()){ //모음,자음 조건이 맞다면
            for(int i=0; i<c; i++){
                if(choose[i]==0) {
                    cout<<arr[i];
                }
            }
            cout<<'\n';
        }
    } while (next_permutation(choose,choose+c));
    
}