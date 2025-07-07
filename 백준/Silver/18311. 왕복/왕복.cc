#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    long long k;  
    cin >> n >> k;

    vector<long long> tmp(n), forward(n), backward(n);

    for (int i = 0; i < n; i++)
        cin >> tmp[i];

    // 앞으로 가는 구간 누적합
    forward[0] = tmp[0];
    for (int i = 1; i < n; i++)
        forward[i] = forward[i - 1] + tmp[i];

    // 뒤로 돌아오는 구간 누적합 (tmp 뒤집어서 계산)
    reverse(tmp.begin(), tmp.end());
    backward[0] = tmp[0];
    for (int i = 1; i < n; i++)
        backward[i] = backward[i - 1] + tmp[i];

    // 아직 편도 다 못 갔을 때
    if (k <= forward[n - 1]) {
        for (int i = 0; i < n; i++) {
            if (forward[i] > k) {
                cout << (i + 1);
                return 0;
            }
        }
        // 딱 마지막 구간 경계에 있다면 N번 코스
        cout << n;
    }
    // 돌아오는 구간
    else {
        long long x = k - forward[n - 1];
        for (int i = 0; i < n; i++) {
            if (backward[i] > x) {
                // 뒤집힌 인덱스를 원래 코스 번호로
                cout << (n - i);
                return 0;
            }
        }
    }

    return 0;
}
