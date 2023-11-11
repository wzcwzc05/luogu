#include <bits/stdc++.h>
using namespace std;
struct Time{
    int hour;
    int minute;
    int second;
    int sum;
};
int n,m,a,c,b;
Time t[5005];
bool cmp(Time x,Time y)
{
    return x.sum<y.sum;
}
int main()
{
    cin>>n;
    for (int i=1;i<=n;i++){
        cin>>a>>b>>c;
        t[i].hour=a;
        t[i].minute=b;
        t[i].second=c;
        t[i].sum=a*3600+b*60+c;
    }
    sort(t+1,t+n+1,cmp);
    for (int i=1;i<=n;i++)
    cout<<t[i].hour<<" "<<t[i].minute<<" "<<t[i].second<<"\n";
    return 0;
}