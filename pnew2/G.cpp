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
    while (q--)
    {
        Node a[5], b[5];
        for (int i = 0; i <= 3; i++)
        {
            a[i].x = 0, b[i].x = 0;
            a[i].y = 0, b[i].y = 0;
            a[i].use = 0, b[i].use = 0;
        }
        cin >> h >> w;
        a[0].x = h / 2, a[1].x = h / 2, a[2].x = h / 2, a[3].x = h / 2;
        a[0].y = w / 2, a[1].y = w / 2, a[2].y = w / 2, a[3].y = w / 2;
        b[0].x = h / 2, b[1].x = h / 2, b[2].x = h / 2, b[3].x = h / 2;
        b[0].y = w / 2, b[1].y = w / 2, b[2].y = w / 2, b[3].y = w / 2;
        cin >> n >> m;
        int ans = 0;
        for (int i = 1; i <= n; i++)
        {
            int x, y;
            cin >> x >> y;
            if (x <= a[0].x && y <= a[0].y)
                a[0].x = x, a[0].y = y, a[0].use = 1;
            if (x < a[1].x && y > a[1].y)
                a[1].x = x, a[1].y = y, a[1].use = 1;
            if (x >= a[2].x && y <= a[2].y)
                a[2].x = x, a[2].y = y, a[2].use = 1;
            if (x > a[3].x && y > a[3].y)
                a[3].x = x, a[3].y = y, a[3].use = 1;
        }
        for (int i = 1; i <= m; i++)
        {
            int x, y;
            cin >> x >> y;
            if (x <= b[0].x && y <= b[0].y)
                b[0].x = x, b[0].y = y, b[0].use = 1;
            if (x < b[1].x && y > b[1].y)
                b[1].x = x, b[1].y = y, b[1].use = 1;
            if (x >= b[2].x && y <= b[2].y)
                b[2].x = x, b[2].y = y, b[2].use = 1;
            if (x > b[3].x && y > b[3].y)
                b[3].x = x, b[3].y = y, b[3].use = 1;
        }
        for (int i = 0; i <= 3; i++)
        {
            if (a[i].use == 1 && b[3 - i].use == 1)
                ans = max(ans, abs(a[i].x - b[3 - i].x) + abs(a[i].y - b[3 - i].y));
        }
        cout << ans << "\n";
    }
    return 0;
}