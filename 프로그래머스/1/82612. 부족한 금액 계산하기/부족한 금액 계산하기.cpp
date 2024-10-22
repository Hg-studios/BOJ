using namespace std;

long long solution(int price, int money, int count)
{
    long long sum=0;
    
    for(long long i=1; i<=count; i++) {
        sum += price*i;
    }
    
    if(sum <= money) return 0;
    else return sum-money;
}