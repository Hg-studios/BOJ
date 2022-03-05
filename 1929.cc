#include <iostream>
using namespace std;

int main(){ 
  //소수인지 아닌지를 확인하는 코드로 이 문제를 풀게 되면 O(nlgn)이 되어서 그닥 효율적이지 못함
  //따라서, 어떤 범위 안에서 모든 소수를 구하는 문제라면 '에라토스테네스의 체'를 이용함! O(NloglogN)
  int prime[1000000]; //소수 저장할 배열
  int pn =0; //소수의 개수
  bool check[1000001]; //지워졌으면 true, 소수 그대로가 인덱스가 되어서 값이 들어가기 때문에 prime보다 +1임
  
  int m,n; //m부터 n까지의 소수
  cin >> m >> n;

  for(int i=2; i<=n; i++){ 
    if(check[i] == false){ //i의 배수들을 모두 지워줌, 자기 자신은 지우지 않음
      prime[pn++] = i;
      for(int j=i*2; j<=n; j+=i){
        check[j] = true;
      }
    }
  }
  
  for(int i=0; i<n; i++){
    //일단 n까지의 소수를 다 구해놓은 것이고
    //이제는 m이상인 애들만 출력을 하면 됨 
    if(prime[i]>=m)cout << prime[i] << '\n'; 
  }
  
  return 0;
}