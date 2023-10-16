#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll N = 1e5 + 10;
ll n, m;
char ch;
string st;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> m;
    while (m--)
    {
        cin >> st;
        int node = 1, line = 0;
        for (int i = 0; i <= st.size() - 1; i++)
        {
            char ch = st[i];
            if (ch == 'L')
            {
                node = node * 2 - 1;
            }
            else
                node = node * 2;
        }
        cout << node << "\n";
    }
    return 0;
}