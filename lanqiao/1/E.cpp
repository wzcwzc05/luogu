#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll N = 1e5 + 10;
ll n, m, a[N], l, r, mid, ans;
char ch;
string st1, st2, st3;
char transfer(char t)
{
    if (t >= 'a' && t <= 'z')
        return toupper(t);
    else
        return tolower(t);
}
bool check(int k)
{
    int t = 0, p = 0;
    while (t <= n)
    {
        p++;
        k++;
        if (st1[p] != st3[k])
            return false;
        t++;
    }
    return true;
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n;
    cin >> st1 >> st2;
    st3 = st1;
    for (int i = 0; i <= n - 1; i++)
    {
        st3[i] = transfer(st1[i]);
    }
    char ch = st3[0];
    for (ll i = 0; i <= n; i++)
    {
        if (ch == st2[i])
        {
            if (check(i))
            {
                ans = min(ans, min(i - 1, n - i + 1));
            }
        }
    }
    return 0;
}