#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e5;
int n, m, q;
string st;
int main()
{
    cin >> q;
    while (q--)
    {
        cin >> n >> m;
        cin >> st;
        int status = m, ans = 0;
        for (int i = 0; i <= st.size() - 1; i++)
        {
            if (st[i] == 'a')
                status = status - 1;
            if (st[i] == 'p')
                status = status - 3;
            if (st[i] == 's')
                status = status - 2;
            if (status <= 0)
            {
                if (st[i] == 'p')
                    ans++;
                status = m;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}