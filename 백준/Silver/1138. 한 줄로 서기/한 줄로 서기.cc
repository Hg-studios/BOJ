#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; 
    if (!(cin >> N)) return 0;
    vector<int> L(N);
    for (int i = 0; i < N; ++i) cin >> L[i];

    vector<int> ans; 
    ans.reserve(N);

    // 키가 큰 사람부터 삽입
    for (int h = N; h >= 1; --h) {
        int idx = L[h - 1];              // 왼쪽에 있어야 하는 큰 사람 수
        ans.insert(ans.begin() + idx, h); // 그 위치에 h 삽입
    }

    for (int i = 0; i < N; ++i) {
        if (i) cout << ' ';
        cout << ans[i];
    }
    cout << '\n';
    return 0;
}