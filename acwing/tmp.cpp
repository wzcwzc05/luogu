#include <bits/stdc++.h>
using namespace std;
string s;
vector<bool> bos[26];  // 0为小写，1为大写字母
map<int, char> mp;     // 非英文字母位置
int main(void) {
    while (getline(cin, s)) {
        int n = s.size();
        for (int i = 0; i < s.size();) {
            if ((s[i] <= 'Z' && s[i] >= 'A') || (s[i] <= 'z' && s[i] >= 'a')) {
                if (s[i] <= 'Z' && s[i] >= 'A') {
                    bos[s[i] - 'A'].push_back(1);
                    s[i] = s[i] - 'A' + 'a';
                    i++;
                } else if (s[i] <= 'z' && s[i] >= 'a') {
                    bos[s[i] - 'a'].push_back(0);
                    i++;
                }
            } else {
                mp[i + mp.size()] = s[i];
                s.erase(s.begin() + i);
            }
        }
        sort(s.begin(), s.end());
        int j = 0;  // vector中的第几个
        char flag = 'a';
        for (int i = 0; i < n; i++) {
            if (mp.find(i) != mp.end()) {
                s.insert(i, 1, mp[i]);
            } else {
                if (s[i] != flag) {
                    j = 0;
                }
                if (j < bos[s[i] - 'a'].size() && bos[s[i] - 'a'][j] == 1) {
                    flag = s[i];
                    s[i] = s[i] - 'a' + 'A';
                    j++;
                } else if (j < bos[s[i] - 'a'].size() &&
                           bos[s[i] - 'a'][j] == 0) {
                    j++;
                    flag = s[i];
                }
            }
        }
        cout << s << '\n';
        memset(bos, 0, sizeof(bos));
        mp.clear();
    }
    return 0;
}