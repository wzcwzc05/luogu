#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll qpower(ll n, ll m, ll p)
{
    ll base = n;
    ll ans = 1;
    while (m > 0) {
        if (m & 1)
            ans = ans * base % p;
        base = base * base % p;
        m >>= 1;
    }
    return ans;
}
int main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    ll n, m, p;
    cin >> n >> m >> p;
    cout << n << "^" << m << " mod " << p << "=" << qpower(n, m, p) << endl;
    return 0;
}