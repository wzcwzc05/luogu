#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll N = 1e5 + 10;
int n, a[N], q, m, h, w;
struct Node
{
    int x, y, use;
};

int main()
{
    cin >> q;
    Node a[5];
    while (q--)
    {
        cin >> h >> w;
        a[0].x = h / 2, a[1].x = h / 2, a[2].x = h / 2 + 1, a[3].x = h / 2 + 1;
        a[0].y = w / 2 + 1, a[1].y = w / 2, a[2].y = w / 2 + 1, a[3].y = w / 2;
        cin >> n >> m;
        int ans = 0;
        for (int i = 1; i <= n; i++)
        {
            int x, y;
            cin >> x >> y;
            if (x <= a[0].x && y <= a[0].y)
                a[0].x = x, a[0].y = y, a[0].use = 1;
            if (x <= a[1].x && y >= a[1].y)
                a[1].x = x, a[1].y = y, a[1].use = 1;
            if (x >= a[2].x && y <= a[2].y)
                a[2].x = x, a[2].y = y, a[2].use = 1;
            if (x >= a[3].x && y >= a[3].y)
                a[3].x = x, a[3].y = y, a[3].use = 1;
        }
        for (int i = 1; i <= m; i++)
        {
            int x, y;
            cin >> x >> y;
            for (int i = 0; i <= 3; i++)
            {
                if (a[i].use == 1)
                {
                    ans = max(ans, abs(x - a[i].x) + abs(y - a[i].y));
                }
            }
        }
        cout << ans << "\n";
    }
    return 0;
}