#include <bits/stdc++.h>
using namespace std;
using ll = long long;
string str;
ll n;
vector<pair<ll, ll>> v;
map<pair<ll, ll>, int> mp;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
int main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> n;
    cin >> str;
    int x = 0, y = 0, d = 0;
    v.push_back({x, y});
    for (int i = 0; i < n; ++i) {
        if (str[i] == 'F') {
            x += dx[d], y += dy[d];
            v.push_back({x, y});
        } else if (str[i] == 'L') {
            d = (d - 1 + 4) % 4;
            x += dx[d], y += dy[d];
            v.push_back({x, y});
        } else if (str[i] == 'R') {
            d = (d + 1) % 4;
            x += dx[d], y += dy[d];
            v.push_back({x, y});
        }
        // cout << "Orginal:" << x << " " << y << " " << d << "\n";
    }
    int final_x = x, final_y = y;
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        int dx, dy, tx, ty;
        dx = final_x - v[i].first, dy = final_y - v[i].second;
        if (str[i] == 'F') {
            tx = v[i].first - dy, ty = v[i].second + dx;
            if (mp[make_pair(tx, ty)] == 0) {
                ans++;
                mp[make_pair(tx, ty)] = 1;
            }
            // cout << tx << " " << ty << "\n";
            tx = v[i].first + dy, ty = v[i].second - dx;
            if (mp[make_pair(tx, ty)] == 0) {
                ans++;
                mp[make_pair(tx, ty)] = 1;
            }
            // cout << tx << " " << ty << "\n";
        } else if (str[i] == 'L') {
            tx = v[i].first + dy, ty = v[i].second - dx;
            if (mp[make_pair(tx, ty)] == 0) {
                ans++;
                mp[make_pair(tx, ty)] = 1;
            }
            // cout << tx << " " << ty << "\n";
            tx = v[i].first - dx, ty = v[i].second - dy;
            if (mp[make_pair(tx, ty)] == 0) {
                ans++;
                mp[make_pair(tx, ty)] = 1;
            }
            // cout << tx << " " << ty << "\n";
        } else if (str[i] == 'R') {
            tx = v[i].first - dy, ty = v[i].second + dx;
            if (mp[make_pair(tx, ty)] == 0) {
                ans++;
                mp[make_pair(tx, ty)] = 1;
            }
            // cout << tx << " " << ty << "\n";
            tx = v[i].first - dx, ty = v[i].second - dy;
            if (mp[make_pair(tx, ty)] == 0) {
                ans++;
                mp[make_pair(tx, ty)] = 1;
            }
            // cout << tx << " " << ty << "\n";
        }
    }
    cout << ans << "\n";
    return 0;
}