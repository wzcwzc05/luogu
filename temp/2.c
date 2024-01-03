#include <stdio.h>
int n, a[1000], ans[1000], t;
void decompose(int t, int *s, int *count)
{
    for (int i = 2; t != 1 && i <= t; i++)
    {
        if (t % i == 0)
        {
            while (t % i == 0)
                t = t / i;
            int flag = 0;
            for (int j = 1; j <= *count; j++)
            {
                if (s[j] == i)
                {
                    flag = 1;
                    break;
                }
            }
            if (flag == 0)
            {
                ++*count;
                s[*count] = i;
            }
        }
    }
    return;
}
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        int temp;
        scanf("%d", &temp);
        decompose(temp, ans, &t);
    }
    for (int i = 1; i <= t - 1; i++)
        for (int j = i + 1; j <= t; j++)
            if (ans[i] > ans[j])
            {
                int temp = ans[i];
                ans[i] = ans[j];
                ans[j] = temp;
            }
    for (int i = 1; i <= t; i++)
        printf("%d ", ans[i]);
    printf("\n");
    return 0;
}