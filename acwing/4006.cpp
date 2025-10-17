#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll max_ans, min_ans, n, t, cur;
int main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> t;
        if (t == cur)
            min_ans += 0;
        else
            min_ans += t, cur = t;
        max_ans += cur;
    }
    cout << max_ans << "\n" << min_ans << "\n";
    return 0;
}
