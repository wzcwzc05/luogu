#include <bits/stdc++.h>
using namespace std;
int n, s, minn[110], maxn[110];
int main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> n >> s;
    if (n == 1 && s == 0) {
        cout << "0 0\n";
        return 0;
    }
    if (s <= 0) {
        cout << "-1 -1\n";
        return 0;
    }
    int tmp_s = s - 1;
    minn[1] = 1;
    for (int i = n; i > 1; --i) {
        if (tmp_s > 9)
            minn[i] += 9, tmp_s -= 9;
        else {
            minn[i] = tmp_s, tmp_s = 0;
            break;
        }
    }
    if (tmp_s > 8) {
        cout << "-1 -1\n";
        return 0;
    } else
        minn[1] += tmp_s;
    tmp_s = s;
    for (int i = 1; i <= n; ++i) {
        if (tmp_s > 9)
            maxn[i] = 9, tmp_s -= 9;
        else {
            maxn[i] = tmp_s, tmp_s = 0;
            break;
        }
    }
    if (tmp_s > 0) {
        cout << "-1 -1\n";
        return 0;
    }
    for (int i = 1; i <= n; ++i) cout << minn[i];
    cout << " ";
    for (int i = 1; i <= n; ++i) cout << maxn[i];
    cout << "\n";
    return 0;
}