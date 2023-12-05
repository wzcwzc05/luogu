#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int n, m, q;
set<int,greater<int> > st;
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int temp;
        cin >> temp;
        st.insert(temp);
    }
    for (auto i = st.begin(); i != st.end(); ++i)
        cout << *i << " ";
    return 0;
}