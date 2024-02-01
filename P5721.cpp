#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, t = 1;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n - i + 1; j++) {
            if (t < 10)
                cout << 0 << t;
            else
                cout << t;
            t++;
        }
        cout << endl;
    }
    return 0;
}