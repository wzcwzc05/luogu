#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    string str;
    int ans = 0;
    cin >> str;
    for (int i = 0; i < str.length(); ++i) {
        int t = 0;
        for (int j = i + 1; j < str.length(); ++j)
            if (str[i] > str[j])
                ++t;
            else if (str[i] == str[j]) {
                int l = i, r = j, flag = 0;
                while (l <= r) {
                    if (str[l] > str[r]) {
                        flag = 1;
                        break;
                    } else if (str[l] < str[r]) {
                        break;
                    }
                    ++l, --r;
                }
                if (flag == 1) ++t;
            }
        ans += t;
    }

    cout << ans << "\n";
    return 0;
}