#include<stdio.h>
long long qu(long long q[],long long n,long long obj){
    long long id=n/2;
    for(long long left=0,right=n-1;obj!=q[id]&&left<right-1;id=(left+right)/2){
        if(obj<q[id]){
            right=id;
        }
        else{
            left=id;
        }
    }
    if(obj==q[id]){
        while(q[id-1]==q[id]) id--;
        for(long long left=0,right=id;obj!=q[id]&&left<right-1;id=(left+right)/2){
        if(obj<q[id]){
            right=id;
        }
        else{
            left=id;
        }
    }
        return id+1;
    }
    else{
        return -1;
    }
}
int main(void)
{
    long long n,m;
    scanf("%lld%lld",&n,&m);
    long long a[n],b[m];
    for(long long i=0;i<n;i++){
        scanf("%lld",&a[i]);
    }
    for(long long i=0;i<m;i++){
        scanf("%lld",&b[i]);
    }
    for(long long i=0;i<m;i++){
        printf("%lld ",qu(a,n,b[i]));
    }
    return 0;
}
