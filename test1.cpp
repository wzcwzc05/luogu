/*机器人饲养指南*/
#include <bits/stdc++.h>
using namespace std;
long long n, A[120], ans;
int m;

void dp(long long nn, int mm, vector<int> s) {  // 拆分n，不超过m
    if (nn <= 0) {                              // 分解完
        // 计算
        long long tempans = 0;
        for (int i = 0; i < s.size(); i++) {
            tempans += A[s[i]];
        }
        if (tempans > ans) {
            ans = tempans;
            cout << "ans:" << ans << ' ';
            for (int i = 0; i < s.size(); i++) {
                cout << s[i] << ' ';
            }
            cout << '\n';
        }
        // 继续拆分
        sort(s.begin(), s.end());
        for (int i = 1; i < s[s.size() - 1]; i++) {
            s[s.size() - 1] -= i;
            s.push_back(i);
            dp(nn, mm, s);
        }
        return;
    }
    if (nn >= mm) {
        s.push_back(mm);
        dp(nn - mm, mm, s);
    } else {
        s.push_back(nn);
        dp(0, mm, s);
    }
}
int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        cin >> A[i];
    }
    vector<int> anss = {};
    dp(n, m, anss);
    cout << ans;
    return 0;
}