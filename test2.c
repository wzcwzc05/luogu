#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void string_sort_ascii(char *strings[], int num);   // 以ASCII中的顺序对字符串进行排序
void string_sort_strlen(char *strings[], int num);  // 按长度递增顺序对字符串进行排序
void string_sort_wordlen(char *strings[], int num); // 按第1个单词长度递增顺序对字符串进行排序
char *s_gets(char *st, int n);
int main(void)
{
    char a[10][130];
    char *p[10];
    int i = 0, k = 0;
    while (i < 10 && s_gets(a[i], 130) && a[i][0] != '\0')
    {
        p[i] = a[i];
        i++;
    }
    for (k = 0; k < i; k++)
        puts(p[k]);
    puts("");
    string_sort_ascii(p, i);
    for (k = 0; k < i; k++)
        puts(p[k]);
    puts("");
    string_sort_strlen(p, i);
    for (k = 0; k < i; k++)
        puts(p[k]);
    puts("");
    string_sort_wordlen(p, i);
    for (k = 0; k < i; k++)
        puts(p[k]);
    return 0;
}

void string_sort_ascii(char *strings[], int num)
{
    int j = 0, i = 0, k1 = 0;
    char *temp;
    for (i = 0; i < num; i++)
    {

        for (j = i + 1; j < num; j++)
        {
            for (k1 = 0; k1 < 130 && strings[i][k1] == strings[j][k1]; k1++)
                ;
            if (strings[i][k1] > strings[j][k1])
            {
                temp = strings[i];
                strings[i] = strings[j];
                strings[j] = temp;
            }
        }
    }
}

void string_sort_strlen(char *strings[], int num)
{
    int j = 0, i = 0;
    char *temp;
    for (i = 0; i < num - 1; i++)
    {
        int minj = i;
        for (j = i + 1; j < num; j++)
        {
            if (strlen(strings[minj]) > strlen(strings[j]))
            {
                minj = j;
            }
        }
        if (minj != i)
        {
            temp = strings[i];
            strings[i] = strings[minj];
            strings[minj] = temp;
        }
    }
}

void string_sort_wordlen(char *strings[], int num)
{
    int a1[num];
    int j = 0, i = 0;
    char *temp;
    for (i = 0; i < num; i++)
    {
        for (j = 0; j < 130 && strings[i][j] != ' '; j++)
        {
            ;
        }
        a1[i] = j;
    }
    for (i = 0; i < num; i++)
    {
        int minj = i;
        for (j = i; j < num; j++)
        {
            if (a1[minj] > a1[j])
                minj = j;
        }
        if (minj != i)
        {
            temp = strings[i];
            strings[i] = strings[minj];
            strings[minj] = temp;
            int b;
            b = a1[i];
            a1[i] = a1[minj];
            a1[minj] = b;
        }
    }
}

char *s_gets(char *st, int n)
{
    char *ret_val;
    int i = 0;
    ret_val = fgets(st, n, stdin);
    if (ret_val)
    {
        while (st[i] != '\n' && st[i] != '\0')
            i++;
        if (st[i] == '\n')
            st[i] = '\0';
        else
            while (getchar() != '\n')
                continue;
    }
    return ret_val;
}