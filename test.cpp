#include <bits/stdc++.h>
using namespace std;
const int MAX_OPT = 4;
vector<double> num[100];
vector<double> start_v, end_v;
vector<pair<int, string>> opt = {
    { 2, "+" },
    { 2, "-" },
    { 2, "*" },
    { 2, "/" },
    // { 1, "!" },
    // { 1, "sqrt" },
    // { 1, "log" },
    // { 1, "ln" }
};
long long ans;
double factorial(double x)
{
    if (x == 0)
        return 1;
    return x * factorial(x - 1);
}
void dfs(int dep, int countOpt, double sum)
{
    if (countOpt > MAX_OPT)
        return;
    if (sum == 24.0000) {
        cout << "!\n";
        ans++;
        return;
    }
    for (auto& i : opt) {
        if (i.first == 1) {
            if (i.second == "!")
                dfs(dep, countOpt + 1, factorial(sum));
            if (i.second == "sqrt")
                dfs(dep, countOpt + 1, sqrt(sum));
            if (i.second == "log")
                dfs(dep, countOpt + 1, log10(sum));
            if (i.second == "ln")
                dfs(dep, countOpt + 1, log(sum));
        } else if (i.first == 2) {
            if (i.second == "+")
                dfs(dep + 1, countOpt + 1, sum + start_v[dep + 1]);
            if (i.second == "-")
                dfs(dep + 1, countOpt + 1, sum - start_v[dep + 1]);
            if (i.second == "*")
                dfs(dep + 1, countOpt + 1, sum * start_v[dep + 1]);
            if (i.second == "/")
                dfs(dep + 1, countOpt + 1, sum / start_v[dep + 1]);
        }
    }
}
int main()
{
    num[0] = { 4.0, 5.0, 6.0, 9.0 };
    int n = 1;
    num[1] = num[0];
    while (next_permutation(num[n].begin(), num[n].end())) {
        ++n;
        num[n] = num[n - 1];
    }
    // for (int i = 0; i < n; ++i) {
    //     for (int j = 0; j < 4; ++j)
    //         cout << num[i][j] << " ";
    //     cout << endl;
    // }
    for (int i = 0; i < 24; ++i) {
        end_v.clear();
        start_v = num[i];
        dfs(0, 0, num[i][0]);
    }
    cout << ans << endl;
    return 0;
}