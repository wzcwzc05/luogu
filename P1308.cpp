#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void Utolower(string& str)
{
    for (auto& i : str) {
        if (i >= 'A' && i <= 'Z')
            i += 'a' - 'A';
    }
}
int main()
{
    string str, t;
    ll i = 0, count = 0;
    cin >> str;
    getchar();
    Utolower(str);
    getline(cin, t);
    Utolower(t);
    t = ' ' + t + ' ', str = ' ' + str + ' ';
    if (t.find(str) == -1) {
        cout << -1 << "\n";
        return 0;
    }
    while (t.find(str, i) != -1) {
        ++count;
        i = t.find(str, i) + 1;
    }
    cout << count << " " << t.find(str) << "\n";
    return 0;
}