#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll N = 1e6 + 10;
ll n, t, a[N];
deque<ll> dqmax, dqmin;
vector<ll> ansmax, ansmin;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> t;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    dqmax.push_back(1), dqmin.push_back(1);
    for (int i = 2; i <= t; i++)
    {
        while (!dqmax.empty() && a[dqmax.back()] < a[i])
            dqmax.pop_back();
        while (!dqmin.empty() && a[dqmin.back()] > a[i])
            dqmin.pop_back();
        dqmax.push_back(i);
        dqmin.push_back(i);
    }
    ansmax.push_back(a[dqmax.front()]);
    ansmin.push_back(a[dqmin.front()]);
    for (int i = t + 1, k = 2; i <= n; i++, k++)
    {
        while (!dqmax.empty() && (dqmax.front() > i || dqmax.front() < k))
            dqmax.pop_front();
        while (!dqmin.empty() && (dqmin.front() > i || dqmin.front() < k))
            dqmin.pop_front();
        while (!dqmax.empty() && a[dqmax.back()] <= a[i])
            dqmax.pop_back();
        while (!dqmin.empty() && a[dqmin.back()] >= a[i])
            dqmin.pop_back();
        dqmax.push_back(i);
        dqmin.push_back(i);
        ansmax.push_back(a[dqmax.front()]);
        ansmin.push_back(a[dqmin.front()]);
    }
    for (auto i = ansmin.begin(); i != ansmin.end(); i++)
        cout << *i << " ";
    cout << "\n";
    for (auto i = ansmax.begin(); i != ansmax.end(); i++)
        cout << *i << " ";
    cout << "\n";
    return 0;
}