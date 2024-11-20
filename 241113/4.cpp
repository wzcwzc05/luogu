#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MAXN = 1e5 + 10;
int year, month, day;
int month_day_1[14] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int month_day_2[14] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int total, ans;
int main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    year = 1901, month = 1, day = 1;
    int *month_days =
        (year % 4 == 0 && year % 100 != 0) ? month_day_2 : month_day_1;
    while (!(year == 2024 && month == 12 && day == 31)) {
        month_days =
            (year % 4 == 0 && year % 100 != 0) ? month_day_2 : month_day_1;
        if (day == 1 || day == 11 || day == 21 || day == 31) {
            if (total % 7 == 5) {
                ans++;
                cout << year << "-" << month << "-" << day << "\n";
            }
        }
        day++, total++;
        if (day > month_days[month]) month++, day = 1;
        if (month > 12) month = 1, year++;
    }
    cout << ans << "\n";
    return 0;
}