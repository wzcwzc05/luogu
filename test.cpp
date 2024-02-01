#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct stud {
    int num;
    struct stud* next;
} stud;
int main()
{
    struct stud *p, *head = NULL;
    do {
        p = (struct stud*)malloc(sizeof(struct stud));
        scanf("%d ", &p->num);
        p->next = head;
        head = p;
    } while (p->num != -1);

    for (p = head; p != NULL; p = p->next)
        printf("%d\n", p->num);
    return 0;
}