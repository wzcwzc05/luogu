#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int a[100010], n, k, ans;
bool cmp(int a, int b) { return a > b; }
// void dfs(int dep, int sum) {
//     if (sum % k == 0) {
//         ans = min(ans, dep);
//         return;
//     } else if (dep >= ans)
//         return;
//     for (int i = 1; i <= n; ++i) {
//         dfs(dep + 1, )
//     }
// }
int main() {
    cin >> n >> k;
    int t = 0;
    bool flag1 = 0, flag2 = 0, _ = 0;
    for (int i = 1; i <= n; ++i) {
        cin >> t;
        if (t % 3 == 0) {
            cout << 1 << "\n";
            return 0;
        } else if (t % 3 == 1) {
            if (flag2) {
                _ = 1;
                flag1 = 1;
            } else
                flag1 = 1;
        } else if (t % 3 == 2) {
            if (flag1) {
                _ = 1;
                flag2 = 1;
            } else
                flag2 = 1;
        }
    }
    if (_)
        cout << 2 << "\n";
    else
        cout << 3 << "\n";
    return 0;
}