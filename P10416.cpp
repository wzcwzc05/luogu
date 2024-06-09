#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll t, l, r;
int main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> t;
    while (t--) {
        cin >> l >> r;
        if (r % 2 == 0)
            cout << (r - l + 1) * 2 - (r / 2 - l + 1) << "\n";
        else
            cout << (r - l + 1) * 2 - (r / 2 - l) << "\n";
    }
    return 0;
}