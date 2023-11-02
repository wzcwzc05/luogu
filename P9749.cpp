#include <bits/stdc++.h>
using namespace std;
int n, m, i, j, k;
int main()
{
    cin >> n;
    int ans = 0, t = 0;
    bool flag = 0;
    while (n != 0)
    {
        ans++;
        if (n % 3 == 1 && flag == 0)
        {
            t = ans;
            flag = 1;
        }
        if (n % 3 == 0)
            n -= n / 3;
        else
            n -= (n / 3 + 1);
    }
    cout << ans << " " << t << "\n";
    return 0;
}