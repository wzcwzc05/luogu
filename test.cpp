<<<<<<< Updated upstream
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int a[5][200], n, m, ans;
void dfs(int dep, int left_, int right_,
         int d) {  // 深度,左脑用时,右脑用时,第d科
    if (dep > a[d][0]) {
        ans = min(ans, max(left_, right_));
    } else {
        dfs(dep + 1, left_ + a[d][dep], right_, d);
        dfs(dep + 1, left_, right_ + a[d][dep], d);
    }
}
int main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    for (int i = 1; i <= 4; ++i) cin >> a[i][0];
    for (int i = 1; i <= 4; ++i) {
        for (int j = 1; j <= a[i][0]; ++j) cin >> a[i][j];
    }
    int sum = 0;
    for (int i = 1; i <= 4; ++i) {
        ans = INT_MAX;
        dfs(1, 0, 0, i);
        sum += ans;
    }
    cout << sum << "\n";
    return 0;
=======
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define OVERFLOW -2
typedef int Status;
typedef char TElemType;

Status PrintElement(TElemType e) {
    printf("%c", e);
    return OK;
}
typedef enum PointerTag { Link, Thread };

typedef struct BiThrNode {
    TElemType data;
    struct BiThrNode *lchild, *rchild;
    PointerTag LTag, RTag;
} BiThrNode, *BiThrTree;
BiThrTree pre;
Status CreateBiThrTree(BiThrTree& T) {
    char ch;
    scanf("%c", &ch);
    if (ch == '#')
        T = NULL;
    else {
        if (!(T = (BiThrNode*)malloc(sizeof(BiThrNode)))) exit(OVERFLOW);
        T->data = ch;
        CreateBiThrTree(T->lchild);
        if (T->lchild != NULL) T->LTag = Link;
        CreateBiThrTree(T->rchild);
        if (T->rchild != NULL) T->RTag = Link;
    }
    return OK;
}

void InThreading(BiThrTree p) {
    if (p) {
        InThreading(p->lchild);
        if (!p->lchild) {
            p->LTag = Thread;
            p->lchild = pre;
        }
        if (!pre->rchild) {
            pre->RTag = Thread;
            pre->rchild = p;
        }
        pre = p;
        InThreading(p->rchild);
    }
}
Status InOrderThreading(BiThrTree& Thrt, BiThrTree T) {
    if (!(Thrt = (BiThrTree)malloc(sizeof(BiThrNode)))) exit(OVERFLOW);
    Thrt->LTag = Link;
    Thrt->RTag = Thread;
    Thrt->rchild = Thrt;
    if (!T)
        Thrt->lchild = Thrt;
    else {
        Thrt->lchild = T;
        pre = Thrt;
        InThreading(T);
        pre->rchild = Thrt;
        pre->RTag = Thread;
        Thrt->rchild = pre;
    }
    return OK;
}
Status InOrderTraverse_Thr(BiThrTree T, Status (*Visit)(TElemType e)) {
    BiThrNode* p;
    p = T->lchild;
    while (p != T) {
        while (p->LTag == Link) p = p->lchild;
        if (!Visit(p->data)) return ERROR;
        while (p->RTag == Thread && p->rchild != T) {
            p = p->rchild;
            Visit(p->data);
        }
        p = p->rchild;
    }
    return OK;
}

int main() {
    BiThrTree T, Thrt;
    printf("创建线索二叉树，按先序次序输入线索二叉树中结点的值：\n");
    CreateBiThrTree(T);
    if (InOrderThreading(Thrt, T) == OK) printf("成功建立中序线索化链表！\n");
    printf("中序遍历线索二叉树，结果是：\n");
    InOrderTraverse_Thr(Thrt, PrintElement);
    printf("\n");
>>>>>>> Stashed changes
}