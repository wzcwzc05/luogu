#include <stdio.h>
#include <stdlib.h>
#define LIST_INIT_SIZE 100  // 线性表存储空间的初始分配量
#define ElemType int        // 线性表中元素的类型
#define Status int  // 函数状态返回类型，0表示成功，1表示失败
typedef struct {
    ElemType *elem;  // 线性表存储空间
    int length;      // 线性表当前长度
    int listsize;    // 线性表存储空间的总大小
} List;

Status InitList(List *plist) {  // 初始化线性表
    plist->elem = (ElemType *)malloc(LIST_INIT_SIZE * sizeof(ElemType));
    if (plist->elem == NULL) {
        return 1;
    }
    plist->length = 0;
    plist->listsize = sizeof(ElemType) * LIST_INIT_SIZE;
    return 0;
}

Status DestroyList(List *plist) {  // 销毁线性表
    free(plist->elem);
    plist->elem = NULL;
    plist->length = 0;
    plist->listsize = 0;
    return 0;
}
Status ClearList(List *plist) {  // 清空线性表
    plist->length = 0;
    return 0;
}
Status ResizeList(List *plist, int newsize) {  // 调整线性表存储空间大小
    ElemType *newelem =
        (ElemType *)realloc(plist->elem, newsize * sizeof(ElemType));
    if (newelem == NULL) {
        return 1;
    }
    plist->elem = newelem;
    plist->listsize = newsize * sizeof(ElemType);
    return 0;
}
Status InsertList(List *plist, int pos, ElemType elem) {  // 插入元素
    if (pos < 0 || pos > plist->length) {
        return 1;
    }
    if (ResizeList(plist, plist->listsize / sizeof(ElemType) + 100) == 1) {
        return 1;
    }

    for (int i = plist->length - 1; i >= pos; i--) {
        plist->elem[i + 1] = plist->elem[i];
    }
    plist->elem[pos] = elem;
    plist->length++;
    return 0;
}
Status DeleteList(List *plist, int pos,
                  ElemType *pelem) {  // 删除指定位置的元素
    if (pos < 0 || pos >= plist->length) {
        return 1;
    }
    *pelem = plist->elem[pos];
    for (int i = pos + 1; i < plist->length; i++) {
        plist->elem[i - 1] = plist->elem[i];
    }
    plist->length--;
    if (plist->length < plist->listsize / sizeof(ElemType) - 100) {
        ResizeList(plist, plist->listsize / sizeof(ElemType) - 100);
    }
    return 0;
}
Status LocateElem(List *plist, ElemType elem,  // 定位元素的位置
                  Status (*compare)(ElemType, ElemType)) {  // 自定义比较函数
    for (int i = 0; i < plist->length; i++) {
        if (compare(plist->elem[i], elem) == 0) {
            return i;
        }
    }
    return 0;
}
Status compare(ElemType a, ElemType b) { return a - b; }
Status PrintList(List *plist) {
    for (int i = 0; i < plist->length; i++) {
        printf("%d ", plist->elem[i]);
    }
    printf("\n");
}
int main() {
    List list;
    InitList(&list);
    int n;
    printf("请输入元素个数：");
    scanf("%d", &n);
    printf("请输入元素：");
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        InsertList(&list, i, x);
    }
    printf("请输入需要插入的元素的位置和值：");
    int pos, val;
    scanf("%d%d", &pos, &val);
    InsertList(&list, pos, val);
    PrintList(&list);
    ElemType elem;
    printf("请输入需要删除的元素的位置：");
    scanf("%d", &pos);
    DeleteList(&list, pos, &elem);
    PrintList(&list);
    DestroyList(&list);
    return 0;
}