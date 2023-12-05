#include<stdio.h>
double get_arr2d(int n,int m,double stuff[n][m]);
void max2d(int n,int m,double stuff[n][m],double *min,double *max);
void average2d(int n,int m,double stuff[n][m],double sum,double* min,double* max);
int main(void)
{
    int n,m;
    scanf("%d %d",&n,&m);
    double stuff1[n][m];
    double sum;
    sum=get_arr2d(n,m,stuff1);
    double min,max;
    max2d(n,m,stuff1,&min,&max);
    average2d(n,m,stuff1,sum,&min,&max);
    return 0;
}

double get_arr2d(int n,int m,double stuff[n][m]){
    int i,k;
    double sum=0;
    for(i=0;i<n;i++){
        for(k=0;k<m;k++){
            scanf("%lf",&stuff[i][k]);
            sum+=stuff[i][k];
        }
    }
    return sum;
}
void max2d(int n,int m,double stuff[n][m],double *min1,double *max1){
    int i,k;
    *min1=stuff[0][0];
    *max1=stuff[0][0];
    for(i=0;i<n;i++){
        for(k=0;k<m;k++){
            if(stuff[i][k]<*min1){
                *min1=stuff[i][k];
            }
            if(stuff[i][k]>*max1){
                *max1=stuff[i][k];
            } 
        }
    }
    for(i=0;i<n;i++){
        for(k=0;k<m;k++){
            printf("%lf ",stuff[i][k]);
        }
        printf("\n");
    }
}

void average2d(int n,int m,double stuff[n][m],double sum,double* min2,double* max2){
    double average;
    average=(sum-*min2-*max2)/(n*m);
    printf("%.1lf %.1lf %.1lf",*max2,*min2,average);
}