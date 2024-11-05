        #include <bits/stdc++.h>
        using namespace std;
        using ll = long long;
        const ll N = 2e5 + 10;
        struct Node {
            ll data;
            ll fa;
        };
        vector<ll> primes;
        Node a[N];
        ll opt = 0;
        Node org = {0, 0};
        ll n, q, k, x, y;
        ll x_find(ll cur) {
            // cout << "Enter: " << cur << "\n";
            if (__gcd(org.data, a[cur].data) > 1 && cur != x)
                return cur;
            else if (a[cur].fa == cur)
                return -1;
            else
                return x_find(a[cur].fa);
        }
        int main() {
            ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
            cin >> n >> q;
            for (int i = 1; i <= n; ++i) cin >> a[i].data, a[i].fa = i;
            for (int i = 1; i <= n - 1; ++i) {
                cin >> x >> y;
                a[y].fa = x;
            }

            while (q--) {
                cin >> opt;
                if (opt == 1) {
                    cin >> x;
                    org = a[x];
                    cout << x_find(x) << "\n";
                } else {
                    cin >> x >> y;
                    a[x].data = y;
                }
            }
            return 0;
        }