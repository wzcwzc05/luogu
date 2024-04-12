#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll n, m, t, sum;
vector<int> vec;
bool cmp(pair<int, int> a, pair<int, int> b) { return a.second > b.second; }
int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> t, vec.push_back(t);
        sum += t;
    }
    sort(vec.begin(), vec.end());
    int p = 0;
    while (sum >= m) {
        int re = m;
        while (re > 0) {
            if (re < vec[p])
                vec[p] -= re, re = 0;
            else
                re -= vec[p], vec[p] = 0, ++p;
        }
        // cout << p << " " << vec[p] << "\n";
        sum -= m;
    }
    // for (auto &i : vec) cout << i << " ";
    cout << vec.size() - p << "\n";
    return 0;
}