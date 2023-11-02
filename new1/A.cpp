#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll q, n, m;
string st;
int main()
{
    cin >> q;
    while (q--)
    {
        cin >> st;
        if (st.size() - 1 > 0)
        {
            for (int i = 0; i <= st.size() - 1; i++)
                if (st[i] == st[i + 1])
                {
                    cout << st[i] << "\n";
                    break;
                }
        }
        else
            cout << st << "\n";
    }
    return 0;
}