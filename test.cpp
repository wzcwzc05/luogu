#include <cstdio>
#include <cstdlib>
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define OVERFLOW -2
typedef int Status;
typedef int ElemType;
typedef struct LNode {
    ElemType data;
    struct LNode *next;
} LNode, *LinkList;
void CreateList_L(LinkList &L, int n) {
    int i;
    LinkList p;
    L = (LinkList)malloc(sizeof(LNode));
    L->next = NULL;
    for (i = n; i > 0; --i) {
        p = (LinkList)malloc(sizeof(LNode));
        scanf("%d", &p->data);
        p->next = L->next;
        L->next = p;
    }
}

Status OutputList_L(LinkList L) {
    LinkList p = L->next;
    if (!p) return ERROR;
    while (p) {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
    return OK;
}

Status GetElem_L(LinkList &L, int i, ElemType &e) {
    int j;
    LinkList p;
    p = L->next;
    j = 1;
    while (p && j < i) {
        p = p->next;
        ++j;
    }
    if (!p || j > i) return ERROR;
    e = p->data;
    return OK;
}

Status ListInsert_L(LinkList &L, int i, ElemType e) {
    LinkList p, s;
    int j;
    p = L;
    j = 0;
    while (p && j < i - 1) {
        p = p->next;
        ++j;
    }
    if (!p || j > i - 1) return ERROR;
    s = (LinkList)malloc(sizeof(LNode));
    s->data = e;
    s->next = p->next;
    p->next = s;
    return OK;
}

Status ListDelete_L(LinkList &L, int i, ElemType &e) {
    LinkList p, q;
    int j;
    p = L;
    j = 0;
    while (p->next && j < i - 1) {
        p = p->next;
        ++j;
    }
    if (!(p->next) || j > i - 1) return ERROR;
    q = p->next;
    p->next = q->next;
    e = q->data;
    free(q);
    return OK;
}

int main() {
    ElemType b, dd, d;
    LinkList L;
    printf("创建单链表,输入5个元素:\n");
    CreateList_L(L, 5);
    printf("输出单链表所有元素！\n");
    OutputList_L(L);
    printf("输出单链表第2个位置元素到dd!\n");
    GetElem_L(L, 2, dd);
    printf("dd=%d\n", dd);
    printf("插入元素b:");
    scanf("%d", &b);
    printf("在单链表第4个位置插入%d!\n", b);
    ListInsert_L(L, 4, b);
    printf("输出插入操作后单链表所有元素！\n");
    OutputList_L(L);
    printf("删除单链表第3个位置的元素!\n");
    ListDelete_L(L, 3, d);
    printf("输出删除操作后单链表所有元素！\n");
    OutputList_L(L);
}