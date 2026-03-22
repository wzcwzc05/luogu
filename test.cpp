#include <iostream>
#include <stack>
#define mp make_pair
using namespace std;
using LL = long long;
const int maxn = 100000 + 5;
int n, a[maxn], l[maxn], r[maxn];
LL sum[maxn];
bool first = 1;
 
int main() {
    while(cin >> n) {
        sum[0] = 0;
        for(int i = 0; i < n; i ++) cin >> a[i], sum[i + 1] = sum[i] + a[i];
 
        stack<int> stk_l, stk_r;
        for(int i = 0; i < n; i ++) {
            while(!stk_l.empty() && (a[stk_l.top()] > a[i] || (a[i] && a[stk_l.top()] == a[i]))) stk_l.pop();
            l[i] = (stk_l.empty() ? 0 : (stk_l.top() + 1));
            stk_l.push(i);
        }
        for(int i = n - 1; i >= 0; i --) {
            while(!stk_r.empty() && (a[stk_r.top()] > a[i] || (a[i] && a[stk_r.top()] == a[i]))) stk_r.pop();
            r[i] = (stk_r.empty() ? (n - 1) : (stk_r.top() - 1));
            stk_r.push(i);
        }
 
        LL ans = -1;
        int idx = 0;
        for(int i = 0; i < n; i ++) {
            LL val = (sum[r[i] + 1] - sum[l[i]]) * a[i];
            if(mp(ans, mp(-r[idx] + l[idx], -l[idx])) < mp(val, mp(-r[i] + l[i], -l[i]))) ans = val, idx = i;
        }
        if(first) first = 0;
        else cout << endl;
        cout << ans << "\n" << l[idx] + 1 << " " << r[idx] + 1 << endl;
    }
}