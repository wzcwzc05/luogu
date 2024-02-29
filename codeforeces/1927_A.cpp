#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll n, m, _;
string str;
void solve()
{
    ll start_p = 0, end_p = 0;
    cin >> n >> str;
    for (auto i = str.begin(); i != str.end(); ++i)
        if (*i == 'B') {
            start_p = i - str.begin() + 1;
            break;
        }
    for (auto i = str.end() - 1; i != str.begin() - 1; --i)
        if (*i == 'B') {
            end_p = i - str.begin() + 1;
            break;
        }
    cout << end_p - start_p + 1 << "\n";
}
int main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> _;
    while (_--)
        solve();
    return 0;
}