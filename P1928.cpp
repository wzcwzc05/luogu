#include <bits/stdc++.h>
using namespace std;
string str, ans;
struct node {
    int ed;
    string str;
};
bool isNum(char ch)
{
    return (ch >= '0' && ch <= '9');
}
node prase(int st)
{
    string strt;
    int num = 0, i;
    if (isNum(str[st + 1]) && isNum(str[st + 2]))
        num = (str[st + 1] - '0') * 10 + (str[st + 2] - '0'), st += 3;
    else if (isNum(str[st + 1]))
        num = (str[st + 1] - '0'), st += 2;
    for (i = st; str[i] != ']' && i < str.size(); ++i) {
        if (str[i] != '[')
            strt += str[i];
        else {
            node temp;
            temp = prase(i);
            strt += temp.str;
            i = temp.ed;
        }
    }
    string res = "";
    for (int k = 1; k <= num; ++k)
        res += strt;
    return { i, res };
}
int main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    getline(cin, str);
    for (int i = 0; i < str.size(); ++i) {
        if (str[i] != '[')
            ans += str[i];
        else {
            node temp;
            temp = prase(i);
            ans += temp.str;
            i = temp.ed;
        }
    }
    cout << ans << "\n";
    return 0;
}