#include <bits/stdc++.h>
using namespace std;
string str;
int main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> str;
    int ans = 0, cnt = 0;
    for (auto &c : str) {
        if (c == 'a')
            ans = max(++cnt, ans);
        else
            cnt = 0;
    }
    cout << string(ans + 1, 'a') << "\n";
    return 0;
}