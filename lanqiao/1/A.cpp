#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll N = 1e5 + 10;
ll n;
char ch;
map<char, int> m;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= 4; j++)
        {
            int t = 0;
            cin >> ch;
            m[ch]++;
        }
        if (m.size() == 2)
        {
            int temp = 0;
            for (auto i = m.begin(); i != m.end(); i++)
            {
                if (temp == 0)
                    temp = i->second;
                else
                {
                    if (temp == 3 && i->second == 1)
                        cout << "Yes"
                             << "\n";
                    else if (temp == 1 && i->second == 3)
                        cout << "Yes"
                             << "\n";
                    else
                        cout << "No"
                             << "\n";
                }
            }
        }
        else
            cout << "No"
                 << "\n";
        m.clear();
    }
    return 0;
}