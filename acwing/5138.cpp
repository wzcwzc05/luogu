#include <bits/stdc++.h>
using namespace std;
unordered_map<char, int> hs;
int n;
string str;
int main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> n;
    cin >> str;
    int ans = 0;
    for (auto& ch : str) {
        if (ch >= 'a' && ch <= 'z')
            hs[ch]++;
        else if (hs[ch + 'a' - 'A'] <= 0)
            ans++;
        else
            hs[ch + 'a' - 'A']--;
    }
    cout << ans << "\n";
    return 0;
}