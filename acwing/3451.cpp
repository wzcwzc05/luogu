#include <bits/stdc++.h>
using namespace std;
bool cmp(const char& a, const char& b) { return tolower(a) < tolower(b); }
int main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    string str;
    while (getline(cin, str)) {
        string tmp, ans;
        for (auto& ch : str)
            if (isalpha(ch)) tmp += ch;
        stable_sort(tmp.begin(), tmp.end(), cmp);
        int i = 0, j = 0;
        for (i = 0, j = 0; i < str.length(), j < tmp.length(); ++i, ++j) {
            while (!isalpha(str[i])) {
                ans += str[i];
                ++i;
            }
            ans += tmp[j];
        }
        if (i != str.length())
            for (; i < str.length(); ++i) ans += str[i];
        cout << ans << "\n";
    }
    return 0;
}