#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int ans = 0;
    for (int i = 1; i <= 2024; ++i)
        if ((i ^ 2024) < 2024) ans++;
    cout << ans << "\n";
    return 0;
}