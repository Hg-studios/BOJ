#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;
    vector<long long> S(N);
    for(int i = 0; i < N; i++){
        cin >> S[i];
    }
    long long M;
    cin >> M;

    // M이 초기 구간 안에 있으면 바로 출력
    if(M <= N){
        cout << S[M-1] << '\n';
        return 0;
    }

    // 1) 초기 수열 S의 서로 다른 값 개수 K 계산
    vector<long long> T = S;
    sort(T.begin(), T.end());
    T.erase(unique(T.begin(), T.end()), T.end());
    long long K = T.size();

    // 2) i > N 구간에서 B_i = (이전까지의 서로 다른 개수)
    //    이 값이 T에 처음 포함되는 j_stop 시점을 찾는다.
    //    j_stop = min{ j ≥ 0 | K + j ∈ T }
    auto it = lower_bound(T.begin(), T.end(), K);
    long long j_stop = (it == T.end() ? LLONG_MAX : (*it - K));

    // M번째 항은, M = N + t일 때
    long long t = M - N;
    long long ans;
    if(t <= j_stop){
        // 아직 멈추기 전: B_{N+t} = K + (t-1)
        ans = K + (t - 1);
    } else {
        // 멈춘 뒤에는 모두 동일한 값
        ans = K + j_stop;
    }

    cout << ans << '\n';
    return 0;
}
