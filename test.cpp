#include <bits/stdc++.h>
using namespace std;
using ll = long long;
bool isPower(ll x, ll p)
{
    ll last, num = 0;
    if (x <= 0)
        return false;
    while (x != 0)
    {
        last = x % p;
        if (last != 1 && last != 0)
            return false;
        else if (last == 1)
            if (num != 0)
                return false;
            else
                num = 1;

        x = x / p;
    }
    return true;
}
int main()
{
    int n, a = 1, s = 0, m;
    cin >> n >> m;
    cout << isPower(n, m) << endl;
    return 0;
}