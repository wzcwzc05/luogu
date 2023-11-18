// kmp算法
#include <iostream>
#include <vector>
#include <string>

using namespace std;

// 构建部分匹配表
vector<int> buildNext(const string& pattern) {
    int m = pattern.length();
    vector<int> next(m, 0);
    for (int i = 1, j = 0; i < m; ++i) {
        while (j > 0 && pattern[i] != pattern[j]) {
            j = next[j - 1];
        }
        if (pattern[i] == pattern[j]) {
            ++j;
        }
        next[i] = j;
    }
    return next;
}

// KMP搜索算法
void KMP(const string& text, const string& pattern) {
    vector<int> next = buildNext(pattern);
    int n = text.length();
    int m = pattern.length();

    for (int i = 0, j = 0; i < n; ++i) {
        while (j > 0 && text[i] != pattern[j]) {
            j = next[j - 1];
        }
        if (text[i] == pattern[j]) {
            ++j;
        }
        if (j == m) {
            cout << "Pattern found at index " << i - m + 1 << endl;
            j = next[j - 1];
        }
    }
}

int main() {
    string text = "ABABDABACDABABCABAB";
    string pattern = "ABABCABAB";
    KMP(text, pattern);
    return 0;
}