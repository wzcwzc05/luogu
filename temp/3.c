#include <stdio.h>
int main()
{
    int red, green, yellow, n, nowtime, c;
    scanf("%d%d%d", &red, &yellow, &green);
    c = red + yellow + green;
    scanf("%d", &n);
    nowtime = 0;
    for (int i = 1; i <= n; i++)
    {
        int type, ptime;
        scanf("%d%d", &type, &ptime);
        if (type == 0)
        {
            nowtime += ptime;
        }
        else if (type == 1)
        {
            int t = yellow + green + ptime;
            if (nowtime <= t && nowtime >= ptime + yellow)
                continue;
            else if (nowtime < ptime + yellow)
                nowtime += ptime + yellow - nowtime;
            else if (nowtime > t)
            {
                int r = (nowtime - t) % c;
                if (r <= red + yellow)
                    nowtime += red + yellow - r;
                else
                    continue;
            }
        }
        else if (type == 2)
        {
            int t = green + ptime;
            if (nowtime <= t && nowtime >= ptime)
                continue;
            else if (nowtime < ptime)
                nowtime += ptime - nowtime;
            else if (nowtime > t)
            {
                int r = (nowtime - t) % c;
                if (r <= red + yellow)
                    nowtime += red + yellow - r;
                else
                    continue;
            }
        }
        else if (type == 3)
        {
            int t = ptime;
            if (nowtime <= t)
                continue;
            else
            {
                int r = (nowtime - t) % c;
                if (r <= red + yellow)
                    nowtime += red + yellow - r;
                else
                    continue;
            }
        }
    }
    printf("%d\n", nowtime);
    return 0;
}