#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include  <set>
#include <queue>
#define eps 1e-9
using namespace std;
struct edges
{
    int  v,next;
    double c,t;
}e[40020];
struct point
{
    double c,t;
    int step;
}p[100];
int a[2505];
int h[2505];
int vis[100];
int n,m,k;
int pre[2505];
int pr[2505];
void link(int v,int  u,double c,double t)
{
    e[++k].v=u;
    e[k].next=h[v];
    e[k].c=c;
    e[k].t=t;
    h[v]=k;
}
queue<int> s;
void find(int start)
{
    int t,i,v,u,t2;
    double c,t1;
    set<int>::iterator it;
    for(i=1;i<=n;i++)
    {
        p[i].c=-6000;
        p[i].t=1;
        vis[i]=0;
    }
    while(!s.empty())s.pop();
    v=start;
    pr[start]=start;
    s.push(start);
    p[v].c=0;
    p[v].t=0;
    p[v].step=0;
    while(!s.empty())
    {
        v=s.front();
        s.pop();
        t=h[v];
        vis[v]=0;
        while(t!=-1)
        {
            u=e[t].v;
            t1=e[t].t+p[v].t;
            c=e[t].c+p[v].c;
            if(u==start)
            {
                if(p[start].c*t1<c*p[start].t||p[start].c<eps)
                {
                    p[start].c=c;
                    p[start].t=t1;
                    pr[start]=v;
                    p[start].step=p[v].step+1;
                }
                t=e[t].next;
                continue;
            }
            t2=pr[v];
            while(1)
            {
                if(t2==start||t2==u)break;
                t2=pr[t2];
            }
            if(t2==u)
            {
                t=e[t].next;
                continue;
            }
            if(p[u].c*t1<c*p[u].t)
            {
                p[u].c=c;
                p[u].t=t1;
                pr[u]=v;
                p[u].step=p[v].step+1;
                if(!vis[u])
                {
                    s.push(u);
                    vis[u]=1;
                }
            }
            t=e[t].next;
        }
    }
}
int main()
{
    int i,step,v,u,id;
    double c,t;
   //freopen("in.txt","r",stdin);
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        k=0;
        step=0;
        memset(h,-1,sizeof(h));
        for(i=1;i<=m;i++)
        {
            scanf("%d%d%lf%lf",&v,&u,&c,&t);
            link(v,u,c,t);
        }
        c=-6000;
        t=1;
        for(i=1;i<=n;i++)
        {
            find(i);
            if(c*p[i].t<p[i].c*t)
            {
                c=p[i].c;
                t=p[i].t;
                id=i;
                pre[i]=pr[i];
                step=p[i].step;
                v=pr[i];
                while(1)
                {
                    pre[v]=pr[v];
                    if(pre[v]==i)break;
                    v=pr[v];
                }
            }
        }
        printf("%d\n",step);
        v=id;
        for(i=1;i<=step;i++)
        {
            a[i]=pre[v];
            v=pre[v];
        }
        for(i=step;i>1;i--)
        {
            printf("%d ",a[i]);
        }
        if(step)printf("%d\n",a[i]);
    }
    return 0;
}
