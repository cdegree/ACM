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

const int N = 1000005;
bool isprime[N];
int len;
int l;
void init()
{
    len=0;
    l=0;
    for(int i=1;i<N;++i)isprime[i]=1;
    isprime[1]=0;
    for(int i=2;i<N;++i)
    {
        if(isprime[i])
        {
            for(int j=i+i;j<N;j+=i)
            {
                isprime[j]=0;
            }
        }
    }
}
int main()
{
    init();

    int n;
    while(~scanf("%d",&n))
    {
        int len=0;
        for(int i=3;i+2<=n;++i)
        {
            if(isprime[i]&&isprime[i+2])len++;
        }
        printf("%d\n",len);
        for(int i=3;i+2<=n;++i)
        {
            if(isprime[i]&&isprime[i+2])printf("%d %d\n",2,i);
        }
    }
	return 0;
}
