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
#include <set>
#define X first
#define Y second
using namespace std;

typedef long long LL ;

#define lson L,mid,rt<<1
#define rson mid+1,R,rt<<1|1
#define lc rt<<1
#define rc rt<<1|1




int r,n,m;
struct Matrix
{
    int data[2][2];
    void multilply(Matrix a,Matrix b)
    {
        data[0][0] = a.data[0][0]*b.data[0][0] + a.data[0][1]*b.data[1][0];
        data[0][1] = a.data[0][0]*b.data[0][1] + a.data[0][1]*b.data[1][1];
        data[1][0] = a.data[1][0]*b.data[0][0] + a.data[1][1]*b.data[1][0];
        data[1][1] = a.data[1][0]*b.data[0][1] + a.data[1][1]*b.data[1][1];
        for(int i=0; i<2; ++i)for(int j=0; j<2; ++j)data[i][j]%=r;
    }
} M[30003];
void pf(Matrix res)
{
    //puts("ok1");
    for(int i=0; i<2; ++i)
    {
        printf("%d %d\n",res.data[i][0],res.data[i][1]);
    }
    //puts("ok2");
}
const int N = 30003;
struct Segment_Tree
{
    Matrix m[N*4];
    int left[N*4],right[N*4];
    void Build(int L,int R,int rt)
    {
        if(L==R)
        {
            m[rt]=M[L];
        }
        else
        {
            int mid = (L+R)>>1;
            Build(lson);
            Build(rson);
            Push_Up(rt);
        }
    }
    void Push_Up(int rt)
    {
        m[rt].multilply(m[lc],m[rc]);
    }
    Matrix Query(int L,int R,int rt,int from,int to)
    {
        if(from<=L&&R<=to)
        {
            Matrix ret=m[rt];
            return ret;
        }
        else
        {
            int mid = (L+R)>>1;
            Matrix ret;
            ret.data[0][0]=ret.data[1][1]=1;
            ret.data[1][0]=ret.data[0][1]=0;
            //printf("ret = \n");
            //pf(ret);
            if(from<=mid)
            {
                //pf(ret);
                //printf(" * \n");
                ret.multilply(ret,Query(L,mid,lc,from,to));
                //pf(Query(L,mid,lc,from,to));
                //printf(" = \n");
                //pf(ret);
            }
            //pf(ret);
            if(to>mid)
            {
                ret.multilply(ret,Query(mid+1,R,rc,from,to));
            }
            //printf("ret = \n");
            //pf(ret);
            return ret;
        }
    }
}Seg;



/*
Matrix get_ans(Matrix a,Matrix b)
{
    Matrix ret ;
    int x ;
    int y ;
    int a1 = a.data[0][0];
    int a2 = a.data[1][0];
    int b1 = a.data[0][1];
    int b2 = a.data[1][1];
    int c1 = b.data[0][0];
    int c2 = b.data[1][0];
    if((a1*b2-a2*b1)==0||(a2*b1-a1*b2)==0)puts("NO");
    x = (b2*c1-b1*c2)/(a1*b2-a2*b1);
    y = (a2*c1-a1*c2)/(a2*b1-a1*b2);
    x %= r;
    y %= r;
    ret.data[0][0]=x;
    ret.data[1][0]=y;
    a1 = a.data[0][0];
    a2 = a.data[1][0];
    b1 = a.data[0][1];
    b2 = a.data[1][1];
    c1 = b.data[0][1];
    c2 = b.data[1][1];
    x = (b2*c1-b1*c2)/(a1*b2-a2*b1);
    y = (a2*c1-a1*c2)/(a2*b1-a1*b2);
    x %= r;
    y %= r;
    ret.data[0][1]=x;
    ret.data[1][1]=y;
    return ret;
}
*/

int main()
{
    int T=0;
    Matrix ret1,ans;
    /*
    r=9;
    ret1.data[0][0]=ret1.data[1][1]=1;
    ret1.data[1][0]=ret1.data[0][1]=0;
    ans.data[0][0]=0;
    ans.data[0][1]=1;
    ans.data[1][1]=0;
    ans.data[1][0]=0;
    ret1.multilply(ret1,ans);
    pf(ret1);

    while(1)puts("Fuck");
    */
    while(cin>>r>>n>>m)
    {
        if(T!=0)puts("");
        ++T;
        for(int i=1; i<=n; ++i)
        {
            scanf("%d %d %d %d",&M[i].data[0][0],&M[i].data[0][1],&M[i].data[1][0],&M[i].data[1][1]);
        }
        Seg.Build(1,n,1);
        while(m--)
        {
            int from,to;
            scanf("%d%d",&from,&to);
            Matrix res = Seg.Query(1,n,1,from,to);
            pf(res);
            if(m!=0)puts("");
        }
    }
    return 0;
}
