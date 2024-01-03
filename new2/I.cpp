#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int q, n, m, a[10010];
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 0; i <= n; i++)
    {
        int count = 0;
        for (int j = 1; j <= n; j++)
            if (a[j] != i)
                count++;
        if (count == i)
        {
            cout << count << "\n";
            return 0;
        }
    }
    cout << -1 << "\n";
    return 0;
}