#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll n, pos, att, hp, pos1, pos2;
string str;
bool flag;
struct hero {
    ll hp, att;
};
hero mp[3][8];
void summon_h(bool target, ll pos, ll att, ll hp) {
    if (mp[target][pos].hp != 0) {
        for (int i = 7; i > pos; --i) {
            mp[target][i] = mp[target][i - 1];
        }
    }
    mp[target][pos].hp = hp;
    mp[target][pos].att = att;
}
void attack_h(bool target, ll our_p, ll target_p) {
    mp[!target][target_p].hp -= mp[target][our_p].att;
    mp[target][our_p].hp -= mp[!target][target_p].att;
    if (mp[!target][target_p].hp <= 0 && target_p != 0) {
        // cout << "1dead: " << !target << " " << target_p << "\n";
        mp[!target][target_p].hp = mp[!target][target_p].att = 0;
    }
    if (mp[target][our_p].hp <= 0 && our_p != 0) {
        // cout << "2dead: " << target << " " << our_p << "\n";
        mp[target][our_p].hp = mp[target][our_p].att = 0;
    }
}
void sort_h() {
    // cout << ":BEFORE\n";
    // for (int i = 1; i <= 7; ++i) cout << mp[0][i].hp << " ";
    // cout << "\n";
    // for (int i = 1; i <= 7; ++i) cout << mp[!0][i].hp << " ";
    // cout << "\n";
    for (int i = 1; i <= 7; ++i)
        if (mp[0][i].hp != 0) {
            ll pos = i;
            for (int j = i - 1; j >= 1; --j)
                if (mp[0][j].hp != 0) {
                    break;
                } else
                    pos = j;
            mp[0][pos] = mp[0][i];
            if (pos != i) mp[0][i].hp = mp[0][i].att = 0;
        }
    for (int i = 1; i <= 7; ++i)
        if (mp[1][i].hp != 0) {
            ll pos = i;
            for (int j = i - 1; j >= 1; --j)
                if (mp[1][j].hp != 0) {
                    break;
                } else
                    pos = j;
            mp[1][pos] = mp[1][i];
            if (pos != i) mp[1][i].hp = mp[1][i].att = 0;
        }
    // cout << "AFTER:\n";
    // for (int i = 1; i <= 7; ++i) cout << mp[0][i].hp << " ";
    // cout << "\n";
    // for (int i = 1; i <= 7; ++i) cout << mp[!0][i].hp << " ";
    // cout << "\n";
}
int main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> n;
    mp[0][0].hp = mp[1][0].hp = 30;
    mp[0][0].att = mp[1][0].att = 0;
    for (int i = 1; i <= n; ++i) {
        cin >> str;
        if (str == "summon") {
            cin >> pos >> att >> hp;
            summon_h(flag, pos, att, hp);
        } else if (str == "attack") {
            cin >> pos1 >> pos2;
            attack_h(flag, pos1, pos2);
        } else if (str == "end") {
            flag = !flag;
        }
        sort_h();
        if (mp[0][0].hp <= 0) {
            cout << "-1\n";
            break;
        }
        if (mp[1][0].hp <= 0) {
            cout << "1\n";
            break;
        }
    }

    if (mp[0][0].hp > 0 && mp[1][0].hp > 0) cout << "0\n";
    ll num = 0;
    cout << mp[0][0].hp << "\n";
    for (int i = 1; i <= 7; ++i) {
        if (mp[0][i].hp != 0) num++;
    }
    cout << num << " ";
    for (int i = 1; i <= 7; ++i) {
        if (mp[0][i].hp != 0) cout << mp[0][i].hp << " ";
    }
    cout << '\n';
    num = 0;
    cout << mp[1][0].hp << "\n";
    for (int i = 1; i <= 7; ++i) {
        if (mp[1][i].hp != 0) num++;
    }
    cout << num << " ";
    for (int i = 1; i <= 7; ++i) {
        if (mp[1][i].hp != 0) cout << mp[1][i].hp << " ";
    }
    cout << '\n';
    return 0;
}