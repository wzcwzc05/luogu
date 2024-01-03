#include <bits/stdc++.h>
using namespace std;
set<int> st;
void decompose(int t)
{
    for (int i = 2; t != 1 && i <= t; i++)
    {
        if (t % i == 0)
        {
            while (t % i == 0)
                t /= i;
            st.insert(i);
        }
    }
}
int main()
{
    int n; cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int temp; cin >> temp;
        decompose(temp);
    }
    for (auto i = st.begin(); i != st.end(); i++)
        cout << *i << " ";
    cout << "\n";
    return 0;
}