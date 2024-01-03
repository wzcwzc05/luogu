#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
long long n, t, a[N], pren[N], suffn[N];
stack<long long> prestk, suffstk;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
    {
        while (!prestk.empty() && a[prestk.top()] >= a[i])
            prestk.pop();
        if (prestk.empty())
            pren[i] = 0;
        else
            pren[i] = prestk.top();
        prestk.push(i);
    }
    for (int i = n; i >= 1; i--)
    {
        while (!suffstk.empty() && a[suffstk.top()] > a[i])
            suffstk.pop();
        if (suffstk.empty())
            suffn[i] = n + 1;
        else
            suffn[i] = suffstk.top();
        suffstk.push(i);
    }
    long long sum = 0;
    for (int i = 1; i <= n; i++)
    {
        // cout << i << " " << pren[i] << " " << suffn[i] << " " << (suffn[i] - pren[i]) * 2 + 1 << "\n";
        sum += a[i] * (suffn[i] - i) * (i - pren[i]);
    }
    cout << sum << "\n";
    return 0;
}