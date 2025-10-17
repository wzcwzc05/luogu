/*3250. 通信网络*/
#include<bits/stdc++.h>
using namespace std;
int N,M,x,y,sum;
bool a[1050][1050];
int main(void)
{
    cin>>N>>M;
    for(int i=1;i<=N;i++){
        a[i][i]=true;
    }
    for(int i=0;i<M;i++){
        cin>>x>>y;
        a[x][y]=true;
    }
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            if(i!=j&&a[i][j]==true){
                for(int k=1;k<=N;k++){
                    if(a[j][k]==true){
                        a[i][k]=true;
                    }
                }
            }
        }
    }
    for(int i=1;i<=N;i++){
        int tmp=0;
        for(int j=1;j<=N;j++){
            if(a[i][j]==true){
                tmp++;
            }
        }
        if(tmp==N) sum++;
        else{
            tmp=0;
            for(int j=1;j<=N;j++){
                if(a[j][i]==true){
                    tmp++;
                }
            }
            if(tmp==N) sum++;
        }
    }
    cout<<sum;
    return 0;
}