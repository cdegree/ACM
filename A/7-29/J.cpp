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

LL mod = 1000000007LL;
const int N = 100005;
char s1[N],s2[N],s3[N];
int n;
LL get_dis(char *c1,char *c2)
{
    LL ret=0;
    for(int i=0;i<n;++i)
    {
        ret += (c1[i]-'0')^(c2[i]-'0');
    }
    return ret;
}
LL Pow(LL x,LL m)
{
    if(m==0)return 1;
    else if(m&1)
    {
        LL ret = x*Pow(x,m-1);
        ret %=mod;
        return ret;
    }
    else
    {
        LL ret = Pow(x,m/2);
        ret *=ret;
        ret %=mod;
        return ret;
    }
}
LL dis[3];
int main()
{
    while(~scanf("%s %s %s",s1,s2,s3))
    {
        n=strlen(s1);
        dis[0] = get_dis(s1,s2);
        dis[1] = get_dis(s1,s3);
        dis[2] = get_dis(s2,s3);
        LL res=0;
        if(dis[0]%2==0&&dis[1]%2==0&&dis[2]%2==0)
        {
            sort(dis,dis+3);
            if(dis[1]==0)//1
            {
                res = (Pow(2,n)-1+mod)%mod;
            }
            else if(dis[0]==0) //2
            {
                res = Pow(2,n-1);
            }
            else //3
            {
                res = Pow(2,n-2);
            }
            printf("%I64d\n",res);
        }
        else
        {
            puts("0");
        }
    }
	return 0;
}
