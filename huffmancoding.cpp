#include <bits/stdc++.h>
using namespace std;
struct TNode {
    char t;
    TNode *lChild = NULL;
    TNode *rChild = NULL;
};
void build(TNode *root) {       

}
string str1, str2;
int main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> str1 >> str2;
    TNode *root = new TNode{*str2.end(), NULL, NULL};
    build(root);
    return 0;
}