#include <iostream>
using namespace std;

//n!을 구하는 문제가 아니라
//소인수분해를 해보았을 때, 2와 5의 개수만 
//알아내면 됨! 
//근데 항상 2의 배수가 5의 배수보다 개수가 많으므로
//소인수분해 했을 때 5의 개수를 알면 되고 그게 정답임
//소인수분해 했을 때 5의 개수는 그 개수를 5의 제곱수들로 나눠서 나오는 몫을 더해주면 됨
//예를 들어, 15! 이라면 1x5,2x5,3x5까지 5가 3개가 들어있고 그래서 5로 나누면 몫인 3이 정답이 됨
int main(){
  int result = 0;
  int n;
  cin >> n;

  for(int i=5; i<=n; i*=5){
    result += n/i;
  }

  cout << result << '\n';
  
  return 0;
}