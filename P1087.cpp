#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 10;
int n;
string str;
struct Node {
    char s;
    Node *left_node = NULL, *right_node = NULL;
};
char solve(string& s) {
    bool has1 = 0, has0 = 0;
    for (auto& ch : s) {
        if (ch == '0') has0 = 1;
        if (ch == '1') has1 = 1;
    }
    return has0 && has1 ? 'F' : (has0 ? 'B' : 'I');
}
void build_tree(Node* treenode, string s) {
    treenode->s = solve(s);
    if (s.size() == 1) return;
    string left_s = s.substr(0, s.size() / 2);
    string right_s = s.substr(s.size() / 2, s.size() / 2);
    treenode->left_node = new Node();
    treenode->right_node = new Node();
    build_tree(treenode->left_node, left_s);
    build_tree(treenode->right_node, right_s);
}
void dfs(Node* p) {
    if (p->left_node != NULL) dfs(p->left_node);
    if (p->right_node != NULL) dfs(p->right_node);
    cout << p->s;
}
int main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> n;
    cin >> str;
    Node* root = new Node();
    build_tree(root, str);
    dfs(root);
    cout << "\n";
    return 0;
}