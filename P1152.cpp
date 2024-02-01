#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e3 + 10;
ll n, t, last, now;
bitset<N> bt;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> last;
    for (int i = 2; i <= n; i++)
    {
        cin >> now;
        ll diff = abs(now - last);
        if (diff <= n - 1 && diff >= 1 && bt[diff] == 0)
            bt[diff] = 1;
        last = now;
    }
    for (int i = 1; i <= n - 1; i++)
        if (bt[i] == 0)
        {
            cout << "Not jolly\n";
            return 0;
        }
    cout << "Jolly\n";
    return 0;
}