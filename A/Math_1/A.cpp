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

const int N = 100005;

LL phi[N];
vector<int> prime[N];
bool isprime[N];
void init()
{
    for(int i=0; i<N; ++i)prime[i].clear();
    memset(isprime,1,sizeof(isprime));
    for(int i=0; i<N; ++i)phi[i]=i;
    for(int i=2; i<N; ++i)
    {
        if(isprime[i])
        {
            for(int j=i; j<N; j+=i)
            {
                isprime[j]=0;
                phi[j]=phi[j]/i*(i-1);
                prime[j].push_back(i);
            }
        }
        phi[i]+=phi[i-1];
    }
}
LL dfs(int cur,int x,int n)
{
    LL ret=0;
    for(int i=cur; i<prime[n].size(); ++i)
    {
        LL t = x/prime[n][i];
        ret += t - dfs(i+1,t,n);
    }
    return ret;
}
int main()
{
    int a,b,c,d,k;
    int T;
    init();
    scanf("%d",&T);
    for(int t=1; t<=T; ++t)
    {
        scanf("%d%d%d%d%d",&a,&b,&c,&d,&k);
        printf("Case %d: ",t);
        if(k==0)
        {
            puts("0");
        }
        else
        {
            b/=k;
            d/=k;
            if(b>d)swap(b,d);
            LL res = phi[b];
            for(int i=b+1; i<=d; ++i)
            {
                res += b - dfs(0,b,i);
            }
            printf("%I64d\n",res);
        }
    }
    return 0;
}
