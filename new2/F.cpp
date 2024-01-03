#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll q, n, m;
ll fact(ll n)
{
    ll sum = 1;
    for (ll i = 1; i <= n; i++)
        sum *= i;
    return sum;
}
void solve()
{
    set<string> st;
    cin >> n >> m;
    for (ll i = 1; i <= m; i++)
    {
        string str;
        for (ll i = 1; i <= n; i++)
        {
            ll temp;
            cin >> temp;
            str += to_string(temp);
        }
        st.insert(str);
    }
    if (st.size() >= fact(n)-1)
        cout << "YES\n";
    else
        cout << "NO\n";
}
int main()
{
    cin >> q;
    while (q--)
    {
        solve();
    }
    return 0;
}