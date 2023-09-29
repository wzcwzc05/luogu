#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, a = 1, s = 0;
    cin >> n;
    for (int i = n; i > 0; i--)
    {
        for (int j = i; j > 0; j--)
        {
            a *= j;
        }
        s += a;
        a = 1;
    }
    cout << s << endl;
    return 0;
}