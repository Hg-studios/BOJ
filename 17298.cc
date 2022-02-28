#include <iostream>
#include <string>
using namespace std;

int main(){
  int arr[1000000];
  
  int n;
  cin >> n;
  
  for(int i=0; i<n; i++){ //n개만큼 수를 저장함 
    cin >> arr[i];
  }
  
  for(int i=0; i<n; i++){ //하나씩 값을 찾음 
    for(int j=i+1; j<n; j++){ //i번째일 때 i+1부터 찾아야 하므로 
      if(arr[i] < arr[j]){
        if(i!=0) cout << " "; //처음이 아닐때만 빈칸 출력
        cout << arr[j]; //값을 찾았으니 출력
        break; //찾았으니 빠져나옴
      }
      if(j==n-1) cout << -1; //만약 마지막까지 못찾았다면 -1을 출력해야함
    }
    
  }

  cout << " " << -1 << '\n'; //마지막거는 비교할 게 없으니 무조건 -1임
  return 0;
}