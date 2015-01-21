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


const int maxn = 50005;

#define lson L , mid , rt << 1
#define rson mid + 1 , R , rt << 1 | 1
#define lc rt<<1
#define rc rt<<1|1

struct Segment_Tree
{
    int left[maxn*4],right[maxn*4];
    int sum[maxn*4];
    int add[maxn*4];
    bool npd[maxn*4];
    void Build(int L,int R,int rt)
    {
        left[rt]=L,right[rt]=R;
        sum[rt]=R-L+1;
        add[rt]=0;
        npd[rt]=false;
        if(L==R)
        {
            ;
        }
        else
        {
            int mid = (L+R)>>1;
            Build(lson);
            Build(rson);
            Push_Up(rt);
        }
    }
    void Push_Up(int rt)
    {
        sum[rt]=sum[lc]+sum[rc];
    }
    void Push_Down(int rt)
    {
        if(npd[rt])
        {
            npd[lc]=npd[rc]=1;
            npd[rt]=0;
            sum[lc]=(right[lc]-left[lc]+1)*add[rt];
            sum[rc]=(right[rc]-left[rc]+1)*add[rt];
            add[lc]=add[rt];
            add[rc]=add[rt];
        }
    }
    void Update(int L,int R,int rt,int from,int to,int val)
    {
        if(from<=L&&R<=to)
        {
            add[rt]=val;
            sum[rt]=(right[rt]-left[rt]+1)*val;
            npd[rt]=1;
        }
        else
        {
            int mid = (L+R)>>1;
            Push_Down(rt);
            if(from<=mid)
            {
                Update(lson,from,to,val);
            }
            if(to>mid)
            {
                Update(rson,from,to,val);
            }
            Push_Up(rt);
        }
    }
    int Query(int L,int R,int rt,int from,int to)
    {
        if(from<=L&&R<=to)
        {
            return sum[rt];
        }
        else
        {
            int mid = (L+R)>>1;
            Push_Down(rt);
            int ret=0;
            if(from<=mid)
            {
                ret+=Query(lson,from,to);
            }
            if(to>mid)
            {
                ret+= Query(rson,from,to);
            }
            return ret;
        }
    }

} Seg;
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int n,m;
        scanf("%d%d",&n,&m);
        Seg.Build(1,n,1);
        while(m--)
        {
            int k,a,b;
            scanf("%d%d%d",&k,&a,&b);
            ++a;
            if(k==1)
            {
                int l=a,r=n,mid,ans=-1;
                while(l<=r)
                {
                    mid=(l+r)/2;
                    int cnt=Seg.Query(1,n,1,a,mid);
                    if(cnt>=1)
                    {
                        ans=mid;
                        r = mid - 1;
                    }
                    else
                    {
                        l = mid + 1;
                    }
                }
                if(~ans)
                {
                    int left=ans;
                    l=left;
                    r=n,mid,ans=-1;
                    while(l<=r)
                    {
                        mid=(l+r)/2;
                        int cnt=Seg.Query(1,n,1,left,mid);
                        if(cnt>=b)
                        {
                            ans=mid;
                            r = mid - 1;
                        }
                        else
                        {
                            l = mid + 1;
                        }
                    }
                    if(~ans)
                    {
                        //printf("sum = %d b = %d\n",Seg.Query(1,n,1,left,ans),b);
                        //puts("hered1");
                        Seg.Update(1,n,1,left,ans,0);
                        printf("%d %d\n",left-1,ans-1);
                    }
                    else
                    {
                        l=ans;
                        //printf("pans = %d\n",ans);
                        r=n,mid,ans=-1;
                        while(l<=r)
                        {
                            mid=(l+r)/2;
                            int cnt=Seg.Query(1,n,1,mid,n);
                            if(cnt>=1)
                            {
                                ans=mid;
                                l = mid + 1;
                            }
                            else
                            {
                                r = mid - 1;
                            }
                        }
                        //printf("ans = %d\n",ans);
                        //puts("hered2");
                        Seg.Update(1,n,1,left,ans,0);
                        printf("%d %d\n",left-1,ans-1);
                    }
                }
                else
                {
                    puts("Can not put any one.");
                }
            }
            else
            {
                if(b>n-1)b=n-1;
                ++b;
                int sum = Seg.Query(1,n,1,a,b);
                //printf("sum empty = %d\n",sum);
                sum = b-a+1-sum;
                printf("%d\n",sum);
                Seg.Update(1,n,1,a,b,1);
            }
        }
        puts("");
    }
    return 0;
}
