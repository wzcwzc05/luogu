#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int cmp(char *a, char *b)
{
    return *a - *b;
}
int main()
{
    char str1[100], str2[100], str[100];
    scanf("%s", str1);
    scanf("%s", str2);
    strcat(str1, str2);
    qsort(str1, strlen(str1), sizeof(char), cmp);
    printf("%s\n", str1);
    return 0;
}