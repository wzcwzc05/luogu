#include <bits/stdc++.h>
using namespace std;
char ch;
bool points[62526];
int nums;
int main() {
    cin >> ch;
    while (ch != 'E') {
        if (ch != '\n') points[nums++] = ch == 'W' ? 0 : 1;
        cin >> ch;
    }
    int hua = 0, oppo = 0;
    for (int i = 0; i <= nums - 1; ++i) {
        hua += points[i] == 0 ? 1 : 0;
        oppo += points[i] == 1 ? 1 : 0;
        if ((hua >= 11 || oppo >= 11) && (abs(hua - oppo) >= 2)) {
            cout << hua << ":" << oppo << "\n";
            hua = oppo = 0;
        }
    }
    cout << hua << ":" << oppo << "\n\n";
    hua = oppo = 0;
    for (int i = 0; i <= nums - 1; ++i) {
        hua += points[i] == 0 ? 1 : 0;
        oppo += points[i] == 1 ? 1 : 0;
        if ((hua >= 21 || oppo >= 21) && (abs(hua - oppo) >= 2)) {
            cout << hua << ":" << oppo << "\n";
            hua = oppo = 0;
        }
    }
    cout << hua << ":" << oppo << "\n";
    return 0;
}