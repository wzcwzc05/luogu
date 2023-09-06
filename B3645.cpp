#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int n, q, sum;
int l, r;
int a[N], prefix[N];
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    prefix[1] = a[1];
    for (int i = 2; i <= n; i++)
        prefix[i] = prefix[i - 1] + a[i];
    cin >> l >> r;
    sum = prefix[r] - prefix[l];
    for (int i = 2; i <= q; i++)
    {
        cin >> l >> r;
        cout<<prefix[r]-prefix[l]<<"\n";
    }
    cout << sum << "\n";
    return 0;
}