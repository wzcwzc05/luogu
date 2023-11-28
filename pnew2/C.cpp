#include <bits/stdc++.h>
using namespace std;
const int N = 1e5;
int main()
{
    int q;
    cin >> q;
    while (q--)
    {
        long long ans = 0;
        long long n, k, t;
        bool flag = 0;
        cin >> n >> k;
        long long x = n / k;
        /*if (k==1)
        {
            cout<<n<<"\n";
            continue;
        }*/
        ans = (n + 1) * x - ((k + (k + k * (x - 1))) * x / 2);
        ans = ans * 2;
        if (k == 1)
            ans = ans - n;
        /*while (flag==0)
        {
            ans+=(n-t+1)*2;
            t+=k;
            if (n-t+1<=0)
                flag=1;
        }*/
        cout << ans << "\n";
    }
    return 0;
}
