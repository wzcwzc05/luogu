#include <bits/stdc++.h>
using namespace std;
multiset<int> mt;
int n, opt, t;
int main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> n;
    mt.insert(INT_MAX), mt.insert(-INT_MAX);
    int order = 0;
    multiset<int>::iterator s = mt.begin();
    for (int i = 1; i <= n; ++i) {
        cin >> opt >> t;
        switch (opt) {
        case 1:
            s = lower_bound(mt.begin(), mt.end(), t);
            order = 0;
            for (auto i = mt.begin(); i != s; ++i, ++order)
                ;
            cout << order << "\n";
            break;
        case 2:
            order = -1;
            for (auto& i : mt) {
                if (++order == t) {
                    cout << i << "\n";
                    break;
                }
            }
            break;
        case 3:
            s = lower_bound(mt.begin(), mt.end(), t);
            cout << *(--s) << "\n";
            break;
        case 4:
            cout << *upper_bound(mt.begin(), mt.end(), t) << "\n";
            break;
        case 5:
            mt.insert(t);
            break;
        default:
            break;
        }
    }
    return 0;
}