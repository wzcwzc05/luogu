#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e5;
int main()
{
    int q;
    cin >> q;
    while (q--)
    {
        string st;
        cin >> st;
        int n, l;
        n = st.size() - 1;
        l = n;
        bool flag = true;
        for (int i = 0; i <= n; i++)
        {
            if (st[i] >= 'a' && st[i] <= 'z')
                st[i] -= 'a' - 'A';
        }
        for (int i = 0; i <= n; i++)
        {
            // cout<<st[i]<<" "<<st[l]<<"\n";
            if (st[i] == st[l])
            {
                flag = false;
                break;
            }
            l--;
        }
        if (flag == true)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}
