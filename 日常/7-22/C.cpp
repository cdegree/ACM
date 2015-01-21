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
using namespace std;

typedef long long LL ;
#define N 2005 // 总的点的个数
#define M 2000005// 边的个数

int head[N], cnt, head2[N], cnt2;
struct edge
{
    int u, v, pre;
} E[M], E2[M];
void insert(int u, int v)
{
    E[cnt].u = u, E[cnt].v = v;
    E[cnt].pre = head[u];
    head[u] = cnt++;
}
void insert2(int u, int v)
{
    E2[cnt2].u = u, E2[cnt2].v = v;
    E2[cnt2].pre = head2[u];
    head2[u] = cnt2++;
}
int index, dfn[N], low[N], instack[N], sta[N], top;
int belong[N], cntnum, num[N];
int cf[N], rd[N], que[N], col[N];
bool ans[N];//1表示选择
void tarjan(int id)
{
    dfn[id] = low[id] = ++index;
    instack[id] = 1;
    sta[top++] = id;
    int tmp = head[id];
    while(tmp != -1)
    {
        if (!dfn[E[tmp].v])
        {
            tarjan(E[tmp].v);
            low[id] = min(low[id], low[E[tmp].v]);
        }
        else if (instack[E[tmp].v] && dfn[E[tmp].v] < low[id])
            low[id] = dfn[E[tmp].v];
        tmp = E[tmp].pre;
    }
    if (dfn[id] == low[id])
    {
        do
        {
            tmp = sta[--top];
            instack[tmp] = 0;
            belong[tmp] = cntnum;
            num[cntnum]++;
        }
        while(tmp != id);
        cntnum++;
    }
}
bool solve(int n) // n是一半的点数(实际的人数) 执行tarjan和topsort,完成标记
{
    index = cntnum = top = 0;
    memset(dfn, 0, sizeof(dfn));
    memset(num, 0, sizeof(num));
    for(int i = 0; i < 2 * n; i++)
        if (!dfn[i]) tarjan(i);
//在缩点的图中标记互斥的缩点。（原来互斥，现在也互斥）
//判定部分
    for(int i = 0; i < n; i++)
    {
        if (belong[i] == belong[i + n])
        {
            //cout << i + 1 << "haha" << endl;
            return false;
        }
        cf[belong[i]] = belong[i + n];
        cf[belong[i + n]] = belong[i];
    }
    memset(rd, 0, sizeof(rd));
    memset(head2, -1, sizeof(head2));
    memset(col, 0, sizeof(col));
    cnt2 = 0;
    for(int i = 0; i < cnt; i++)      //建立缩点图，边用的是反向边，同时统计入度。
        if (belong[E[i].u] != belong[E[i].v])
        {
            insert2(belong[E[i].v], belong[E[i].u]);
            rd[belong[E[i].u]]++;
        }
    int head = 0, tail = 0;                //开始topsort
    for(int i = 0; i < cntnum; i++)
        if (rd[i] == 0) que[tail++] = i;
    while(head < tail)
    {
        int tmp = que[head++];
        if (col[tmp] == 0)
        {
            col[tmp] = 1;
            col[cf[tmp]] = -1;
        }
        int id = head2[tmp];
        while(id != -1)
        {
            if (--rd[E2[id].v] == 0)
                que[tail++] = E2[id].v;
            id = E2[id].pre;
        }
    }
    memset(ans, 0, sizeof(ans));
    for(int i = 0; i < n; i++)
        if (col[belong[i]] == 1) ans[i] = 1;
    return true;
}
void init()
{
    cnt=0;
    memset(head,-1,sizeof(head));
}

bool judge(pair<int,int> a,pair<int,int> b)
{
    return a.first==b.first||a.second==b.second;
}
pair<int,int> P[N];
int main()
{
    int n;
    while(~scanf("%d",&n))
    {
        init();
        for(int i=0; i<n; ++i)
        {
            int a,b,c;
            scanf("%d %d %d",&a,&b,&c);
            --a,--b,--c;
            P[i]=make_pair(i,a);
            P[i+n]=make_pair(b,c);
        }
        for(int i=0;i<n;++i)
        {
            for(int j=i+1;j<n;++j)
            {
                if(judge(P[i],P[j]))
                {
                    insert(i,j+n);
                    insert(j,i+n);
                }
                if(judge(P[i],P[j+n]))
                {
                    insert(i,j);
                    insert(j+n,i+n);
                }
                if(judge(P[i+n],P[j]))
                {
                    insert(i+n,j+n);
                    insert(j,i);
                }
                if(judge(P[i+n],P[j+n]))
                {
                    insert(i+n,j);
                    insert(j+n,i);
                }
            }
        }
        solve(n);
        for(int i=0;i<n;++i)
        {
            if(ans[i]==1)
            {
                printf("%d ",1);
            }
            else printf("2 ");
        }
        puts("");
    }
    return 0;
}
