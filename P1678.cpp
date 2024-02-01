#include <bits/stdc++.h>
using namespace std;
using ll = long long;
vector<ll> vec;
ll n, m;
ll b_find(int t)
{
    ll left_p = 0, right_p = n - 1, mid_p = 0;
    while (left_p < right_p)
    {
        mid_p = left_p + (right_p - left_p) / 2;
        if (vec[mid_p] > t)
            right_p = mid_p;
        else
            left_p = mid_p + 1;
    }
    return left_p;
}
int main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        ll temp;
        cin >> temp;
        vec.push_back(temp);
    }
    sort(vec.begin(), vec.end());
    ll ans = 0;
    for (int i = 1; i <= m; i++)
    {
        ll temp;
        cin >> temp;
        ll pos = b_find(temp);
        if (pos == n)
            ans += temp - vec[pos - 1];
        else if (pos == 0)
            ans += vec[0] - temp;
        else
            ans += min(abs(temp - vec[pos]), abs(temp - vec[pos - 1]));
    }
    cout << ans << "\n";
    return 0;
}