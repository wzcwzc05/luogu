#include <bits/stdc++.h>
using namespace std;
int search_max_number(int t) {
    int maxn = 0;
    while (t != 0) {
        maxn = max(t % 10, maxn);
        t /= 10;
    }
    return maxn;
}
int main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int res = 1, ans = 0;
    while (res != 2024) {
        double cost_1 = (res + 1 <= 2024) ? 1.0 : 0.0;
        int max_num = search_max_number(res);
        double cost_2 = (res + max_num <= 2024) ? max_num / 3.0 : 0.0;
        double cost_3 = (res * 2 <= 2024) ? res / 10.0 : 0.0;
        if (cost_1 > cost_2 && cost_1 > cost_3)
            ans += 1, res += 1;
        else if (cost_2 > cost_1 && cost_2 > cost_3)
            ans += 3, res += max_num;
        else if (cost_3 > cost_1 && cost_3 > cost_2)
            ans += 10, res *= 2;
        else {
            if (cost_3 != 0)
                ans += 10, res *= 2;
            else if (cost_2 != 0)
                ans += 3, res += max_num;
            else
                ans += 1, res += 1;
        }
        cout << res << "\n";
    }
    cout << "Ans: " << ans << "\n";
    return 0;
}