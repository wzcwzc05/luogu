#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#define LIST_INIT_SIZE 100  // 线性表存储空间的初始分配量
#define LISTINCREMENT 10    // 线性表存储空间的分配增量
#define ElemType int        // 线性表中元素的类型
#define Status int  // 函数状态返回类型，0表示成功，1表示失败
typedef struct {
    ElemType *elem;  // 存储空间基址
    int length;      // 线性表当前长度
    int listsize;  // 线性表当前分配的存储空间容量（以sizeof(ElemType）为单位）
} SqList;

Status InitList_Sq(SqList &L) {
    // 构造一个空的线性表
    L.elem = (ElemType *)malloc(LIST_INIT_SIZE * sizeof(ElemType));
    if (!L.elem) exit(OVERFLOW);  // 分配存储空间失败
    L.length = 0;                 // 空表长度为零
    L.listsize = LIST_INIT_SIZE;  // 当前分配的存储空间容量
    return 0;
}  // InitList_Sq

Status Destroy_Sq(SqList &L) {
    free(L.elem);
    L.length = 0;
    L.listsize = 0;
    return 0;
}

Status ListInsert_Sq(SqList &L, int i, ElemType e) {
    // 在线性表L的第i个位置插入元素e
    // i的合法值为1<=i<=L.length_Sq(L)+1
    if (i < 1 || i > L.length + 1) return 1;  // i值不合法
    if (L.length >= L.listsize) {
        // 分配新的存储空间
        ElemType *newbase = (ElemType *)realloc(
            L.elem, (L.listsize + LISTINCREMENT) * sizeof(ElemType));
        if (!newbase) exit(OVERFLOW);
        L.elem = newbase;             // 新基址
        L.listsize += LISTINCREMENT;  // 增加存储容量
    }
    ElemType *p, *q;
    q = &(L.elem[i - 1]);  // q为插入位置
    for (p = &(L.elem[L.length - 1]); p >= q; --p) *(p + 1) = *p;
    *q = e;
    ++L.length;
    return 0;
}  // ListInsert_Sq

Status ListDelete_Sq(SqList &L, int i, ElemType &e) {
    // 在顺序线性表L中删除第i个元素，并用e返回其值
    // i的合法值为1<=i<=ListLength_Sq(L)
    if ((i < 1) || (i > L.length)) return 1;  // i值不合法
    ElemType *p, *q;
    p = &(L.elem[i - 1]);       // p为被删除元素的位置
    e = *p;                     // 被删除元素的值赋给e
    q = L.elem + L.length - 1;  // 表尾元素的位置
    for (++p; p <= q; ++p) *(p - 1) = *p;
    --L.length;
    return 0;
}  // ListDelete_Sq

Status compare(ElemType a, ElemType b) { return a - b; }

int LocateElem_Sq(SqList L, ElemType e, Status (*compare)(ElemType, ElemType)) {
    // 在顺序线性表L中查找第1个值与e满足compare()的元素的位序
    // 若找到，则返回其在L中的位序，否则返回0
    ElemType i = 1;        // i的值为第1个元素的位序
    ElemType *p = L.elem;  // p的初值为第1个元素的存储位置
    while (i <= L.length && !(*compare)(*p++, e)) ++i;
    if (i <= L.length)
        return i;
    else
        return 0;
}  // LocateElem_Sq

int PrintElem_Sq(SqList L) {
    for (int i = 0; i < L.length; ++i) {
        printf("%d ", L.elem[i]);
    }
    return 0;
}

int main() {
    SqList L;
    InitList_Sq(L);
    printf("请输入元素个数\n");
    int n, loc;
    ElemType val, ret;
    scanf("%d", &n);
    printf("请输入n个元素\n");
    if (n <= LIST_INIT_SIZE) {
        for (int i = 0; i < n; ++i) {
            scanf("%d", &L.elem[i]);
        };
    } else {
        // 分配新的存储空间
        ElemType *newbase = (ElemType *)realloc(
            L.elem, (L.listsize + LISTINCREMENT * (n - LIST_INIT_SIZE)) *
                        sizeof(ElemType));
        if (!newbase) exit(OVERFLOW);
        L.elem = newbase;             // 新基址
        L.listsize += LISTINCREMENT;  // 增加存储容量
        for (int i = 0; i < n; ++i) {
            scanf("%d", &L.elem[i]);
        };
    }
    L.length = n;
    printf("请输入需要插入的元素位置和值\n");
    scanf("%d%d", &loc, &val);
    ListInsert_Sq(L, loc, val);
    printf("插入元素后的线性表为：\n");
    PrintElem_Sq(L);
    printf("\n");
    printf("请输入需要删除的元素位置");
    scanf("%d", &loc);
    ListDelete_Sq(L, loc, ret);
    printf("删除元素后的线性表为：\n");
    PrintElem_Sq(L);
    printf("\n");
    printf("请输入需要查找的元素的值\n");
    scanf("%d", &val);
    loc = LocateElem_Sq(L, val, &compare);
    printf("第1个为%d的元素位序为%d\n", val, loc);
    Destroy_Sq(L);
    return 0;
}