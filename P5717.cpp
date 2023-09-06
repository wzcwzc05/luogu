#include <bits/stdc++.h>
using namespace std;

int t[10];

int main()
{
    cin>>t[0]>>t[1]>>t[2];
    sort(t,t+3);
    int a=t[0],b=t[1],c=t[2];
    if (a+b<=c)
    {
        printf("Not triangle\n");
        return 0;
    }
    if (a*a+b*b==c*c)
    printf("Right triangle\n");
    if (a*a+b*b>c*c)
    printf("Acute triangle\n");
    if (a*a+b*b<c*c)
    printf("Obtuse triangle\n");
    if (a==b || b==c || a==c)
    printf("Isosceles triangle\n");
    if (a==b && b==c)
    printf("Equilateral triangle\n");
    return 0;
}
