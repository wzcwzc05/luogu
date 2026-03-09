#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll q, n;
struct Node {
    int id;
    ll num;
};
void solve() {
    cin >> n;
    map<int, int> count;
    unordered_map<int, int> ids;
    int ans = INT_MAX, ansi = 0;
    for (int i = 1; i <= n; ++i) {
        int tmp;
        cin >> tmp;
        count[tmp]++;
        ids[tmp] = i;
    }
    for (const auto& s : count) {
        if (s.second == 1) {
            cout << ids[s.first] << "\n";
            return;
        }
    }
    cout << "-1\n";
    return;
}
int main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> q;
    while (q--) {
        solve();
    }
    return 0;
}