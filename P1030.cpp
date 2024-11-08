#include <bits/stdc++.h>
using namespace std;
struct TNode {
    char t;
    TNode *lChild = NULL;
    TNode *rChild = NULL;
};

string str1, str2;
TNode *build(string mid, string back) {
    TNode *root = new TNode{back[back.size() - 1], NULL, NULL};
    char root_c = back[back.size() - 1];
    int left_t = 0, right_t = 0;
    for (int i = 0; i < mid.size(); ++i) {
        if (mid[i] == root_c)
            break;
        else
            left_t++;
    }
    right_t = back.size() - 1 - left_t;
    if (left_t != 0)
        root->lChild = build(mid.substr(0, left_t), back.substr(0, left_t));
    if (right_t != 0)
        root->rChild = build(mid.substr(left_t + 1, right_t),
                             back.substr(left_t, right_t));
    return root;
}
void front_travel(TNode *root) {
    if (root != NULL) {
        cout << root->t;
        front_travel(root->lChild);
        front_travel(root->rChild);
    }
}
int main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> str1 >> str2;
    TNode *root = NULL;
    root = build(str1, str2);
    front_travel(root);
    cout << "\n";
    return 0;
}