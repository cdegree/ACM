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
#define sqr(x) (x)*(x)
using namespace std;
const double PI = acos(-1.0);
map<int,int>::iterator it;
typedef long long LL ;
#pragma comment(linker,"/STACK:102400000,102400000")


bool dig[11];
const int N = 10005;
int e[5];
void init()
{
    e[0]=1;
    for(int i=1; i<5; ++i)
    {
        e[i]=e[i-1]*10;
    }
}
struct bignum
{
    int d[N];
    int n;
    bignum() {};
    bignum(int x)
    {
        (*this).n=0;
        while(x>0)
        {
            (*this).d[(*this).n++]=x%10;
            x/=10;
        }
    }
    bignum multiply(bignum y)
    {
        bignum ret;
        for(int i=0; i<=y.n+n; ++i)ret.d[i]=0;
        for(int i=0; i<y.n; ++i)
        {
            for(int j=0; j<n; ++j)
            {
                ret.d[i+j] += y.d[i]*d[j];
            }
        }
        for(int i=0; i<y.n+n; ++i)
        {
            ret.d[i+1]+=ret.d[i]/10;
            ret.d[i]%=10;
        }
        int pos=0;
        for(int i=y.n+n; i>=0; --i)if(ret.d[i]!=0)
            {
                pos=i;
                break;
            }
        ret.n=pos+1;
        //printf("pos=%d\n",pos);
        return ret;
    }
    void operator =(int x)
    {
        (*this).n=0;
        while(x>0)
        {
            (*this).d[(*this).n++]=x%10;
            x/=10;
        }
    }
    void operator =(bignum x)
    {
        (*this).n=x.n;
        for(int i=0;i<x.n;++i)(*this).d[i]=x.d[i];
    }
    bool OK()
    {
        for(int i=0; i<n; ++i)
        {
            if(dig[ d[i] ])return false;
        }
        return true;
    }
    void pf()
    {
        for(int i=n-1; i>=0; --i)
        {
            printf("%d",d[i]);
        }
        puts("");
    }
};
int n,m;
const int M = 10000;
int main()
{
    /*
    bignum p=99;
    bignum q=99;
    p.multiply(q);
    p.pf();
    */
    int T=1;
    //freopen("Kout.txt","w",stdout);
    while(~scanf("%d%d",&n,&m))
    //for(n=10000;n>=1;--n)
    {
        //m=1;
        memset(dig,0,sizeof(dig));
        int a;
        //for(int i=0;i<10;++i)dig[i]=1;
        //dig[1]=0;
        for(int i=0; i<m; ++i)
        {
            scanf("%d",&a);
            dig[a]=1;
        }
        //printf("n = %d\n",n);
        printf("Case %d: ",T++);
        bignum b=n;
        bignum x=n;
        if(b.d[0]==0&&dig[0])
        {
            puts("-1");
            continue;
        }
        int len=1;
        bignum y ;
        while(len<M)
        {
            y = b.multiply(len++);
            if(y.OK())break;
        }
        if(len<M)y.pf();
        else puts("-1");
    }
    return 0;
}
