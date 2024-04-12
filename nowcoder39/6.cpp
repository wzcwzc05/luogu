#include <bits/stdc++.h>
using namespace std;
const int N = 9e6 + 10;
int n, m, l, r;
char opt;
bitset<100010> bt1, bt2;
string str1, str2;
int main() {
    cin >> n;
    cin >> str1 >> str2;
    for (int i = 0; i < n; ++i) {
        bt1[i] = str1[i] - '0';
        bt2[i] = str2[i] - '0';
    }
    cin >> m;
    for (int i = 1; i <= m; ++i) {
        cin >> opt >> l >> r;
        if (opt == 'A') {
            for (int j = l; j <= r; ++j) bt1[j] = 1;
        } else {
            for (int j = l; j <= r; ++j) bt2[j] = 1;
        }
        int ans = 0;
        for (int i = 0; i < n; ++i)
            if (bt1[i] == 1 && bt2[i] == 1) ans++;
        cout << ans << "\n";
    }
    return 0;
}