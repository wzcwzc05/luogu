#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int n, m, q;
int hs[N][130];
int main()
{
    int q;
    cin >> n >> m >> q;
    for (int i = 1; i <= n; i++)
    {
        string st;
        cin >> st;
        for (int j = 0; j <= m - 1; j++)
            hs[j][st[j]]++;
    }
    for (int i = 1; i <= q; i++)
    {
        string st;
        int ans = 0;
        cin >> st;
        for (int i = 0; i <= m - 1; i++)
        {
            for (int j = 'a'; j <= 'z'; j++)
                if (st[i] != j)
                    ans += hs[i][j];
        }
        cout << ans << '\n';
    }
    return 0;
}
