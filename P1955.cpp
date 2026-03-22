#include <bits/stdc++.h>
using namespace std;
using ll = long long;
map<int, int> mpe;
vector<pair<int, int>> v;
int q, n, x, y, opt;
int findf(int x) { return mpe[x] == x ? x : mpe[x] = findf(mpe[x]); }
void merge(int x, int y) { mpe[findf(x)] = findf(y); }
void print() {
    for (int i = 1; i <= n; ++i) cout << findf(i) << " ";
    cout << "\n";
}
void solve() {
    cin >> n;
    mpe.clear();
    v.clear();
    for (int i = 1; i <= n; ++i) {
        cin >> x >> y >> opt;
        mpe[x] = mpe[x] == 0 ? x : mpe[x];
        mpe[y] = mpe[y] == 0 ? y : mpe[y];
        if (opt) {
            merge(x, y);
        } else {
            v.push_back(make_pair(x, y));
        }
    }
    for (auto &i : v) {
        if (findf(i.first) == findf(i.second)) {
            cout << "NO\n";
            // print();
            return;
        }
    }
    // print();
    cout << "YES\n";
}
int main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> q;
    while (q--) {
        solve();
    }
    return 0;
}