#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

#define ll long long 

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    if (!(cin >> T)) return 0;
    while (T--) {
        int N;
        cin >> N;
        vector<int> price(N);
        for (int i = 0; i < N; ++i) cin >> price[i];

        long long profit = 0;
        int max_future = 0; // 뒤에서부터 보며 이후 최대값 저장
        for (int i = N - 1; i >= 0; --i) {
            if (price[i] > max_future) {
                max_future = price[i];          // 더 비싸면 그 날을 새로운 매도가로
            } else {
                profit += (long long)(max_future - price[i]); // 싸면 그 날 사서 max에 판다고 가정
            }
        }
        cout << profit << '\n';
    }
    return 0;
}