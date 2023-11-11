#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 10;
int a[N], n, w[N];
long long prefixa[N];
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        prefixa[i] = prefixa[i - 1] + a[i];
    }
    prefixa[n + 1] = prefixa[n];
    long long mod = 1000000007, ans = 0, sum = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> w[i];
        sum = sum + prefixa[n - i] - prefixa[i];
        ans = (ans + w[i] * (sum % mod) % mod) % mod;
    }
    cout << ans << endl;
    return 0;
}