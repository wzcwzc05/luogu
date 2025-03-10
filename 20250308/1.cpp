#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int ans = 0;
    for (int i = 1; i <= 2025; ++i)
        if (i % 3 == 0 || i % 8 == 0 || i % 38 == 0) ans++;
    cout << ans << "\n";
    return 0;
}