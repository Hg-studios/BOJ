#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> v(m);
    for (int i = 0; i < m; i++) {
        cin >> v[i];
    }

    int diff = 0;

    // 1. 첫 가로등과 마지막 가로등이 비추는 거리 확인
    diff = max(diff, v[0] - 0);  // 시작 부분
    diff = max(diff, n - v[m-1]); // 끝 부분

    // 2. 가로등 사이 간격 확인
    for (int i = 1; i < m; i++) {
        diff = max(diff, (v[i] - v[i-1] + 1) / 2);
    }

    cout << diff << endl;
    return 0;
}
