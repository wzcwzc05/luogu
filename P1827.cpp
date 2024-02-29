#include <bits/stdc++.h>
using namespace std;
struct Node {
    char value = 0;
    Node* lchild = NULL;
    Node* rchild = NULL;
    Node(char x)
    {
        this->value = x;
    }
};
char pre[10001], mid[10001];
long long n;
Node* build(char v, int lmid, int rmid, int lpre, int rpre)
{
    if (lmid > rmid || lpre > rpre || lmid < 1 || rmid > n || lpre < 1 || rpre > n)
        return NULL;
    // cout << (char)v << " " << lmid << " " << rmid << " " << lpre << " " << rpre << endl;
    Node* p = new Node(v);
    int k = lmid, lc = 0;
    while (mid[k] != v && k <= rmid)
        ++lc, ++k;
    p->lchild = build(pre[lpre + 1], lmid, k - 1, lpre + 1, lpre + lc);
    p->rchild = build(pre[lpre + lc + 1], k + 1, rmid, lpre + lc + 1, rpre);
    return p;
}
void postSearch(Node* p)
{
    if (p->lchild != NULL)
        postSearch(p->lchild);
    if (p->rchild != NULL)
        postSearch(p->rchild);
    cout << p->value;
}
int main()
{
    string str1, str2;
    cin>>str1>>str2;
    for (auto& i : str1) {
        mid[++n] = i;
    }
    n = 0;
    for (auto& i : str2) {
        pre[++n] = i;
    }
    Node* p = build(pre[1], 1, n, 1, n);
    postSearch(p);
    cout << "\n";
    return 0;
}