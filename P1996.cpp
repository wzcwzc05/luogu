#include <bits/stdc++.h>
using namespace std;
bool vis[1000];
int main()
{
    int n, m;
    cin >> n >> m;
    int step = 1, t = 0, left = n;
    while (left > 0)
    {
        if (vis[step] == 0)
            t++;
        if (t == m)
        {
            cout << step << " ";
            left--;
            vis[step] = 1;
            t = 0;
        }
        step++;
        if (step > n)
        {
            step = 1;
        }
    }
    cout << endl;
    return 0;
}