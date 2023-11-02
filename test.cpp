#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll N = 1e8 + 10;
ll a, b, c, sum1, sum2, sum3;
int main()
{
    cin >> a >> b >> c;
    for (ll i = 1; i <= a; i++)
    {
        sum1 = (i * i * i) % 998244353;
        for (ll j = 1; j <= b; j++)
        {
            sum2 = sum1 * j * j % 998244353;
            for (ll k = 1; k <= c; k++)
            {
                sum3 += sum2 * (c - k) % 998244353;
                sum3 = sum3 % 998244353;
            }
        }
    }
    cout << sum3 << "\n";
    return 0;
}