#include <iostream>
#include <vector>
#include <cmath>
#include <limits.h>
using namespace std;

vector<int> dp;

int recur(int n) {
    if (n == 0) return 0;
    if (dp[n] != -1) return dp[n];

    int mn = INT_MAX;
    for (int i = 1; i*i <= n; i++) {
        mn = min(mn, recur(n - i*i) + 1);
    }

    dp[n] = mn;
    return mn;
}

int main()
{
    int n; cin >> n;

    dp.resize(n + 1, -1);
    cout << recur(n);

    return 0;
}
