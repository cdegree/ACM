#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>
#include <vector>
#define inf 1111111111
using namespace std;
int n,m;
int a[220000];
int b[220000];
int sum[22000];
int c[3];
int main()
{
    int i,j,flag,id,tt,t;
    int Min[10];
    //freopen("in.txt","r",stdin);
    while(~scanf("%d",&n))
    {
        flag=0;
        for(i=0;i<=3;i++)Min[i]=inf;
        for(i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
            if(a[i]!=-1&&(i%3)!=0)
            {
                flag=1;
                t=i;
            }
        }
        for(i=1;i<=n;i++)scanf("%d",&sum[i]);
        b[0]=0;
        b[1]=sum[1];
        Min[1]=min(b[1],Min[1]);
        for(i=1;i<n;i++)
        {
            b[i+1]=sum[i]-b[i-1]-b[i];
            Min[(i+1)%3]=min(b[i+1],Min[(i+1)%3]);
        }
        c[0]=0;
        if(flag)
        {
            tt=a[t]-b[t];
            if(t%3==2)tt=-tt;
            c[1]=tt;
            c[2]=-tt;
        }
        else if(n%3==1)
        {
            tt=sum[n]-b[n-1]-b[n];
            c[1]=tt;
            c[2]=-tt;
        }
        else if(n%3==0)
        {
            tt=sum[n]-b[n]-b[n-1];
            c[2]=tt;
            c[1]=-tt;
        }
        else
        {
            c[1]=min(0,Min[2]);
            c[2]=Min[1];
        }
        scanf("%d",&m);
        for(i=1;i<=m;i++)
        {
            scanf("%d",&id);
            id++;
            printf("%d\n",b[id]+c[id%3]);
        }
    }
    return 0;
}
