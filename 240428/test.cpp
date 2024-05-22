#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e5 + 10;
char ch[5][N];
int main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    ll n, h, ans = 0;
    cin >> n >> h;
    for (int i = 1; i <= 5; ++i)
        for (int j = 1; j <= n; ++j) cin >> ch[i][j];
    for (int i = 1; i <= n; ++i) {
        if (h < 2) break;
        if (ch[2][i] == '*' && ch[1][i] == '*') h -= 2, ans += 2;
        if (h < 2) break;
        if (ch[4][i] == '*' && ch[5][i] == '*') h -= 2, ans += 2;
        if (h < 2) break;
    }
    if (h == 0) {
        cout << ans << "\n";
        return 0;
    }
    for (int i = 1; i <= n; ++i) {
        if (ch[2][i] == '*' && ch[1][i] != '*') h--, ans++;
        if (h == 0) {
            cout << ans << "\n";
            return 0;
        }
        if (ch[4][i] == '*' && ch[5][i] != '*') h--, ans++;
        if (h == 0) {
            cout << ans << "\n";
            return 0;
        }
    }
    if (h < 2) {
        cout << ans << "\n";
        return 0;
    }
    for (int i = 1; i <= n; ++i) {
        if (ch[1][i] == '*' && ch[2][i] != '*') h -= 2, ans++;
        if (h < 2) {
            cout << ans << "\n";
            return 0;
        }
        if (ch[5][i] == '*' && ch[4][i] != '*') h -= 2, ans++;
        if (h < 2) {
            cout << ans << "\n";
            return 0;
        }
    }
    cout << ans << "\n";
    return 0;
}
/*
10 2
##########
#####**###
..........
##########
##########
*/