#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll N = 1e5 + 10;
ll n;
bool h[N];
int main()
{
    cin >> n;
    int start = 1;
    int interval = n - 1;
    h[1] = 1;
    for (int i = 1; i <= n; i++)
    {
        cout << start << " ";
        if (start - interval > 0 && h[start - interval] == 0)
        {
            h[start - interval] = 1;
            start = start - interval;
        }
        else if (start - interval <= n && h[start + interval] == 0)
        {
            h[start + interval] = 1;
            start = start + interval;
        }
        interval--;
    }
    return 0;
}