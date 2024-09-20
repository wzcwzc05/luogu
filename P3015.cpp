#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll N = 1e5 + 10;
const ll mod = 12345678910;
ll n, t, level_n;
ll level[N];
int main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> n;
    level_n = 0;
    for (int i = 1; i <= n; ++i) {
        cin >> t;
        if (!t) {
            ++level_n;
        } else {
            if (level[level_n] == 0)
                level[level_n - 1] = (level[level_n - 1] + 1) % mod,
                                level[level_n--] = 0;
            else
                level[level_n - 1] =
                    (level[level_n] * 2 + level[level_n - 1]) % mod,
                                level[level_n--] = 0;
        }
    }
    cout << level[0] % mod << "\n";
    return 0;
}