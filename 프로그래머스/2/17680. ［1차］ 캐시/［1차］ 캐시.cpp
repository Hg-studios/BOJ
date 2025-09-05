#include <string>
#include <vector>
#include <queue>
#include <functional>   // std::greater
#include <cctype>       // tolower
using namespace std;

struct State {
    string city;
    int timer;
};

// timer가 작은 게 위로 오게(=가장 오래된 게 top)
struct Cmp {
    bool operator()(const State& a, const State& b) const {
        return a.timer > b.timer; // min-heap by timer
    }
};

int solution(int cacheSize, vector<string> cities) {
    // (필요하면) 대소문자 무시
    for (auto& s : cities) {
        for (auto& ch : s) ch = tolower(static_cast<unsigned char>(ch));
    }

    int answer = 0;
    priority_queue<State, vector<State>, Cmp> pq;

    for (int i = 0; i < (int)cities.size(); i++) {
        priority_queue<State, vector<State>, Cmp> tmp;

        bool hit = false; // pq 안에 있는지
        while (!pq.empty()) {
            auto cur = pq.top(); pq.pop();

            if (cur.city == cities[i]) { // cache hit
                hit = true;
                answer += 1;
                tmp.push({cur.city, i}); // 최신 사용 시각으로 갱신
            } else {
                tmp.push(cur);
            }
        }

        if (!hit) { // cache miss
            answer += 5;

            if (cacheSize > 0) {
                if ((int)tmp.size() >= cacheSize) {
                    tmp.pop(); // 가장 오래된 것 제거
                }
                tmp.push({cities[i], i});
            }
            // cacheSize==0이면 아무 것도 넣지 않음
        }

        pq = std::move(tmp);
    }

    return answer;
}
