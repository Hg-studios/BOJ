#include <iostream>
#include <algorithm>
using namespace std;

int n, s;
int arr[100005];
int mn = 0x7fffffff;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> s;
    for (int i = 0; i < n; i++) cin >> arr[i];

    int st = 0, en = 0, tot = 0;
    
    while (en < n) {
        tot += arr[en]; // 부분합에 en 추가

        while (tot >= s) { // 조건 만족하면 최소 길이 갱신 및 st 이동
            mn = min(mn, en - st + 1);
            tot -= arr[st];
            st++;
        }

        en++; // en을 이동
    }

    cout << (mn == 0x7fffffff ? 0 : mn);
    return 0;
}
