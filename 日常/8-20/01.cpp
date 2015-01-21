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

LL mod=1000000007LL;
struct matrix
{
    LL d[4][4];
    void init()
    {
        memset(d,0,sizeof(d));
        for(int i=0; i<4; ++i)d[i][i]=1;
    }
    matrix mul(matrix b)
    {
        matrix ret;
        for(int i=0; i<4; ++i)for(int j=0; j<4; ++j)ret.d[i][j]=0;
        for(int k=0; k<4; ++k)
        {
            for(int i=0; i<4; ++i)
            {
                if(d[i][k]==0)continue;
                for(int j=0; j<4; ++j)
                {
                    ret.d[i][j]+=d[i][k]*b.d[k][j];
                    ret.d[i][j]%=mod;
                }
            }
        }
        return ret;
    }
    matrix add(matrix b)
    {
        matrix ret;
        //memset(ret.d,0,sizeof(ret.d));
        for(int i=0; i<4; ++i)
        {
            for(int j=0; j<4; ++j)
            {
                ret.d[i][j]=d[i][j]+b.d[i][j];
                ret.d[i][j]%=mod;
            }
        }
        return ret;
    }
    void pf()
    {
        for(int i=0; i<4; ++i)
        {
            for(int j=0; j<4; ++j)
            {
                printf("%I64d ",d[i][j]);
            }
            puts("");
        }
    }
};

matrix cal_Power(matrix x,LL n)
{
    matrix ret ;
    ret.init();
    if(n==0)return ret;
    if(n==1)return x;
    if(n&1)
    {
        ret = cal_Power(x,n-1);
        ret = ret.mul(x);
    }
    else
    {
        ret = cal_Power(x,n/2);
        ret = ret.mul(ret);
    }
    return ret;
}

matrix cal_sum(matrix x,LL n)
{

    if(n==0){
        matrix ret ;
        ret.init();
        return ret;
    }
    matrix ret ;
    if(1)
    {
        if(n%2==0)
        {
            matrix tmp = cal_sum(x,n/2-1);
            matrix tmp2 = cal_Power(x,n/2);
            ret = cal_Power(x,n);
            ret = ret.add(tmp);
            ret = ret.add( tmp2.mul(tmp) );
        }
        else
        {
            matrix tmp = cal_sum(x,n/2);
            matrix tmp2 = cal_Power(x,n/2+1);
            ret = tmp2.mul(tmp);
            ret = ret.add(tmp);
        }
    }
    else
    {
        if(n%3==0)
        {
            matrix tmp = cal_sum(x,(n-2)/3);
            matrix tmp2 = cal_Power(x,(n-2)/3+1);
            ret = tmp;
            ret = ret.add(tmp.mul(tmp2));
            tmp2 = tmp2.mul(tmp2);
            ret = ret.add(tmp.mul(tmp2));
            ret = ret.add(cal_Power(x,n));
        }
        else if(n%3==1)
        {
            matrix tmp = cal_sum(x,(n-2)/3);
            matrix tmp2 = cal_Power(x,(n-2)/3+1);
            ret = tmp;
            ret = ret.add(tmp.mul(tmp2));
            tmp2 = tmp2.mul(tmp2);
            ret = ret.add(tmp.mul(tmp2));
            ret = ret.add(cal_Power(x,n));
            ret = ret.add(cal_Power(x,n-1));
        }
        else
        {
            matrix tmp = cal_sum(x,(n-2)/3);
            matrix tmp2 = cal_Power(x,(n-2)/3+1);
            ret = tmp;
            ret = ret.add(tmp.mul(tmp2));
            tmp2 = tmp2.mul(tmp2);
            ret = ret.add(tmp.mul(tmp2));
        }
    }
    return ret;
}
LL n,A0,AX,AY,B0,BX,BY;
inline LL get_res( matrix ans)
{
    LL res = A0*ans.d[2][0]%mod + B0*ans.d[2][1]%mod + A0*B0%mod*ans.d[2][2]%mod
             + ans.d[2][3];
    return res%mod;
}
int main()
{
    freopen("Ain.txt","r",stdin);
    while(~scanf("%I64d%I64d%I64d%I64d%I64d%I64d%I64d",&n,&A0,&AX,&AY,&B0,&BX,&BY))
    {
        if(n==0)
        {
            puts("0");
            continue;
        }
        matrix A;
        A.d[0][0] = AX;
        A.d[0][1] = 0;
        A.d[0][2] = 0;
        A.d[0][3] = AY;
        A.d[1][0] = 0;
        A.d[1][1] = BX;
        A.d[1][2] = 0;
        A.d[1][3] = BY;
        A.d[2][0] = AX*BY%mod;
        A.d[2][1] = AY*BX%mod;
        A.d[2][2] = AX*BX%mod;
        A.d[2][3] = AY*BY%mod;
        A.d[3][0] = 0;
        A.d[3][1] = 0;
        A.d[3][2] = 0;
        A.d[3][3] = 1;
        matrix ans = cal_sum(A,n-1);
        LL res = get_res(ans);
        res %= mod;
        printf("%I64d\n",res);
        //res = get_res(tmp);
        //tmp.pf();
        //printf("%I64d\n",res);
    }
    return 0;
}
