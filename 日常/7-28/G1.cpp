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
#define naxx 10000006
#define ll long long
using namespace std;
typedef unsigned long long ull;
const long long qwss=46856248255981LL;
int alre[naxx],vis[naxx]= {0},sum=0;
ll mif,ans;
class about
{
public:
    void init();
    ull jidi,times;
} sa[70];
void about::init()
{
    jidi=times=0;
}
void make()//С����ô...ֱ��ɸ���ȸ��£�alre�Ǽ�¼���й�������С�����������ĸ�
{
    memset(vis,true,sizeof(vis));
    vis[1]=false;
    for(int i=2;i<N;++i)
    {
        if(vis[i])
        {
            for(int j=i+i;j<N;j+=i)
            {
                vis[j]=false;
            }
        }
    }
}
void init()
{

}
ull mul(const ull &x,const ull &y,const ull &n) //�����������ģN�Ľ��
{
    ull ret=0,res=x,yy=y;
    for (; yy; yy>>=1)
    {
        if (yy&1)
        {
            ret+=res;
            if (ret>=n) ret-=n;
        }
        res<<=1;
        if (res>=n) res-=n;
    }
    return ret;
}
ull power(const ull &a,const ull &b,const ull &n)//������ģN�Ľ��
{
    if (!b) return 1;
    if (b == 1) return a;
    if (b & 1) return mul (power (mul (a, a , n), b >> 1 ,n), a , n) % n;
    return power (mul (a , a , n), b >> 1, n ) % n;
}
bool check(const ull &a,const ull &n) //������AΪ�׵Ļ�N�ܷ�ͨ����������
{
    if ((n==2)||(n==a)) return 1;
    if ((n==1)||(!(n&1))||(n==46856248255981LL)) return 0;
    ull d=n-1;
    while (!(d&1)) d>>=1;
    ull t=power(a % n,d ,n);
    while (d!=n-1&&t!=1&&t!=n-1)
        t=mul(t,t,n),d<<=1;
    return (t==n-1)||(d&1);
}
ull gcd(ull x, ull y)//������ȡ�������˵...
{
    int k = 0;
    while (!(x & 1) && !(y & 1)) k++, x >>= 1, y >>= 1;
    while (x && y)
    {
        if (!(x & 1)) x >>= 1;
        else if (!(y & 1)) y >>= 1;
        else if (x > y) x -= y;
        else y -= x;
    }
    if (x) return x << k;
    return y << k;
}
ull iabs(const ull &x)
{
    return x>0?x:-x;
}
ull rho(const ull &n) //�ֽ��N��ĳһ������
{
    //RHOα������̣�F[X]=X^2+a   ���ݴ���ţ��˵����+12323���Էǳ���ķֽ��ĳһ��.. ��ʼ״̬ô...

//��ʵ�ϣ�X,Yͬʱȡ2�Ļ�..������4��ʱ�����ѭ��������С����Ҫ����
    ull x,y,z;
    x=y=2;
    while (true)
    {
        x=mul(x,x,n)+12323;
        while (x>=n) x-=n;
        y=mul(y,y,n)+12323;
        while (y>=n) y-=n;
        y=mul(y,y,n)+12323;
        while (y>=n) y-=n;
        z=gcd(iabs(x-y),n);
        if ((z!=1)&&(z!=n)) break;
    }
    return z;
}
void fenjie(ull n) //�ֽ�N�������,ʹ�ö������ﵽĿ��
{
    queue<ull> q;
    //int alre[naxx];
    //memset(alre,0,sizeof(alre));
    while (!q.empty()) q.pop();
    q.push(n);
    sum=0;
    while (!q.empty())
    {
        ull x=q.front();
        q.pop();
        if (x<naxx)
        {
            //ull uuu=alre[x];
            if (alre[x]==x)
            {
                int i;
                for (i=1; i<=sum+1; ++i)
                {
                    if (i==sum+1) break;
                    if (sa[i].jidi==x)
                    {
                        sa[i].times++;
                        break;
                    }
                }
                if (i==sum+1)
                {
                    sa[++sum].jidi=x;
                    sa[sum].times=1;
                }
            }
            else
            {

                q.push(alre[x]),q.push(x/alre[x]);
            }
        }
        else
        {
            if (check(2,x)&&check(3,x)&&check(7,x)&&check(61,x)&&check(24251,x)) //��ʾͨ����5����������Ŀ��Χ�ھͻ�������������

//��Ȼ��ע��CHECK���������Ǹ��޴������..�Ǹ��Ǹ�ǿα����...���й�..
            {
                int i;
                for (i=1; i<=sum+1; ++i)
                {
                    if (i==sum+1) break;
                    if (sa[i].jidi==x)
                    {
                        sa[i].times++;
                        break;
                    }
                }
                if (i==sum+1)
                {
                    sa[++sum].jidi=x;
                    sa[sum].times=1;
                }
            }
            else
            {
                ull one=rho(x);
                q.push(one);
                q.push(x/one);
            }
        }
    }
}
map<ull,bool>mp1;
ull u1,su;
void dfs1(ull u,ull o)
{
    if(u1%o!=0)return;
    if(u>sum)return;
    if(o<=u1)
    {
        if(mp1[o]==false)
        {
            mp1[o]=true;
            su++;
        }
    }
    else return;
    dfs1(u,o*sa[u].jidi);
    dfs1(u+1,o);
}
void work(ull u)
{
    map<ull,bool>mp;
    mp1=mp;
    u1=u;
    su=0;
    dfs1(1,1);
}
ll get_ans(ll n)
{
    mif=n;
    fenjie(mif);
    work(mif);
    return su;
}

int main()
{
    ull n;
    //freopen("Gin.txt",")
    make();
    while(1)
    {
        scanf("%llu",&n);

        if(n==0)break;
        printf("%llu ",n);
        n = 4*n-3;
        if(n==1)
        {
            puts("1");
            continue;
        }
        ull res = get_ans(n);
        printf("%llu\n",res);
    }
    return 0;
}
