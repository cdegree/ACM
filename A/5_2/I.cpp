#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#define X first
#define Y second
#define sqr(x) ((x)*(x))
using namespace std;
const double eps = 1e-8 ;

typedef long long LL ;

const LL mod =  1000000007LL;
const int N = 1005;
LL C[N][N]= {0};
LL Q[N][N]= {0};
int head[N],dirto[N*2],next[N*2],nedge;
int de[N];
void init()
{
    for(int i=0; i<N; ++i)
    {
        C[i][i]=1;
        C[i][0]=1;
    }
    for(int i=1; i<N; ++i)
    {
        for(int j=1; j<i; ++j)
        {
            C[i][j]=C[i-1][j]+C[i-1][j-1];
            C[i][j] %=mod;
        }
    }
    nedge=0;
    memset(de,0,sizeof(de));
    memset(head,-1,sizeof(head));
}
LL gao(int len1,int len2)
{
    if(len1<len2)swap(len1,len2);
    ++len1;
    //printf("len1 = %d,len2 = %d\n",len1,len2);
    LL ret = 0;
    for(int i=1;i<=len2;++i)
    {
        ret += C[len1][i]*C[len2-1][i-1];
        ret %= mod;
    }
    //printf("ret = %lld\n",ret);
    return ret;
}
void add_edge(int u,int v)
{
    dirto[nedge]=v;
    next[nedge]=head[u];
    head[u]=nedge++;
}
LL dp[N];
int len[N];
int n;
void dfs(int u,int pre)
{
    LL nowdp = 1;
    LL nowlen = 0;
    for(int e=head[u]; ~e; e=next[e])
    {
        int v = dirto[e];
        if(v!=pre)
        {
            dfs(v,u);
            if(nowlen>0)
            {
                    nowdp *= dp[v];
                    nowdp %= mod;
                    nowdp *= gao(nowlen,len[v]);
                    nowdp %= mod;
            }
            else
            {
                nowdp = dp[v];
            }
            //printf("u = %d nowdp = %lld ,nowlen = %lld,len = %d gao = %lld\n",u,nowdp,nowlen,len[v],gao(nowlen+1,len[v]));
            nowdp %= mod;
            nowlen += len[v];
        }
    }
    ++nowlen;
    dp[u]=nowdp;
    len[u]=nowlen;
}
LL res;
void gao()
{
    memset(dp,0,sizeof(dp));
    memset(len,0,sizeof(len));
    for(int i=1; i<=n; ++i)
    {
        if(de[i]==0)
        {
            dfs(i,i);
            res=dp[i];
            break;
        }
    }
}

int main(int argc, char const *argv[])
{
    int T=0;
    init();
    cin>>T;
    for(int t=1; t<=T; ++t)
    {

        scanf("%d",&n);
        nedge=0;
        memset(de,0,sizeof(de));
        memset(head,-1,sizeof(head));
        for(int i=1; i<n; ++i)
        {
            int u,v;
            scanf("%d%d",&u,&v);
            add_edge(u,v);
            add_edge(v,u);
            ++de[v];
        }
        gao();
        for(int i=1; i<=n; ++i)
        {
            //printf("%d: %lld\n",i,dp[i]);
        }
        printf("Case %d: %lld\n",t,res);

    }
    return 0;
}

