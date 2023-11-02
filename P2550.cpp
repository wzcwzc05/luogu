#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll a[10], n, m, prize[10];
int main()
{
    cin >> n;
    for (int i = 1; i <= 7; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
    {
        int ans = 0, temp;
        for (int j = 1; j <= 7; j++)
        {
            cin >> temp;
            for (int k = 1; k <= 7; k++)
                if (temp == a[k])
                {
                    ans++;
                    break;
                }
        }
        prize[ans]++;
    }
    for (int i = 7; i >= 1; i--)
        cout << prize[i] << " ";
    cout << "\n";
    return 0;
}