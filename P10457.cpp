#include <bits/stdc++.h>
using namespace std;
struct card {
    int num;
    bool state;
};
deque<card> q[20];
char ch;
unordered_map<char, int> hs;
int main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    for (int i = 2; i <= 9; ++i) hs[i + '0'] = i;
    hs['0'] = 10, hs['J'] = 11, hs['Q'] = 12, hs['K'] = 13, hs['A'] = 1;
    for (int i = 1; i <= 13; ++i) {
        for (int j = 1; j <= 4; ++j) {
            cin >> ch;
            q[i].push_back({hs[ch], 0});
            // cout << i << " " << j << " " << hs[ch] << "\n";
        }
    }
    int hp = 4;
    while (!q[13].empty()) {
        card cd = q[13].front();
        q[13].pop_front();
        while (cd.num != 13) {
            cd.state = 1;
            q[cd.num].push_front(cd);
            int num = cd.num;
            cd = q[num].back();
            q[num].pop_back();
        }
    }
    int ans = 0;
    for (int i = 1; i <= 12; ++i) {
        bool flag = 1;
        for (auto& cd : q[i])
            if (cd.num != i || cd.state != 1) flag = 0;
        if (flag) ans++;
    }
    cout << ans << "\n";
    return 0;
}