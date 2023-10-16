#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll N = 1e5 + 10;
ll n, m, a[N], l, r, mid, ans;
char ch;
string st;
bool check(ll mid)
{
    int groups = 0, left = 1;
    while (left < n + 1)
    {
        int right = left;
        while (right < n + 1 && a[right] - a[left] <= mid)
        {
            right++;
        }
        groups++;
        left = right;
    }
    cout << mid << " " << groups << endl;
    return groups <= m;
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    sort(a + 1, a + n + 1);
    l = 0;
    r = a[n] - a[1];
    ans = 0;
    while (l + 1 != r)
    {
        mid = (r + l) / 2;
        if (check(mid))
        {
            ans = mid;
            r = mid;
        }
        else
        {
            l = mid;
        }
    }
    cout << ans << "\n";
    return 0;
}