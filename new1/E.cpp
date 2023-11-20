#include <bits/stdc++.h>
using namespace std;
const int N = 1e5;
char mp[10][10];
int m[10][10], k;
void init()
{
    for (int i = 1; i <= 5; i++)
        for (int j = 1; j <= 9; j++)
        {
            mp[i][j] = 'o';
        }
}
void pace()
{
    for (int i = 1; i <= 9; i++)
    {
        for (int j = 1; j <= 5; j++)
        {
            if (i == 1 && mp[j][i] == 'x')
                mp[j][i] = 'o';
            else if (mp[j][i] == 'x')
            {
                mp[j][i - 1] = 'x';
                mp[j][i] = 'o';
            }
        }
    }
}
int main()
{
    int q, n;
    cin >> q;
    while (q--)
    {
        init();
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            pace();
            cin >> k;
            for (int j = 1; j <= k; j++)
            {
                int t;
                cin >> t;
                mp[t][9] = 'x';
            }
            int a, b;
            cin >> b >> a;
            if (a == 3)
            {
                for (int j = 1; j <= 9; j++)
                    mp[b][j] = 'o';
            }
            if (a == 2)
            {
                for (int j = 1; j <= 9; j++)
                {
                    if (mp[b][j] == 'x')
                    {
                        for (int x = b - 1; x <= b + 1; x++)
                            for (int y = j - 1; y <= j + 1; y++)
                                mp[x][y] = 'o';
                        break;
                    }
                }
            }
            if (a == 1)
            {
                for (int j = 1; j <= 9; j++)
                {
                    if (mp[b][j] == 'x')
                    {
                        mp[b][j] = 'o';
                        break;
                    }
                }
            }
        }
        for (int i = 1; i <= 5; i++)
        {
            for (int j = 1; j <= 9; j++)
                cout << mp[i][j];
            cout << "\n";
        }
    }
    return 0;
}
