#include <stdio.h>
#include <ctype.h>
#pragma GCC optimize(2)
char get_first(void);
int main(void)
{
    float a, b, out;
    char ch;
    while ((ch = get_first()) != 'q')
    {
        if (ch == 'a' || ch == 's' || ch == 'm' || ch == 'd')
            if (scanf("%lf %lf", &a, &b) == 2)
            {
                if (ch == 'a')
                {
                    out = a + b;
                    printf("%.2lf\n", out);
                }
                else if (ch == 's')
                {
                    out = a - b;
                    printf("%.2lf\n", out);
                }
                else if (ch == 'm')
                {
                    out = a * b;
                    printf("%.2lf\n", out);
                }
                else if (ch == 'd' && b != 0)
                {
                    out = a / b;
                    printf("%.2lf\n", out);
                }
                else
                {
                    printf("invalid\n");
                    char c;
                    while ((c = getchar()) != EOF && c != '\n');
                }
            }
            else
            {
                printf("invalid\n");
                char c;
                while ((c = getchar()) != EOF && c != '\n');
            }
        else
        {
            printf("invalid\n");
        }
    }
    return 0;
}

char get_first(void)
{
    int ch;
    do
    {
        ch = getchar();
        if (ch == '\n' || ch == ' ')
        { // 如果是换行符或空格，继续读取下一个字符
            continue;
        }
        else
        {
            while (getchar() != '\n') // 清空输入缓冲区
                continue;
            return tolower(ch); // 转换为小写并返回
        }
    } while (1);
}
