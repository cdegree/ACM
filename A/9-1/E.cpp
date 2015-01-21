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

const int N = 20005;
const int M = 20005*4;

int head[N],cnt;
struct edge
{
    int u,v,pre;
}E[M];
void insert(int u,int v)
{
    E[cnt].u=u;
    E[cnt].v=v;
    E[cnt].pre=head[u];
    head[u]=cnt++;
}
int belong[N],cntnum,num[N],low[N],instack[N],top,dfn[N];
int cf[N],sta[N];
int index;
void tarjan(int id)
{
    dfn[id]=low[id]=++index;
    instack[id]=1;
    sta[top++]=id;
    int tmp = head[id];
    int v;
    while(~tmp)
    {
        v = E[tmp].v;
        if(!dfn[v ])
        {
            tarjan(v);
            if( low[ v ] < low[id] )low[id] = low[ v ];
        }
        else if(instack[ v ] && dfn[ v ] < low[id] )
        {
            low[id] = dfn[ v ];
        }
        tmp = E[tmp].pre;
    }
    if(dfn[id]==low[id])
    {
        do
        {
            tmp = sta[--top];
            instack[tmp] = 0;
            belong[tmp] = cntnum;
            num[cntnum]++;
        }
        while(tmp!=id);
        ++cntnum;
    }
}
void init()
{
    memset(head,-1,sizeof(head));
    cnt=0;
}
bool solve(int n)
{
    index = cntnum = top = 0;
    memset(dfn,0,sizeof(dfn));
    memset(num,0,sizeof(num));
    for(int i=0;i<2*n;++i)if(!dfn[i])tarjan(i);
    //for(int i=0;i<2*n;++i)printf("belong[%d]=%d\n",i,belong[i]);


    for(int i=0;i<n;++i)
    {
        if(belong[i]==belong[i+n])
        {
            //printf("%d %d\n",i,i+n);
            return false;
        }
    }
    return true;
}
int B[N];
int A[N][2];
int main()
{
    int T,n,m;
    scanf("%d",&T);
    for(int t=1;t<=T;++t)
    {
        init();
        scanf("%d%d",&n,&m);
        for(int i=0;i<n;++i)
        {
            scanf("%d",B+i);
            --B[i];
            A[i][0]=B[i];
            A[i][1]=(B[i]+1)%3;
        }
        int a,b,k;
        for(int i=0;i<m;++i)
        {
            scanf("%d%d%d",&a,&b,&k);
            --a,--b;
            if(k==1)
            {
                if(A[a][0]==A[b][0])
                {
                    insert(a,b+n);
                    insert(b,a+n);
                    insert(a+n,b);
                    insert(b+n,a);
                }
                else if(A[a][0]==A[b][1])
                {
                    insert(a,b);
                    insert(b+n,a+n);
                }
                else if(A[a][1]==A[b][0])
                {
                    insert(a+n,b+n);
                    insert(b,a);
                }
            }
            else
            {
                if(A[a][0]==A[b][0])
                {
                    insert(a,b);
                    insert(b,a);
                    insert(a+n,b+n);
                    insert(b+n,a+n);
                }
                else if(A[a][0]==A[b][1])
                {
                    insert(a+n,a);
                    insert(b,b+n);
                }
                else if(A[a][1]==A[b][0])
                {
                    insert(a,a+n);
                    insert(b+n,b);
                }
            }
        }
        printf("Case #%d: ",t);
        if(solve(n))
        {
            puts("yes");
        }
        else
        {
            puts("no");
        }
    }
	return 0;
}
