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

const int N = 1005;
const int M = 5000000;

int V[N],cnt,cnt2;
struct edge
{
    int u,v,pre;
} E[M];
void insert(int u,int v)
{
    E[cnt].u=u;
    E[cnt].v=v;
    E[cnt].pre=V[u];
    V[u] = cnt++;
}
int index,dfn[N],low[N],instack[N],sta[N],top;
int belong[N],cntnum,num[N];
int cf[N],rd[N],que[N],col[N];
bool ans[N];
void tarjan(int id)
{
    dfn[id] = low[id] = ++index;
    instack[id] = 1;
    sta[top++]=id;
    int tmp = V[id];
    while(~tmp)
    {
        if(!dfn[E[tmp].v])
        {
            tarjan((E[tmp].v));
            if(low[E[tmp].v] < low[id])low[id] = low[E[tmp].v];
        }
        else if(instack[E[tmp].v] && dfn[E[tmp].v] < low[id] )
        {
            low[id] = dfn[E[tmp].v];
        }
        tmp = E[tmp].pre;
    }
    if(dfn[id]== low[id])
    {
        do
        {
            tmp = sta[--top];
            instack[tmp]=0;
            belong[tmp] = cntnum;
            num[cntnum]++;
        }
        while(tmp!=id);
        ++cntnum;
    }
}
bool solve(int n)
{
    index = cntnum = top = 0;
    memset(dfn,0,sizeof(dfn));
    memset(num,0,sizeof(num));
    for(int i=0; i<2*n; ++i)
    {
        if(!dfn[i])tarjan(i);
    }
    for(int i=0; i<n; ++i)
    {
        if(belong[i] == belong[i+n])
        {
            return false;
        }
        cf[belong[i]] = belong[i+n];
        cf[belong[i+n]] = belong[i];
    }
    return true;
}
void init()
{
    cnt=0;
    memset(V,-1,sizeof(V));
}
LL mt[505][505];
bool test_bit(LL val,int pos)
{
    return ((1LL<<pos)&val)!=0;
}
int main()
{
    int n;
    //freopen("Bin.txt","r",stdin);
    while(~scanf("%d",&n))
    {
        bool mid=0;
        for(int i=0; i<n; ++i)
        {
            for(int j=0; j<n; ++j)
            {
                scanf("%d",&mt[i][j]);
                if(i==j&&mt[i][j]!=0)mid=1;
            }
        }
        if(mid)
        {
            puts("NO");
        }
        else
        {

            //puts("ok");
            bool ok=1;
            for(int k=0; k<32; ++k)
            {
                init();
                //printf("k=%d,cnt=%d\n",k,cnt);
                for(int i=0; i<n; ++i)
                {
                    for(int j=0; j<n; ++j)
                    {
                        if(i==j)continue;
                        {
                            if(test_bit(mt[i][j],k))
                            {
                                if(i%2==1&&j%2==1)
                                {
                                    insert(i, j+n);
                                    insert(j, i+n);
                                }
                                else if(i%2==0&&j%2==0)
                                {
                                    insert(i,i+n);
                                    insert(j,j+n);
                                }
                                else
                                {
                                    insert(i,j+n);
                                    //insert(32*n+k*n+j,k*n+i);
                                    //insert(k*n+j,32*n+k*n+i);
                                    insert(i+n,j);
                                }
                            }
                            else
                            {
                                if(i%2==1&&j%2==1)
                                {
                                    insert(i+n,i);
                                    insert(j+n,j);
                                }
                                else if(i%2==0&&j%2==0)
                                {
                                    insert(i+n,j);
                                    insert(j+n,i);
                                }
                                else
                                {
                                    insert(i,j);
                                    insert(i+n,j+n);
                                }
                            }
                        }
                    }
                }
                //puts("ok2");
                if(!solve(n)){ok=0;break;}
            }
            if(ok)
            {
                puts("YES");
            }
            else
            {
                puts("NO");
            }
        }

    }
    return 0;
}
