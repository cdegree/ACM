#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cctype>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

typedef long long LL ;

const int N = 200005;

struct segment
{
    LL sum;
    LL add;
    LL len;
} Seg[N*5];



void init(int u,int L,int R)
{
    int l=u*2,r=u*2+1;
    Seg[u].sum=Seg[u].add=0;
    Seg[u].len=R-L+1;
    if(L==R)
    {
        return ;
    }
    else
    {
        int mid = (L+R)/2;
        init(l,L,mid);
        init(r,mid+1,R);
    }
}
void push_up(int u,int l,int r)
{
    Seg[u].sum=Seg[l].sum+Seg[r].sum;
}
void push_down(int u,int l,int r)
{
    Seg[l].sum += Seg[u].add*Seg[l].len;
    Seg[l].add += Seg[u].add;
    Seg[r].sum += Seg[u].add*Seg[r].len;
    Seg[r].add += Seg[u].add;
    Seg[u].add=0;
}
void add(int u,int to,int L,int R,int val)
{
    int l=u*2,r=u*2+1;
    if(to==R)
    {
        Seg[u].sum += val*Seg[u].len;
        Seg[u].add += val;
        return ;
    }
    else
    {
        if(Seg[u].add!=0)push_down(u,l,r);
        int mid = (L+R)/2;
        if(to<=mid)add(l,to,L,mid,val);
        else
        {
            add(l,mid,L,mid,val);
            add(r,to,mid+1,R,val);
        }
        push_up(u,l,r);
    }

}
void set(int u,int pos,int val,int L,int R)
{
    int l=u*2,r=u*2+1;
    if(pos==L&&pos==R)
    {
        Seg[u].sum=val;
        Seg[u].add=0;
    }
    else
    {
        if(Seg[u].add!=0)push_down(u,l,r);
        int mid = (L+R)/2;
        if(pos<=mid)set(l,pos,val,L,mid);
        else set(r,pos,val,mid+1,R);
        push_up(u,l,r);
    }
}
void del(int u,int pos,int L,int R)
{
    int l=u*2,r=u*2+1;
    if(pos==L&&pos==R)
    {
        Seg[u].sum=0;
        Seg[u].add=0;
    }
    else
    {
        int mid = (L+R)/2;
        if(Seg[u].add!=0)push_down(u,l,r);
        if(pos<=mid)del(l,pos,L,mid);
        else del(r,pos,mid+1,R);
        push_up(u,l,r);
    }
}
int main()
{
    int T;
    scanf("%d",&T);
    int n=1;
    int len = N - 4;
    init(1,1,len);
    while(T--)
    {
        int t;
        scanf("%d",&t);
        if(t==1)
        {
            int a,x;
            scanf("%d%d",&a,&x);
            add(1,a,1,len,x);
        }
        else if(t==2)
        {
            int k;
            scanf("%d",&k);
            ++n;
            set(1,n,k,1,len);
        }
        else
        {
            del(1,n,1,len);
            --n;
        }
        //printf("sum = %.9f\n",(double)Seg[1].sum);
        printf("%.6f\n",1.0*Seg[1].sum/n);
    }
    return 0;
}
