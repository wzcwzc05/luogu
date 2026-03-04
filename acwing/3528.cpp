#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 10;
int n;
string st[N];
string pat;
int main() {
    // ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> st[i];
    cin >> pat;
    for (auto& ch : pat) ch = tolower(ch);
    for (int p = 1; p <= n; ++p) {
        string str = st[p];
        for (auto& ch : str) ch = tolower(ch);
        int i = 0, j = 0;
        bool flag = 0;
        for (i = 0, j = 0; i < str.size() && j < pat.size(); ++i, ++j) {
            // cout << i << " " << j << "\n";
            if (pat[j] == '[') {
                ++j;
                bool finded = 0;
                while (pat[j] != ']') {
                    // cout << i << " " << j << "\n";
                    if (pat[j] == str[i]) {
                        finded = 1;
                    }
                    ++j;
                }
                if (!finded) {
                    flag = 1;
                    break;
                }
            } else if (pat[j] != str[i]) {
                flag = 1;
                break;
            }
        }
        // cout << i << " " << str.size() << " " << j << " " << pat.size() <<
        // "\n";
        if (i == str.size() && j == pat.size() && !flag)
            cout << p << " " << st[p] << "\n";
    }
    return 0;
}