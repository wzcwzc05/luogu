#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll q, n, m, ans, flag;
string st;
int mm[1000];
int vis[1000];
int main()
{
    cin >> q;
    int temp = 'a' - 'A';
    while (q--)
    {
        cin >> st;
        flag = 0;
        for (int i = 'A'; i <= 'C'; i++)
        {
            vis[i] = 0;
            mm[i] = 0;
        }
        for (int i = 0; i <= st.size() - 1; i++)
        {
            if (st[i] >= 'a' && st[i] <= 'z')
                mm[st[i] - temp] = 1;
            if (st[i] >= 'A' && st[i] <= 'Z')
                if (mm[st[i]] == 1)
                {
                    vis[st[i]] = 1;
                }
        }
        for (int i = 'A'; i <= 'C'; i++)
            if (vis[i] == 0)
                flag = 1;
        if (flag == 0)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}