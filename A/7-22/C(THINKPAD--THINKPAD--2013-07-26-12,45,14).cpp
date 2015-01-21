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
#define N 1005 // 点的个数
#define M 1000005// 边的个数

int v[N], cnt, v2[N], cnt2;
struct edge
{
    int from, to, next;
} e[M], e2[M];
void insert(int from, int to)
{
    e[cnt].from = from, e[cnt].to = to;
    e[cnt].next = v[from];
    v[from] = cnt++;
}
void insert2(int from, int to)
{
    e2[cnt2].from = from, e2[cnt2].to = to;
    e2[cnt2].next = v2[from];
    v2[from] = cnt2++;
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
    int tmp = v[id];
    while(tmp != -1)
    {
        if (!dfn[e[tmp].to])
        {
            tarjan(e[tmp].to);
            if (low[e[tmp].to] < low[id]) low[id] = low[e[tmp].to];
        }
        else if (instack[e[tmp].to] && dfn[e[tmp].to] < low[id])
            low[id] = dfn[e[tmp].to];
        tmp = e[tmp].next;
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
    for(int i = 0; i < n; i++)                  //在缩点的图中标记互斥的缩点。（原来互斥，现在也互斥）
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
    memset(v2, -1, sizeof(v2));
    memset(col, 0, sizeof(col));
    cnt2 = 0;
    for(int i = 0; i < cnt; i++)      //建立缩点图，边用的是反向边，同时统计入度。
        if (belong[e[i].from] != belong[e[i].to])
        {
            insert2(belong[e[i].to], belong[e[i].from]);
            rd[belong[e[i].from]]++;
        }
    int head = 0, tail = 0;                //开始topsort
    for(int i = 0; i < cntnum; i++)
        if (rd[i] == 0) que[tail++] = i;
    puts("ok");
    while(head < tail)
    {
        int tmp = que[head++];
        if (col[tmp] == 0)                   //对于未着色的点x，将x染成红色，同时将与x矛盾的点cf[x]染成蓝色。
        {
            col[tmp] = 1;
            col[cf[tmp]] = -1;
        }
        int id = v2[tmp];
        while(id != -1)
        {
            if (--rd[e2[id].to] == 0)
                que[tail++] = e2[id].to;
            id = e2[id].next;
        }
    }
    memset(ans, 0, sizeof(ans));
    for(int i = 0; i < n; i++) // 2-sat的一组解就等价于所有缩点后点颜色为红色的点
        if (col[belong[i]] == 1) ans[i] = 1;
    return true;
}
bool judge(pair<int,int> a,pair<int,int> b)
{
    return a.first==b.first||a.second==b.second;
}
pair<int,int> P[2*N];
int main()
{
    int n;
    while(~scanf("%d",&n))
    {
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
            else printf("0 ");
        }
        puts("");
    }
    /*
    while(1)puts("ffff");
    while(1)puts("ffff");
    while(1)puts("ffff");
    while(1)puts("ffff");
    while(1)puts("ffff");
    while(1)puts("ffff");
    while(1)puts("ffff");
    while(1)puts("ffff");
    while(1)puts("ffff");
    while(1)puts("ffff");
    while(1)puts("ffff");
    while(1)puts("ffff");
    while(1)puts("ffff");
    while(1)puts("ffff");
    while(1)puts("ffff");
    while(1)puts("ffff");
    while(1)puts("ffff");
    while(1)puts("ffff");
    *//*
while(1)puts("ffff");
while(1)puts("ffff");
while(1)puts("ffff");
while(1)puts("ffff");
while(1)puts("ffff");
while(1)puts("ffff");
while(1)puts("ffff");
while(1)puts("ffff");
while(1)puts("ffff");
while(1)puts("ffff");
while(1)puts("ffff");
while(1)puts("ffff");
while(1)puts("ffff");
while(1)puts("ffff");
while(1)puts("ffff");
while(1)puts("ffff");
while(1)puts("ffff");
while(1)puts("ffff");
*//*
while(1)puts("ffff");
while(1)puts("ffff");
while(1)puts("ffff");
while(1)puts("ffff");
while(1)puts("ffff");
while(1)puts("ffff");
while(1)puts("ffff");
while(1)puts("ffff");
while(1)puts("ffff");
while(1)puts("ffff");
while(1)puts("ffff");
while(1)puts("ffff");
while(1)puts("ffff");
while(1)puts("ffff");
while(1)puts("ffff");
while(1)puts("ffff");
while(1)puts("ffff");
while(1)puts("ffff");
*//*
while(1)puts("ffff");
while(1)puts("ffff");
while(1)puts("ffff");
while(1)puts("ffff");
while(1)puts("ffff");
while(1)puts("ffff");
while(1)puts("ffff");
while(1)puts("ffff");
while(1)puts("ffff");
while(1)puts("ffff");
while(1)puts("ffff");
while(1)puts("ffff");
while(1)puts("ffff");
while(1)puts("ffff");
while(1)puts("ffff");
while(1)puts("ffff");
while(1)puts("ffff");
while(1)puts("ffff");
*//*
while(1)puts("ffff");
while(1)puts("ffff");
while(1)puts("ffff");
while(1)puts("ffff");
while(1)puts("ffff");
while(1)puts("ffff");
while(1)puts("ffff");
while(1)puts("ffff");
while(1)puts("ffff");
while(1)puts("ffff");
while(1)puts("ffff");
while(1)puts("ffff");
while(1)puts("ffff");
while(1)puts("ffff");
while(1)puts("ffff");
while(1)puts("ffff");
while(1)puts("ffff");
while(1)puts("ffff");
*//*
while(1)puts("ffff");
while(1)puts("ffff");
while(1)puts("ffff");
while(1)puts("ffff");
while(1)puts("ffff");
while(1)puts("ffff");
while(1)puts("ffff");
while(1)puts("ffff");
while(1)puts("ffff");
while(1)puts("ffff");
while(1)puts("ffff");
while(1)puts("ffff");
while(1)puts("ffff");
while(1)puts("ffff");
while(1)puts("ffff");
while(1)puts("ffff");
while(1)puts("ffff");
while(1)puts("ffff");
*//*
while(1)puts("ffff");
while(1)puts("ffff");
while(1)puts("ffff");
while(1)puts("ffff");
while(1)puts("ffff");
while(1)puts("ffff");
while(1)puts("ffff");
while(1)puts("ffff");
while(1)puts("ffff");
while(1)puts("ffff");
while(1)puts("ffff");
while(1)puts("ffff");
while(1)puts("ffff");
while(1)puts("ffff");
while(1)puts("ffff");
while(1)puts("ffff");
while(1)puts("ffff");
while(1)puts("ffff");
*//*
while(1)puts("ffff");
while(1)puts("ffff");
while(1)puts("ffff");
while(1)puts("ffff");
while(1)puts("ffff");
while(1)puts("ffff");
while(1)puts("ffff");
while(1)puts("ffff");
while(1)puts("ffff");
while(1)puts("ffff");
while(1)puts("ffff");
while(1)puts("ffff");
while(1)puts("ffff");
while(1)puts("ffff");
while(1)puts("ffff");
while(1)puts("ffff");
while(1)puts("ffff");
while(1)puts("ffff");
*//*
while(1)puts("ffff");
while(1)puts("ffff");
while(1)puts("ffff");
while(1)puts("ffff");
while(1)puts("ffff");
while(1)puts("ffff");
while(1)puts("ffff");
while(1)puts("ffff");
while(1)puts("ffff");
while(1)puts("ffff");
while(1)puts("ffff");
while(1)puts("ffff");
while(1)puts("ffff");
while(1)puts("ffff");
while(1)puts("ffff");
while(1)puts("ffff");
while(1)puts("ffff");
while(1)puts("ffff");
*//*
while(1)puts("ffff");
while(1)puts("ffff");
while(1)puts("ffff");
while(1)puts("ffff");
while(1)puts("ffff");
while(1)puts("ffff");
while(1)puts("ffff");
while(1)puts("ffff");
while(1)puts("ffff");
while(1)puts("ffff");
while(1)puts("ffff");
while(1)puts("ffff");
while(1)puts("ffff");
while(1)puts("ffff");
while(1)puts("ffff");
while(1)puts("ffff");
while(1)puts("ffff");
while(1)puts("ffff");
*//*
while(1)puts("ffff");
while(1)puts("ffff");
while(1)puts("ffff");
while(1)puts("ffff");
while(1)puts("ffff");
while(1)puts("ffff");
while(1)puts("ffff");
while(1)puts("ffff");
while(1)puts("ffff");
while(1)puts("ffff");
while(1)puts("ffff");
while(1)puts("ffff");
while(1)puts("ffff");
while(1)puts("ffff");
while(1)puts("ffff");
while(1)puts("ffff");
while(1)puts("ffff");
while(1)puts("ffff");
*//*
while(1)puts("ffff");
while(1)puts("ffff");
while(1)puts("ffff");
while(1)puts("ffff");
while(1)puts("ffff");
while(1)puts("ffff");
while(1)puts("ffff");
while(1)puts("ffff");
while(1)puts("ffff");
while(1)puts("ffff");
while(1)puts("ffff");
while(1)puts("ffff");
while(1)puts("ffff");
while(1)puts("ffff");
while(1)puts("ffff");
while(1)puts("ffff");
while(1)puts("ffff");
while(1)puts("ffff");
*//*
while(1)puts("ffff");
while(1)puts("ffff");
while(1)puts("ffff");
while(1)puts("ffff");
while(1)puts("ffff");
while(1)puts("ffff");
while(1)puts("ffff");
while(1)puts("ffff");
while(1)puts("ffff");
while(1)puts("ffff");
while(1)puts("ffff");
while(1)puts("ffff");
while(1)puts("ffff");
while(1)puts("ffff");
while(1)puts("ffff");
while(1)puts("ffff");
while(1)puts("ffff");
while(1)puts("ffff");
*//*
while(1)puts("ffff");
while(1)puts("ffff");
while(1)puts("ffff");
while(1)puts("ffff");
while(1)puts("ffff");
while(1)puts("ffff");
while(1)puts("ffff");
while(1)puts("ffff");
while(1)puts("ffff");
while(1)puts("ffff");
while(1)puts("ffff");
while(1)puts("ffff");
while(1)puts("ffff");
while(1)puts("ffff");
while(1)puts("ffff");
while(1)puts("ffff");
while(1)puts("ffff");
while(1)puts("ffff");
*//*
while(1)puts("ffff");
while(1)puts("ffff");
while(1)puts("ffff");
while(1)puts("ffff");
while(1)puts("ffff");
while(1)puts("ffff");
while(1)puts("ffff");
while(1)puts("ffff");
while(1)puts("ffff");
while(1)puts("ffff");
while(1)puts("ffff");
while(1)puts("ffff");
while(1)puts("ffff");
while(1)puts("ffff");
while(1)puts("ffff");
while(1)puts("ffff");
while(1)puts("ffff");
while(1)puts("ffff");
*//*
while(1)puts("ffff");
while(1)puts("ffff");
while(1)puts("ffff");
while(1)puts("ffff");
while(1)puts("ffff");
while(1)puts("ffff");
while(1)puts("ffff");
while(1)puts("ffff");
while(1)puts("ffff");
while(1)puts("ffff");
while(1)puts("ffff");
while(1)puts("ffff");
while(1)puts("ffff");
while(1)puts("ffff");
while(1)puts("ffff");
while(1)puts("ffff");
while(1)puts("ffff");
while(1)puts("ffff");
*//*
while(1)puts("ffff");
while(1)puts("ffff");
while(1)puts("ffff");
while(1)puts("ffff");
while(1)puts("ffff");
while(1)puts("ffff");
while(1)puts("ffff");
while(1)puts("ffff");
while(1)puts("ffff");
while(1)puts("ffff");
while(1)puts("ffff");
while(1)puts("ffff");
while(1)puts("ffff");
while(1)puts("ffff");
while(1)puts("ffff");
while(1)puts("ffff");
while(1)puts("ffff");
while(1)puts("ffff");
*//*
while(1)puts("ffff");
while(1)puts("ffff");
while(1)puts("ffff");
while(1)puts("ffff");
while(1)puts("ffff");
while(1)puts("ffff");
while(1)puts("ffff");
while(1)puts("ffff");
while(1)puts("ffff");
while(1)puts("ffff");
while(1)puts("ffff");
while(1)puts("ffff");
while(1)puts("ffff");
while(1)puts("ffff");
while(1)puts("ffff");
while(1)puts("ffff");
while(1)puts("ffff");
while(1)puts("ffff");
*//*
while(1)puts("ffff");
while(1)puts("ffff");
while(1)puts("ffff");
while(1)puts("ffff");
while(1)puts("ffff");
while(1)puts("ffff");
while(1)puts("ffff");
while(1)puts("ffff");
while(1)puts("ffff");
while(1)puts("ffff");
while(1)puts("ffff");
while(1)puts("ffff");
while(1)puts("ffff");
while(1)puts("ffff");
while(1)puts("ffff");
while(1)puts("ffff");
while(1)puts("ffff");
while(1)puts("ffff");
*//*
while(1)puts("ffff");
while(1)puts("ffff");
while(1)puts("ffff");
while(1)puts("ffff");
while(1)puts("ffff");
while(1)puts("ffff");
while(1)puts("ffff");
while(1)puts("ffff");
while(1)puts("ffff");
while(1)puts("ffff");
while(1)puts("ffff");
while(1)puts("ffff");
while(1)puts("ffff");
while(1)puts("ffff");
while(1)puts("ffff");
while(1)puts("ffff");
while(1)puts("ffff");
while(1)puts("ffff");
*//*
while(1)puts("ffff");
while(1)puts("ffff");
while(1)puts("ffff");
while(1)puts("ffff");
while(1)puts("ffff");
while(1)puts("ffff");
while(1)puts("ffff");
while(1)puts("ffff");
while(1)puts("ffff");
while(1)puts("ffff");
while(1)puts("ffff");
while(1)puts("ffff");
while(1)puts("ffff");
while(1)puts("ffff");
while(1)puts("ffff");
while(1)puts("ffff");
while(1)puts("ffff");
while(1)puts("ffff");
*//*
while(1)puts("ffff");
while(1)puts("ffff");
while(1)puts("ffff");
while(1)puts("ffff");
while(1)puts("ffff");
while(1)puts("ffff");
while(1)puts("ffff");
while(1)puts("ffff");
while(1)puts("ffff");
while(1)puts("ffff");
while(1)puts("ffff");
while(1)puts("ffff");
while(1)puts("ffff");
while(1)puts("ffff");
while(1)puts("ffff");
while(1)puts("ffff");
while(1)puts("ffff");
while(1)puts("ffff");
*/
    return 0;
}
