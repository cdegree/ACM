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

vector<int> fac(int n)
{
    vector<int> f;
    for(int i=1;i*i<=n;++i)
    {
        if(n%i==0)
        {
            f.push_back(i);
            if(n/i!=i)f.push_back(n/i);
        }
    }
    return f;
}

int get_sqr_sum(int x,int m)
{
    int ret=0;
    while(x>0)
    {
        ret+=sqr(x%m);
        x/=m;
    }
    return ret;
}

int sqr_sum(vector<int> f,int base)
{
   int ret=0;
   for(int i=0;i<f.size();++i)
   {
       ret += get_sqr_sum(f[i],base);
   }
   return ret;
}
vector<char> tobase(int x,int b)
{
    vector<char> ret;
    while(x>0)
    {
        int c = x%b;
        char ch;
        if(c>9)
        {
            ch=c+'A'-10;
        }
        else ch=c+'0';
        //printf("c=%d\n",c);
        ret.push_back(ch);
        x/=b;
    }
    return ret;
}

int main()
{
    int n,m;
    while(~scanf("%d%d",&n,&m))
    {
        LL res = sqr_sum(fac(n),m);
        //printf("%lld\n",res);
        vector<char> f = tobase(res,m);
        for(int i=f.size()-1;i>=0;--i)
        {
            printf("%c",f[i]);
        }
        puts("");
    }
	return 0;
}
