#include <bits/stdc++.h>
using namespace std;
const int N = 9e6 + 10;
int a, b, c, x;
bool hs[N];
int cal(int x, int y, int z) { return 2 * x * z + 2 * y * z + x * y; }
int main() {
    cin >> a >> b >> c >> x;
    int ans = 0;
    for (int i = 1; i <= a; ++i)
        for (int j = 1; j <= b; ++j)
            for (int k = 1; k <= c; ++k)
                if (cal(i, j, k) == x) ans++;
    // for (int i = 1; i <= a; ++i)
    //     for (int j = 1; j <= b; ++j) hs[a * b] = 1;
    cout << ans << "\n";
    return 0;
}