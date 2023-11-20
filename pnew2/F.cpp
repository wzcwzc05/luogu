#include <bits/stdc++.h>
using namespace std;
int a[10][10], temp[10][10];
int main()
{
    for (int i = 0; i <= 3; i++)
        for (int j = 0; j <= 5; j++)
        {
            a[i][j] = 3;
            temp[i][j] = 3;
        }
    for (int i = 1; i <= 2; i++)
        for (int j = 1; j <= 4; j++)
        {
            char ch;
            cin >> ch;
            a[i][j] = ch - '0';
            temp[i][j] = a[i][j];
        }
    bool flag = 1;
    while (flag == 1)
    {
        flag = 0;
        for (int i = 1; i <= 2; i++)
            for (int j = 1; j <= 4; j++)
                if (a[i + 1][j] == 3 && a[i][j + 1] == 3 && a[i - 1][j] == 3 && a[i][j - 1] == 3 && a[i][j] < 3)
                {
                    temp[i][j]++;
                    flag = 1;
                }
        memcpy(a, temp, sizeof(temp));
    }
    for (int i = 1; i <= 2; i++)
        for (int j = 1; j <= 4; j++)
            if (a[i][j] < 3)
            {
                cout << "NO\n";
                return 0;
            }
    cout << "YES\n";
    return 0;
}