#include <bits/stdc++.h>
using namespace std;
int p1, p2, p3, len;
string str, ans;
bool is_number(char ch) { return ch >= '0' && ch <= '9'; }
bool is_alpha(char ch) { return ch >= 'a' && ch <= 'z'; }
string gen_str(int mode_1, int nums, char c) {
    string res = "";
    if (mode_1 == 1) c = tolower(c);
    if (mode_1 == 2) c = toupper(c);
    if (mode_1 == 3) c = '*';
    for (int i = 1; i <= nums; ++i) res += c;
    return res;
}
int main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> p1 >> p2 >> p3;
    cin >> str;
    len = str.size();
    for (int i = 0; i < len; ++i) {
        if (str[i] != '-')
            ans += str[i];
        else {
            if (is_number(str[i - 1]) && is_number(str[i + 1]) ||
                (is_alpha(str[i - 1]) && is_alpha(str[i + 1])))
                if (str[i - 1] < str[i + 1])
                    if (p3 == 1) {
                        // 顺序
                        for (char ch = str[i - 1] + 1; ch <= str[i + 1] - 1;
                             ++ch) {
                            ans += gen_str(p1, p2, ch);
                        }
                    } else {
                        // 逆序
                        for (char ch = str[i + 1] - 1; ch >= str[i - 1] + 1;
                             --ch) {
                            ans += gen_str(p1, p2, ch);
                        }
                    }
                else
                    ans += str[i];
            else
                ans += str[i];
        }
    }
    ans += '\0';
    cout << ans << "\n";
    return 0;
}