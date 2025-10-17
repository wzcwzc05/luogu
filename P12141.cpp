#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll t, n, m, k;
int main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> t;
    while (t--) {
        cin >> n >> k;
        bool flag = true;
        while (n--) {
            if (k % 2 == 0)
                k /= 2, flag = !flag;
            else
                k = k / 2 + 1;
        }
        if (flag)
            cout << "RED\n";
        else
            cout << "BLACK\n";
    }
    return 0;
}