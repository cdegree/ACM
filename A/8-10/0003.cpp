#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
struct node
{
    int l,r;
    int v;
} t[400000];
int n,m;
int c,le,ri;
int a;
const int mod = 10007;
void build(int ll,int rr,int rot)
{
    t[rot].l=ll;
    t[rot].r=rr;
    t[rot].v=-1;
    if(ll==rr)return;
    else
    {
        int mid=(ll+rr)/2;
        build(ll,mid,rot<<1);
        build(mid+1,rr,rot<<1|1);
    }
}
void push(int rot)
{
    t[rot<<1].v=t[rot<<1|1].v=t[rot].v;
    t[rot].v=-1;

}
void update1(int ll,int rr,int rot,int val)
{
    //printf(" l=%d,r=%d from %d to %d  val[%d]=%d\n",t[rot].l,t[rot].r,ll,rr,rot,t[rot].v);
    if(t[rot].l==ll&&t[rot].r==rr&&t[rot].v!=-1)
    {
        t[rot].v=(val+t[rot].v)%mod;
    }
    else
    {
        if(t[rot].v!=-1)push(rot);
        int mid=(t[rot].l+t[rot].r)/2;
        if(ll>mid)update1(ll,rr,rot<<1|1,val);
        else if(rr<=mid)update1(ll,rr,rot<<1,val);
        else
        {
            update1(ll,mid,rot<<1,val);
            update1(mid+1,rr,rot<<1|1,val);
        }
    }
}
void update2(int ll,int rr,int rot, int val)
{
    if(t[rot].l==ll&&t[rot].r==rr&&t[rot].v!=-1)
    {
        t[rot].v=(t[rot].v*val)%mod;
    }
    else
    {
        if(t[rot].v!=-1)push(rot);
        int mid=(t[rot].l+t[rot].r)/2;
        if(ll>mid)update2(ll,rr,rot<<1|1,val);
        else if(rr<=mid)update2(ll,rr,rot<<1,val);
        else
        {
            update2(ll,mid,rot<<1,val);
            update2(mid+1,rr,rot<<1|1,val);
        }
    }
}
void update3(int ll,int rr,int rot,int val)
{
    if(t[rot].l==ll&&t[rot].r==rr)
    {
        t[rot].v=val;
    }
    else
    {
        if(t[rot].v!=-1)push(rot);
        int mid=(t[rot].l+t[rot].r)/2;
        if(ll>mid)update3(ll,rr,rot<<1|1,val);
        else if(rr<=mid)update3(ll,rr,rot<<1,val);
        else
        {
            update3(ll,mid,rot<<1,val);
            update3(mid+1,rr,rot<<1|1,val);
        }
    }
}
int query(int ll,int rr,int rot,int f)
{
    //printf("rt=%d %d\n",rot,t[rot].v);
    if(t[rot].v!=-1)
    {
        long long int s=1;
        for(int i=0; i<f; i++)s*=t[rot].v;
        return (int)((s*(rr-ll+1))%mod);
    }
    else
    {
        int mid=(t[rot].l+t[rot].r)/2;
        //printf("%d -> %d  mid = %d\n",t[rot].l,t[rot].r,mid);
        if(rr<=mid)return query(ll,rr,rot<<1,f)%mod;
        else if(ll>mid)return query(ll,rr,rot<<1|1,f)%mod;
        else
        {
            return (query(ll,mid,rot<<1,f)+query(mid+1,rr,rot<<1|1,f))%mod;
        }
    }
}

int main()
{
    int n,m;
    while(~scanf("%d%d",&n,&m))
    {
        if(n==0&&m==0)break;
        build(1,n,1);
        t[1].v=0;
        int q,x,y,c;
        while(m--)
        {
            scanf("%d %d %d %d",&q,&x,&y,&c);
            if(q==1)
            {
                update1(x,y,1,c);
            }
            else if(q==2)
            {
                update2(x,y,1,c);
            }
            else if(q==3)
            {
                update3(x,y,1,c);
            }
            else
            {
                int res = query(x,y,1,c)%10007;
                printf("%d\n",res);
            }
        }
    }
    return 0;
}
