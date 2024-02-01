#include <stdio.h>
#include <malloc.h>
struct SNode
{
    int num;            /*数值*/
    struct SNode *next; /*下一个节点地址*/
};
struct SNode* addtail(struct SNode* head, int num) {
    struct SNode* newNode = (struct SNode*)malloc(sizeof(struct SNode));
    newNode->num = num;
    newNode->next = NULL;

    if (head == NULL) {
        return newNode;
    }

    struct SNode* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    return head;
}

struct SNode* insert(struct SNode* head, struct SNode* p) {
    if (head == NULL || p->num < head->num) {
        p->next = head;
        return p;
    }

    struct SNode* current = head;
    while (current->next != NULL && current->next->num < p->num) {
        current = current->next;
    }

    p->next = current->next;
    current->next = p;
    return head;
}

struct SNode* sort(struct SNode* head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }

    struct SNode* sorted = NULL;
    struct SNode* current = head;
    struct SNode* nextNode = NULL;

    while (current != NULL) {
        nextNode = current->next;
        sorted = insert(sorted, current);
        current = nextNode;
    }

    return sorted;
}

void write(struct SNode* p) {
    while (p != NULL) {
        printf("%d ", p->num);
        p = p->next;
    }
    printf("\n");
}

void freelink(struct SNode* head) {
    struct SNode* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main()
{
    struct SNode *head = NULL;
    int num;
    do
    {
        scanf("%d", &num);
        if (num != -1)
            head = addtail(head, num);
    } while (num != -1);
    head = sort(head);
    write(head);
    freelink(head);
    return 0;
}
