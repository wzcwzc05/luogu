#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e3 + 10;
ll n;
struct Node {
    string name;
    ll age;
    ll score;
};
bool cmp(const Node& a, const Node& b) {
    if (a.score != b.score)
        return a.score < b.score;
    else if (a.name != b.name)
        return a.name < b.name;
    else
        return a.age < b.age;
}
int main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> n;
    vector<Node> v;
    for (int i = 1; i <= n; ++i) {
        Node stu;
        cin >> stu.name >> stu.age >> stu.score;
        v.push_back(stu);
    }
    sort(v.begin(), v.end(), cmp);
    for (auto& i : v) cout << i.name << " " << i.age << " " << i.score << "\n";
    return 0;
}