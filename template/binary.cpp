// 二分模板
#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 9;
int a[N];
bool check(int a, int b)
{
    return a < b;
}
void solve()
{
    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    while (q--)
    {
        int x;
        cin >> x;
        int l = 1, r = n;
        while (l + 1 != r)
        {
            int mid = (l + r) / 2;
            if (check(a[mid], x))
                l = mid;
            else
                r = mid;
        }
        if (a[r] == x)
            cout << r << "\n";
        else
            cout << -1 << " ";
    }
}
int main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int q;
    cin>>q;
    while (q--)
        solve();
    return 0;
}