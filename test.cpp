#include <bits/stdc++.h>
using namespace std;
map<char, int> mp1, mp2;
int main() {
    // abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ
    string st = "ksjr{EcxvpdErSvcDgdgEzxqjql}";
    int s = 0, temp = 0;
    for (int ch = 'A', i = 0; ch <= 'Z'; ++ch, ++i) mp1[ch] = i;
    for (int ch = 'a', i = 0; ch <= 'z'; ++ch, ++i) mp2[ch] = i;
    for (auto &i : st) {
        if (i >= 'a' && i <= 'z') {
            temp = mp2[i];
            temp = temp - s * 2 - 5;
            while (temp < 0) temp += 26;
            i = temp + 'a';
        } else if (i >= 'A' && i <= 'Z') {
            temp = mp1[i];
            temp = temp - s * 2 - 5;
            while (temp < 0) temp += 26;
            i = temp + 'A';
        }
        s++;
    }
    cout << st << endl;
    return 0;
}