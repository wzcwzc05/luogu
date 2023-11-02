#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll x, y, i, sum,n;
int main()
{
    cin >> n;
    /*for (ll i = 1; i <= n; i++)
    {
        x = 1;
        for (ll j = n; j >= n - i + 1; j--)
            x *= j;
        y = 1;
        for (ll j = 1; j <= i; j++)
            y *= i;
        sum += (x / y);
    }*/
    ll sum=pow(2, n) - 1;
    cout << sum << "\n";
    return 0;
}