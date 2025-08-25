#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> A, vector<int> B)
{
    sort(A.begin(), A.end());
    sort(B.begin(), B.end(), greater<>());
    
    int sum=0;
    for(int i=0; i<A.size(); i++) {
        sum += (A[i] * B[i]);
    }

    return sum;
}