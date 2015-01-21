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

int Ext_gcd(int a,int b,int &x,int &y){
    if(b==0) { x=1, y=0; return a; }
    int d= Ext_gcd(b,a%b,y,x);
    y-= a/b*x;
    return d;
}
int Inv(int a,int m)
{
    int d,x,y;
    d= Ext_gcd(a,(int)m,x,y);
    if(d==1) return (x%m+m)%m;
    return -1;
}
int main()
{
    LL l,v1,v2,t;
    while(~scanf("%I64d%I64d%I64d%I64d",&l,&v1,&v2,&t))
    {
        if(v1>v2)swap(v1,v2);
        LL dv = (v2-v1);
        LL cnt=0;
        LL f=1;
        for(int i=1;i<=t;++i)
        {
            if(dv*i%(2*l)==l)
            {
                f=i;
                printf("i = %d\n",i);
                //break;
                ++cnt;
            }
        }
        //cnt = (t-f)/f;
        printf("%lld\n",cnt);
        if(dv*t%(2*l)==l)--cnt;
        LL res = v2*t/l-cnt;

        printf("%I64d\n",res);
    }
	return 0;
}
