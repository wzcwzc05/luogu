#include <bits/stdc++.h>
using namespace std;
int h,n,q,a,b,startx,starty,endx,endy;
bool hs[1000005];
int memory[3][1000005];
struct Node{
  int step,x,y;  
};
int main()
{
    cin>>h>>n>>q>>a>>b;
    for (int i=1;i<=n;i++)
    {
        int temp;
        cin>>temp;
        hs[temp]=1;
    }
    while (q--)
    {
        cin>>startx>>starty>>endx>>endy;
        queue<Node> q;
        Node start;
        start.step=0;
        start.x=startx;
        start.y=starty;
        q.push(start);
        for (int i=0;i<=1;i++)
            for (int j=1;j<=h;j++)
                memory[i][j]=INT_MAX;
        while (!q.empty())
        {
            Node now=q.front();
            if (now.x==endx && now.y==endy)
            {
                cout<<now.step<<"\n";
                break;
            }
            q.pop();
            if (hs[now.y]==1 && now.step<memory[!now.x][now.y])
            {
                Node temp;
                temp.x=!now.x;
                temp.y=now.y;
                temp.step=now.step;
                memory[temp.x][temp.y]=temp.step;
                q.push(temp);
            }
            if (now.step+a<memory[now.x][now.y+1] && now.y+1<=h)
            {
                Node temp;
                temp.x=now.x;
                temp.y=now.y+1;
                temp.step=now.step+a;
                memory[temp.x][temp.y]=temp.step;
                q.push(temp);
            }
            if (now.step+b<memory[now.x][now.y-1] && now.y-1>=1)
            {
                Node temp;
                temp.x=now.x;
                temp.y=now.y-1;
                temp.step=now.step+b;
                memory[temp.x][temp.y]=temp.step;
                q.push(temp);
            }
        }
    }
    return 0;
}