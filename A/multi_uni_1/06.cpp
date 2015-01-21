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
const int N = 100005;
struct NODE
{
    int left,right,fa;
    int wi;
    int vw;
} nd[N];
struct Bnode
{
    vector<int> W;
    vector<int> Qid;
} bd[N*2];
struct Ball
{
    int id;
    int qid;
    bool isQuery;
    int w;
} B[N*2];
bool cmp(const Ball a,const  Ball b)
{
    return a.w<b.w;
}
void add_edge(int x,int u,int v)
{
    nd[x].left=u;
    nd[x].right=v;
    nd[u].fa=x;
    nd[v].fa=x;
}

LL tree[3*N];
int n,m;
void add(int k,LL val)
{
    while(k<3*n)
    {
        tree[k]+=val;
        k += (-k&k);
    }
}
LL get_sum(int k)
{
    LL sum=0;
    while(k>0)
    {
        sum += tree[k];
        k -= (-k&k);
    }
    return sum;
}

LL offset = 10000000;
int first[N],mid[N],last[N],depth[N];
int tim_stp;
bool cannot[N];
int used[N*2];
void dfs(int u,int pre,int dep)
{
    for(int i=0; i<bd[u].W.size(); ++i)
    {
        //printf("bd[%d].W[%d]=%d\n",u,i,bd[u].W[i]);
        if(used[ bd[u].W[i] ])
        {
            //printf("qid = %d, u = %d,  used[%d]=%d\n",bd[u].Qid[i],u,bd[u].W[i],used[ bd[u].W[i] ]);
            cannot[ bd[u].Qid[i] ]=true;
        }
    }
    ++used[ nd[u].vw ];
    //printf("nd[%d].vw = %d\n",u,nd[u].vw);
    depth[u]=dep;
    first[u]=++tim_stp;
    if(~nd[u].left)dfs(nd[u].left,u,dep+1);
    mid[u]=++tim_stp;
    if(~nd[u].right)dfs(nd[u].right,u,dep+1);
    last[u]=++tim_stp;
    --used[ nd[u].vw ];
}
struct Res
{
    LL x,y;
    int id;
} R[N];
bool cmp2(Res a,Res b)
{
    return a.id<b.id;
}
void init()
{
    tim_stp=0;
    for(int i=1; i<N; ++i)bd[i].W.clear(),bd[i].Qid.clear();
    memset(tree,0,sizeof(tree));
    memset(nd,-1,sizeof(nd));
    memset(used,0,sizeof(used));
    memset(cannot,false,sizeof(cannot));
    memset(R,0,sizeof(R));
    memset(B,0,sizeof(B));
    memset(bd,0,sizeof(bd));
}

int len=0;
void pf()
{
    for(int i=0;i<len;++i)
    {
        printf("B[%d].w=%d\n",i,B[i].w);
    }
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        init();
        scanf("%d",&n);
        len=0;
        for(int i=1; i<=n; ++i)
        {
            scanf("%d",&nd[i].wi);
            B[len].isQuery=false;
            B[len].id=i;
            B[len++].w=nd[i].wi;
        }
        scanf("%d",&m);
        for(int i=0; i<m; ++i)
        {
            int c,a,b;
            scanf("%d%d%d",&a,&b,&c);
            add_edge(a,b,c);
        }
        int q;
        scanf("%d",&q);
        for(int i=0; i<q; ++i)
        {
            int u,X;
            scanf("%d%d",&u,&X);
            B[len].isQuery=true;
            B[len].w=X;
            B[len].id=u;
            B[len++].qid=i;
        }
        //printf("len = %d\n",len);
        //pf();
        sort(B,B+len,cmp);
        //pf();
        int L=1;
        int preL=-1;
        if(B[0].isQuery)
        {
            bd[ B[0].id ].W.push_back(L);
            bd[ B[0].id ].Qid.push_back(B[0].qid);
        }
        else
        {
            nd[ B[0].id ].vw=L;
        }
        for(int i=1; i<len; ++i)
        {
            //printf("B[%d].id=%d\n",i,B[i].id);
            int id = B[i].id;
            if(B[i].w!=B[i-1].w)
            {
                ++L;
            }
            if(B[i].isQuery)
            {
                bd[id].W.push_back(L);
                bd[id].Qid.push_back(B[i].qid);
            }
            else
            {
                nd[ id ].vw=L;
            }
        }


        for(int i=1; i<=n; ++i)
        {
            if(nd[i].fa==-1)
            {
                dfs(i,i,0);
                break;
            }
        }


        int cnt=0;
        int pre=-1;
        for(int i=0; i<len; ++i)
        {
            //printf("i=%d: %d w=%d id = %d qid = %d\n",i,B[i].isQuery,B[i].w, B[i].id, B[i].qid );
            if(B[i].isQuery)
            {
                int qid = R[cnt].id=B[i].qid;
                int id = B[i].id;
                if(cannot[qid])
                {
                    R[qid].x=-1;
                }
                else
                {
                    if(~nd[id].fa)
                    {
                        //LL usum = get_sum(first[id]);
                        LL sum = get_sum(first[id]-1);
                        //printf("sum = %lld  \n",sum);
                        LL cntr = sum/offset;
                        LL cntl = sum%offset;
                        //printf("cntl = %lld  cntr = %lld   dep = %d\n",cntl,cntr,depth[id]);
                        R[qid].x=cntr;
                        R[qid].y=2*(cntl+cntr)+depth[id];
                    }
                    else
                    {
                        R[qid].x=0;
                        R[qid].y=0;
                    }
                }
            }
            else
            {
                int u = B[i].id;
                add(first[u],1);
                add(mid[u],offset-1);
                add(last[u],-offset);
            }
        }
        for(int i=0; i<q; ++i)
        {
            if(~R[i].x)
            {
                printf("%I64d %I64d\n",R[i].x,R[i].y);
            }
            else
            {
                puts("0");
            }
        }
    }
    return 0;
}
