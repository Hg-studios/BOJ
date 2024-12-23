#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

// 두더지 정보를 담을 구조체
struct Mole {
    int x, y, t;
};

// 거리 계산 함수 (x1, y1)에서 (x2, y2)까지의 유클리드 거리
double getDistance(int x1, int y1, int x2, int y2) {
    return sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
}

int main() {
    int N, S;
    cin >> N >> S;

    vector<Mole> moles(N);
    for (int i = 0; i < N; ++i) {
        cin >> moles[i].x >> moles[i].y >> moles[i].t;
    }

    // 두더지를 시간 순으로 정렬
    sort(moles.begin(), moles.end(), [](const Mole &a, const Mole &b) {
        return a.t < b.t;
    });

    // DP 배열 초기화
    vector<int> dp(N, 0);
    int maxMoles = 0;

    // 각 두더지에 대해 계산
    for (int i = 0; i < N; ++i) {
        // 시작 위치에서 첫 번째 두더지로 이동할 수 있는지 확인
        double distanceFromStart = getDistance(0, 0, moles[i].x, moles[i].y);
        if (distanceFromStart / S <= moles[i].t) {
            dp[i] = 1; // 첫 번째 두더지를 잡을 수 있는 경우
        }

        // 이전 두더지에서 현재 두더지로 이동 가능 여부 확인
        for (int j = 0; j < i; ++j) {
            double travelTime = getDistance(moles[j].x, moles[j].y, moles[i].x, moles[i].y) / S;
            if (moles[j].t + travelTime <= moles[i].t && dp[j] > 0) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }

        // 최대 잡을 수 있는 두더지 수 갱신
        maxMoles = max(maxMoles, dp[i]);
    }

    cout << maxMoles << endl;

    return 0;
}
