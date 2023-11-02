#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll q, n, m, ans;
string st;
map<char, int> mm;
int main()
{
    cin >> q;
    int temp = 'a' - 'A';
    while (q--)
    {
        cin >> st;
        for (int i = 0; i <= st.size() - 1; i++)
        {
            if (st[i] >= 'a' && st[i] <= 'z')
                mm[st[i]]++;
        }
    }
    return 0;
}