#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll n, ans;
string str;
map<string, bool> mp;
int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> str;
        ans = mp[str] == 0 ? ans + 1 : ans;
        mp[str] = 1;
    }
    cout << ans << "\n";
    return 0;
}