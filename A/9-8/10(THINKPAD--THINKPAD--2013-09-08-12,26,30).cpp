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
#pragma comment(linker,"/STACK:102400000,102400000")
using namespace std;
const double PI = acos(-1.0);
map<int, int>::iterator it;
typedef long long LL ;
template<typename T> void checkmin(T &x, T y) {x = min(x, y);}
template<typename T> void checkmax(T &x, T y) {x = max(x, y);}


const int N = 1000005;

int prime[N];
bool isprime[N];
int len;
void init()
{
    memset(isprime,1,sizeof(isprime));
    len=0;
    for(int i=2;i<N;++i)
    {
        if(isprime[i])
        {
            for(int j=i+i;j<N;j+=i)
            {
                isprime[j]=0;
            }
            prime[len++]=i;
        }
    }
}

pair<int,int> gao(int x)
{
    pair<int,int> ret;
    ret.X=ret.Y=0;
    for(int i=0;i<len;++i)
    {
        if(isprime[prime[i]+x])
        {
            ret.X=prime[i]+x;
            ret.Y=prime[i];
            break;
        }
    }
    return ret;
}

int main()
{
    init();
    for(int i=2;i<N;i+=2)
    {
        pair<int,int> pi = gao(i);
        if(i>800000)printf("%d %d\n",pi.X,pi.Y);
    }
	return 0;
}
