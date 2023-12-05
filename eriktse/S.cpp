#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10;
int n, m, q, a[N];
bitset<N> bs;
int main()
{
    cin >> n;
    bs[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        int temp;
        cin >> temp;
        bs |= (bs << temp);
    }
    int ans = 0;
    for (int i = 0; i <= N; i++)
    {
        if (bs[i] == 1)
            ans++;
    }
    cout << ans << "\n";
    return 0;
}