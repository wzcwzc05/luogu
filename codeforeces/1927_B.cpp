#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 2e5 + 10;
ll n, m, _;
const string str = "abcdefghijklmnopqrstuvwxyz";
void solve()
{
    int temp = 0, maxn = 0;
    cin >> n;
    string ans = "";
    vector<deque<char>> v;
    v.push_back(deque<char>());
    for (char c : str)
        v[0].push_back(c);
    for (int i = 1; i <= n; ++i) {
        cin >> temp;
        if (temp == maxn) {
            v.push_back(deque<char>());
            ++maxn;
        }
        ans.push_back(*(v[temp].begin()));
        v[temp + 1].push_back(*(v[temp].begin()));
        v[temp].pop_front();
    }
    cout << ans << "\n";
}
int main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> _;
    while (_--)
        solve();
    return 0;
}