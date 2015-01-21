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
typedef long long LL ;
#pragma comment(linker,"/STACK:102400000,102400000")

const int N = 600006;
struct node
{
    int lc,rc;
    int val;
} nd[N];

int root;
set< int > sp;
set< int >::iterator it,jt;
char s[N*3];
int deap[N],rot[N];

void insert(int rt,int val)
{
    jt = it = sp.lower_bound(val);
    int dep=0;
    if(jt==sp.end())
    {
        --it;
        rt = rot[*it];
        dep = deap[*it];
    }
    else
    {
        if(it==sp.begin())
        {
            rt = rot[*it];
            dep = deap[*it];
        }
        else
        {
            --it;
            //printf("%d <> %d\n",deap[*it],deap[*jt]);
            if(deap[*it]>deap[*jt])
            {
                dep = deap[*it];
                rt = rot[*it];
            }
            else
            {
                dep = deap[*jt];
                rt = rot[*jt];
            }
        }
    }
    if(val>nd[rt].val)
    {
        nd[rt].rc = ++root;
        sp.insert(val);
        deap[val]=dep+1;
        rot[val]=root;
        nd[root].val=val;
        nd[root].lc=nd[root].rc=-1;
    }
    else if(val<nd[rt].val)
    {
        nd[rt].lc=++root;
        sp.insert(val);
        deap[val]=dep+1;
        rot[val]=root;
        nd[root].val=val;
        nd[root].lc=nd[root].rc=-1;
    }
}

int len=0;

char tp[N];
int top;
int mx=-1;
void dfs2(int x)
{
    top=-1;
    rot[++top]=x;
    deap[top]=nd[x].val%2+'0';
    tp[top]=0;
    char c,ntp;
    int u;
    while(top>=0)
    {
        u = rot[top];
        ntp = tp[top];
        c = (nd[ u ].val%2)+'0';
        if(ntp==0)
        {
            deap[top] = c;
            s[len++]=c;
            if(~nd[u].lc)
            {
                tp[top]=1;
                rot[++top]=nd[u].lc;
                tp[top]=0;
            }
            else if(~nd[u].rc)
            {
                tp[top]=2;
                rot[++top]=nd[u].rc;
                tp[top]=0;
            }
            else
            {
                --top;
            }
        }
        else if(ntp==1)
        {
            s[len++]=c;
            if(~nd[u].rc)
            {
                tp[top]=2;
                rot[++top]=nd[u].rc;
                tp[top]=0;
            }
            else
            {
                --top;
            }
        }
        else
        {
            --top;
            s[len++]=c;
        }
    }
}
int p[7007];
int KMP(char *a,int n,char *b,int m)
{
    int ret=0;
    p[0]=-1;
    int i,j=-1;
    for(int i=1; i<=m; ++i)
    {
        while((j>-1)&&(b[j+1]!=b[i]))j=p[j];
        if(b[j+1]==b[i])j++;
        p[i]=j;
    }
    j=-1;
    for(int i=0; i<n; ++i)
    {
        while((j>-1)&&(b[j+1]!=a[i]))j=p[j];
        if(b[j+1]==a[i])
        {
            j++;
        }
        if(j==m-1)
        {
            ++ret;
            j=p[j];
        }
    }
    return ret;
}

char s2[7007];


int main()
{
    //freopen("Ein.txt","r",stdin);
    int n;
    int T;
    scanf("%d",&T);
    for(int t=1; t<=T; ++t)
    {
        sp.clear();
        root=0;
        scanf("%d",&n);
        nd[0].val=-1;
        int v;
        scanf("%d",&v);
        {
            sp.insert(v);
            deap[v]=0;
            rot[v]=0;
            nd[0].val=v;
            nd[0].rc=nd[0].lc=-1;
        }
        for(int i=1; i<n; ++i)
        {
            scanf("%d",&v);
            insert(0,v);
        }
        sp.clear();
        len=0;
        dfs2(0);
        scanf("%s",s2);
        printf("Case #%d: ",t);
        int m = strlen(s2);
        int res = KMP(s,len,s2,m);
        printf("%d\n",res);
        //for(int i=0; i<len; ++i)printf("%c",s[i]);puts("");
    }
    return 0;
}
