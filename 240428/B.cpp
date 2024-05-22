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
        if (ch[2][i] == '*' && h > 0) {
            ans++, h--, ch[2][i] = '.';
            if (ch[1][i] == '*' && h > 0) ans++, h--, ch[1][i] = '.';
        }
        if (ch[4][i] == '*' && h > 0) {
            ans++, h--, ch[4][i] = '.';
            if (ch[5][i] == '*' && h >= 0) ans++, h--, ch[5][i] = '.';
        }
    }
    for (int i = 1; i <= 5; ++i, cout << "\n")
        for (int j = 1; j <= n; ++j) cout << ch[i][j];
    for (int i = 1; i <= n; ++i) {
        if (ch[1][i] == '*' && h >= 2) ans++, h -= 2, ch[1][i] = '.';
        if (ch[5][i] == '*' && h >= 2) ans++, h -= 2, ch[5][i] = '.';
    }
    cout << ans << "\n";
    return 0;
}
/*
10 40
####*#####
###****###
..........
##########
##########
*/