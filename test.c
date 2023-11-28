#include <stdio.h>
double diff(double *a)
{
    double *max=a+1,*min=a+1;
    for (int i=1;i<=5;i++)
    {
        if (*(a+i)>*max)
            max=a+i;
        if (*(a+i)<*min)
            min=a+i;
    }
    return *max-*min;
}
int main()
{
    double a[10],*max,*min;
    for (int i=1;i<=5;i++)
        scanf("%lf,",&a[i]);
    printf("%.1lf\n",diff(&a));
    return 0;
}