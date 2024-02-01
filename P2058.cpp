#include <bits/stdc++.h>
using namespace std;

int a[200002];
int n, m;

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        int temp;
        cin >> temp;
        a[i] = temp;
    }
    for (int i = 1; i <= m; i++)
    {
        int temp;
        cin >> temp;
        cout << a[temp] << endl;
    }
    return 0;
}
