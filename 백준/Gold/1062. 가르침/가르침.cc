#include <bits/stdc++.h>
using namespace std;

int n, k;
vector<int> word_mask;
vector<int> cand;
int mx = 0;

void dfs(int idx, int cnt, int learned, int target) {
    if (cnt == target) {
        int count_readable = 0;
        for (int m : word_mask) {
            if ((m & ~learned) == 0) {
                count_readable++;
            }
        }
        mx = max(mx, count_readable);
        return;
    }
    for (int i = idx; i < (int)cand.size(); ++i) {
        dfs(i + 1, cnt + 1, learned | (1 << cand[i]), target);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> k;
    if (k < 5) {
        cout << 0;
        return 0;
    }
    if (k == 26) {
        cout << n;
        return 0;
    }

    string s;
    for (int i = 0; i < n; ++i) {
        cin >> s;
        int mask = 0;
        for (char c : s) {
            mask |= (1 << (c - 'a'));
        }
        word_mask.push_back(mask);
    }

    // 기본으로 배워야 하는 글자들: a, n, t, i, c
    int learned = 0;
    char fixed_chars[5] = {'a', 'n', 't', 'i', 'c'};
    for (char c : fixed_chars) {
        learned |= (1 << (c - 'a'));
    }

    // 추가로 선택 가능한 후보 문자 목록 생성
    vector<bool> used(26, false);
    for (char c : fixed_chars) used[c - 'a'] = true;
    for (int c = 0; c < 26; ++c) {
        if (!used[c]) cand.push_back(c);
    }

    int target = k - 5;
    dfs(0, 0, learned, target);

    cout << mx;
    return 0;
}
