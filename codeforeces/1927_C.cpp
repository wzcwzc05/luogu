#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 2e5 + 10;
ll n, m, _, k;
struct node {
    int num, sec;
};
bool cmp(node a, node b)
{
    if (a.num == b.num)
        return a.sec < b.sec;
    return a.num < b.num;
}
void solve()
{
    int temp, t = 0;
    cin >> n >> m >> k;
    vector<node> v;
    for (int i = 1; i <= n; ++i) {
        cin >> temp;
        v.push_back({ temp, 1 });
    }
    for (int i = 1; i <= m; ++i) {
        cin >> temp;
        v.push_back({ temp, 2 });
    }
    sort(v.begin(), v.end(), cmp);
    ll count1 = 0, count2 = 0, now = 0, count3 = 0;
    for (int i = 0; v[i].num <= k && i < v.size(); ++i)
        if (v[i].num == now + 1) {
            ++now;
            if (v[i].sec == 1)
                if (v[i + 1].sec == 2 && v[i + 1].num = v[i].num)
                    ++count3;
                else
                    ++count1;
            else {
                if (i == 0)
                    ++count2;
                else if (!(v[i - 1].sec == 1 && v[i - 1].num == v[i].num))
                    ++count2;
            }
        } else {
            if (v[i].num == now) {
                if (v[i].sec == 1)
                    if (v[i + 1].sec == 2 && v[i + 1].num = v[i].num)
                        ++count3;
                    else
                        ++count1;
                else {
                    if (i == 0)
                        ++count2;
                    else if (!(v[i - 1].sec == 1 && v[i - 1].num == v[i].num))
                        ++count2;
                }
            } else {
                cout << "NO\n";
                return;
            }
        }
    if (count1 >= k / 2 && count2 >= k / 2 && now == k)
        cout << "YES\n";
    else
        cout << "NO\n";
}
int main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> _;
    while (_--)
        solve();
    return 0;
}