#include <bits/stdc++.h>
using namespace std;
map<int, map<int, int>> a;
int n, q;
int main()
{
    cin >> n >> q;
    for (int i = 1; i <= q; i++)
    {
        int opt;
        cin >> opt;
        if (opt == 1)
        {
            int x, y, t;
            cin >> x >> y >> t;
            a[x][y] = t;
        }
        else
        {
            int x, y;
            cin >> x >> y;
            cout << a[x][y] << endl;
        }
    }
    return 0;
}