#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll n, m, t, ag, au, cu;
string temp, team;
ll penlty[1000];
ll win[1000];
bool vis[1000][500];
int main()
{
    cin >> n >> m >> au >> ag >> cu;
    for (int i = 1; i <= n; i++)
    {
        cin >> team;
        for (int j = 1; j <= m; j++)
        {
            cin >> t;
            int time;
            string status;
            for (int k = 1; k <= t; k++)
            {
                cin >> time >> status;
                if (status == "AC" && vis[i][j] == 0)
                {
                    vis[i][j] = 1;
                    win[i]++;
                }
            }
        }
    }
    return 0;
}