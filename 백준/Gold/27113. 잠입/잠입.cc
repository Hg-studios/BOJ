#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
 
typedef long long ll;
 
struct Interval {
    ll L, R;
};
 
// 각 경계에 대해 센서 정보를 입력받아 안전한(allowed) 열 구간을 반환합니다.
vector<Interval> computeAllowed(int cnt, vector<ll>& cols, vector<char>& dirs, ll M) {
    vector<Interval> allowed;
    if(cnt == 0){
        allowed.push_back({1, M});
    } else if(cnt == 1){
        ll c = cols[0];
        char d = dirs[0];
        if(d == 'L'){
            // forbidden: [1, c] → allowed: [c+1, M]
            if(c < M)
                allowed.push_back({c+1, M});
        } else { // d == 'R'
            // forbidden: [c, M] → allowed: [1, c-1]
            if(c > 1)
                allowed.push_back({1, c-1});
        }
    } else if(cnt == 2){
        ll c1 = cols[0], c2 = cols[1];
        char d1 = dirs[0], d2 = dirs[1];
        if(d1 == 'L' && d2 == 'L'){
            // forbidden = [1, c2] → allowed = [c2+1, M]
            if(c2 < M)
                allowed.push_back({c2+1, M});
        } else if(d1 == 'R' && d2 == 'R'){
            // forbidden = [c1, M] → allowed = [1, c1-1]
            if(c1 > 1)
                allowed.push_back({1, c1-1});
        } else if(d1 == 'L' && d2 == 'R'){
            // forbidden = [1, c1] U [c2, M] → allowed = [c1+1, c2-1]
            if(c1 + 1 <= c2 - 1)
                allowed.push_back({c1+1, c2-1});
        } else if(d1 == 'R' && d2 == 'L'){
            // forbidden = [c1, c2] → allowed = [1, c1-1] U [c2+1, M]
            if(c1 > 1)
                allowed.push_back({1, c1-1});
            if(c2 < M)
                allowed.push_back({c2+1, M});
        }
    }
    // 안전 구간을 시작 열 기준으로 오름차순 정렬
    sort(allowed.begin(), allowed.end(), [](const Interval &a, const Interval &b){
        return a.L < b.L;
    });
    return allowed;
}
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int N;
    ll M;
    cin >> N >> M;
    // 경계는 1행과 2행 사이부터 (N-1)행과 N행 사이까지 총 N-1개
    vector<vector<Interval>> allowedIntervals(N+1); // index 1 ~ N-1 사용.
    for (int i = 1; i <= N-1; i++){
        int cnt;
        cin >> cnt;
        vector<ll> cols(cnt);
        vector<char> dirs(cnt);
        for (int j = 0; j < cnt; j++){
            cin >> cols[j] >> dirs[j];
        }
        allowedIntervals[i] = computeAllowed(cnt, cols, dirs, M);
    }
 
    // dp: 현재 행에서 가능한 최소 열 값을 cur라 하고, 그 행에서는 [cur, M]이 가능
    ll cur = 1; // row1: 시작점 (1,1)
    bool possible = true;
    // 각 경계 i (row i -> i+1)마다
    for (int i = 1; i <= N-1; i++){
        ll newCur = -1;
        // 현재 행에서는 오른쪽으로 얼마든지 갈 수 있으므로 [cur, M]에서 allowedIntervals[i]와의 교집합 중 최소값을 선택
        for(auto &intv : allowedIntervals[i]){
            if(intv.R < cur) continue; // intv가 현재 범위보다 왼쪽에 있음.
            newCur = max(cur, intv.L);
            break; // 정렬되어 있으므로 첫 번째로 만나는 것이 최소값.
        }
        if(newCur == -1){
            possible = false;
            break;
        }
        cur = newCur; // row i+1에서는 [cur, M]이 가능
    }
    // row N에서는 오른쪽으로 이동해서 (N, M)에 도달할 수 있음 (M은 항상 ≥ cur 인 상태여야 함)
    cout << (possible && cur <= M ? "YES" : "NO") << "\n";
    return 0;
}
