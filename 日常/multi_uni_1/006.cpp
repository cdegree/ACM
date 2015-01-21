#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;

int n,m,Q;
int tot;
struct NN
{
    int l,r,w,dep;
} node[200010];

struct AA
{
    int w,id,u;
    bool fg;
} arr[200010];
bool cmp(AA a,AA b)
{
    if (a.w==b.w) return a.id<b.id;
    return a.w<b.w;
}

int fa[200010];

int head[200010],L;
struct EE
{
    int to,ne;
} e[200010];
void adde(int u,int v)
{
    e[L].to=v;
    e[L].ne=head[u];
    head[u]=L++;
}

int id[200010][3];
int tre[300010][3];
bool root[200010];
void update(int p,int idx,int v)
{
//    if (p==1) cout<<'x'<<idx<<' '<<v<<endl;
    if (idx<=0) return;
    //cout<<n<<Q<<endl;
    while (idx<=3*n)
    {
        tre[idx][p]+=v;
        idx+=idx&-idx;
    }
}
int read(int p,int idx)
{
//    if (p==1) cout<<idx<<'v';
    int ret=0;
    while (idx>0)
    {
        ret+=tre[idx][p];
        idx-=idx&-idx;
    }
//    if (p==1) cout<<ret<<endl;
    return ret;
}

void dfs(int u,int depth)
{
//    printf("depth = %d, u = %d, (%d, %d)\n", depth, u, node[u].l, node[u].r);
    node[u].dep=depth;
    id[u][0]=++tot;
    if (node[u].l!=-1)
    {
        dfs(node[u].l,depth+1);
        id[u][1]=++tot;
        dfs(node[u].r,depth+1);
        id[u][2]=++tot;
    }
    else
    {
        id[u][1]=++tot;
        id[u][2]=++tot;
    }
}

int yes[200020];
void dfs2(int u)
{
    //    cout<<yes[1]<<endl;
    for (int i=head[u]; i!=-1; i=e[i].ne)
    {
        int ii=e[i].to;
        if (yes[arr[ii].w]!=-1)
        {
            arr[ii].fg=false;
        }
    }
    bool fg=false;
    if (yes[node[u].w]==-1)
    {
        yes[node[u].w]=u;
        //    cout<<my[node[u].w]<<endl;
        fg=true;
    }
    if (node[u].l!=-1)
    {
        dfs2(node[u].l);
        dfs2(node[u].r);
    }
    if (fg) yes[node[u].w]=-1;

}

int mzr[100010 * 2];
int ans[100010][2];
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        scanf("%d",&n);
        for (int i=0; i<=n; i++)
        {
            node[i].l=node[i].r=-1;
            root[i]=true;
        }



        for (int i=0; i<n; i++)
        {
            scanf("%d",&node[i].w);
        }
        scanf("%d",&m);
        for (int i=0; i<m; i++)
        {
            int a,b,c;
            scanf("%d%d%d",&a,&b,&c);
            a--;
            b--;
            c--;
            //    cout << a << ' ' << b << ' ' << c << endl;
            node[a].l=b;
            node[a].r=c;
            root[b]=false;
            root[c]=false;
            fa[b]=a;
            fa[c]=a;
        }
        tot=0;
        for (int i=0; i<n; i++)
            if (root[i])
            {
                fa[i]=-1;
                dfs(i,0);
                break;
            }


        scanf("%d",&Q);
        for (int i=0; i<=3*n; i++)
            tre[i][0]=tre[i][1]=tre[i][2]=0;

        L=0;
        for (int i=0; i<=n+Q; i++)
            head[i]=-1;

        for (int i=0; i<n; i++)
        {
            arr[i].u=i;
            arr[i].w=node[i].w;
            arr[i].id=-1;
            arr[i].fg=true;
        }
        for (int i=0; i<Q; i++)
        {
            int u,x;
            scanf("%d%d",&u,&x);
            u--;
            arr[n+i].id=i;
            arr[n+i].w=x;
            arr[n+i].u=u;
            arr[n+i].fg=true;
            adde(u,n+i);
        }

        for (int i = 0; i < n + Q; i++)
            mzr[i] = arr[i].w;
        int mzr_len = n + Q;
        sort(mzr, mzr + mzr_len);
        mzr_len = unique(mzr, mzr + mzr_len) - mzr;
        for (int i = 0; i < n + Q; i++)
        {
            arr[i].w = lower_bound(mzr, mzr + mzr_len, arr[i].w) - mzr;
            if (i<n) node[i].w=arr[i].w;
        }


        //    for (int i=0;i<n+Q;i++)
        //    {
        //        printf("my[%d]=%d\n",arr[i].w,my[arr[i].w]);
        //    }
        for (int i=0; i<n+Q; i++)
            yes[i]=-1;


        //        for (int i=0;i<n+Q;i++)
        //        {
        //            printf("%d %d %d",arr[i].u,my[arr[i].w],arr[i].fg);
        //        }

        for (int i=0; i<n; i++)
            if (root[i])
            {
                dfs2(i);
                break;
            }

        sort(arr,arr+n+Q,cmp);
        for (int i=0; i<n+Q; i++)
        {
            //    cout <<'a'<<i<<' '<<arr[i].id<<' '<<arr[i].w<<endl;
            if (arr[i].id==-1)
            {
                update(0,id[arr[i].u][0],1);
                update(1,id[arr[i].u][1],1);
                update(2,id[arr[i].u][2],1);
                //    cout<<'b'<<arr[i].u<<' '<<id[arr[i].u][0]<<' '<<id[arr[i].u][1]<<' '<<id[arr[i].u][2]<<endl;
            }
            else
            {
                if (arr[i].fg)
                {
                    //cout<<arr[i].id<<' '<<arr[i].u<<'b'<<node[arr[i].u].dep<<endl;
                    int x;
                    x=read(0,id[arr[i].u][0]);
                    int ii=arr[i].id;

                    ans[ii][0]=0;
                    ans[ii][1]=node[arr[i].u].dep;
                    ans[ii][1]+=x*2;

                    //            if (arr[i].id==2)
                    //            cout<<"x="<<arr[i].u<<endl;

                    x=read(1,id[arr[i].u][0]);
                    ans[ii][0]+=x;
                    //            if (arr[i].id==0)
                    //                cout<<"x="<<x<<endl;

                    x=read(2,id[arr[i].u][0]);
                    ans[ii][1]-=x*2;
                    ans[ii][0]-=x;

                    //    if (arr[i].id==2)
                    //    cout<<"x="<<x<<endl;
                    if (arr[i].w>=node[arr[i].u].w) ans[ii][1]-=2;
                }
                else ans[arr[i].id][0]=200000000;
            }
        }
        for (int i=0; i<Q; i++)
        {
            if (ans[i][0]==200000000)    printf("0\n");
            else
                printf("%d %d\n",ans[i][0],ans[i][1]);
        }
    }
}
