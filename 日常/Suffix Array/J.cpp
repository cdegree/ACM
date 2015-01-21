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

const int maxn = 100202;
int wa[maxn],wb[maxn],wv[maxn],Ws[maxn];
int cmp(int *r,int a,int b,int l)
{
    return r[a]==r[b]&&r[a+l]==r[b+l];
}
void da(int *r,int *sa,int n,int m)
{
    int i,j,p,*x=wa,*y=wb,*t;
    for(i=0; i<m; i++) Ws[i]=0;
    for(i=0; i<n; i++) Ws[x[i]=r[i]]++;
    for(i=1; i<m; i++) Ws[i]+=Ws[i-1];
    for(i=n-1; i>=0; i--) sa[--Ws[x[i]]]=i;
    for(j=1,p=1; p<n; j*=2,m=p)
    {
        for(p=0,i=n-j; i<n; i++) y[p++]=i;
        for(i=0; i<n; i++) if(sa[i]>=j) y[p++]=sa[i]-j;
        for(i=0; i<n; i++) wv[i]=x[y[i]];
        for(i=0; i<m; i++) Ws[i]=0;
        for(i=0; i<n; i++) Ws[wv[i]]++;
        for(i=1; i<m; i++) Ws[i]+=Ws[i-1];
        for(i=n-1; i>=0; i--) sa[--Ws[wv[i]]]=y[i];
        for(t=x,x=y,y=t,p=1,x[sa[0]]=0,i=1; i<n; i++)
            x[sa[i]]=cmp(y,sa[i-1],sa[i],j)?p-1:p++;
    }
    return;
}
int rank[maxn],height[maxn];
void calheight(int *r,int *sa,int n)
{
    int i,j,k=0;
    for(i=1; i<=n; i++) rank[sa[i]]=i;
    for(i=0; i<n; height[rank[i++]]=k)
        for(k?k--:0,j=sa[rank[i]-1]; r[i+k]==r[j+k]; k++);
    return;
}
int sa[maxn],r[maxn];

char p[1005],s[maxn];
int belong[maxn];
bool judge(int mid,int m,int n)
{
    set<int> q;
    for(int i=1; i<=m; ++i)
    {
        if(height[i]>=mid)
        {
            q.insert(belong[ sa[i-1] ]);
            q.insert(belong[ sa[i] ]);
            if(q.size()>=n)
            {
                return 1;
            }
        }
        else
        {
            q.clear();
        }
    }
    return 0;
}
set<string> res;
int main()
{
    int n,m;
    //freopen("Jin.txt","r",stdin);
    bool T=0;
    while(1)
    {
        scanf("%d",&n);
        if(n==0)break;
        if(T)puts("");
        T=1;
        m=0;
        for(int i=0; i<n; ++i)
        {
            scanf("%s",p);
            for(int j=0; j<strlen(p); ++j)
            {
                belong[m]=i;
                r[m++]=p[j];
            }
            belong[m]=n;
            r[m++]=i+256;
        }
        belong[m]=n;
        r[m]=0;
        da(r,sa,m+1,357);
        calheight(r,sa,m);
        int L=1,R=1000,mid,ans=-1;
        n=n/2+1;
        while(L<=R)
        {
            mid=(L+R)>>1;
            if(judge(mid,m,n))
            {
                ans=mid;
                L=mid+1;
            }
            else R=mid-1;
        }
        res.clear();
        if(~ans)
        {
            set<int> q;
            for(int i=1; i<=m; ++i)
            {
                if(height[i]>=ans)
                {
                    q.insert(belong[ sa[i-1] ]);
                    q.insert(belong[ sa[i] ]);
                    if(q.size()==n)
                    {
                        string tmp="";
                        for(int j=0;j<ans;++j)
                        {
                            tmp+=r[ sa[i]+j ];
                        }
                        res.insert(tmp);
                        while(i+1<=m&&height[i+1]>=ans)++i;
                    }
                }
                else
                {
                    q.clear();
                }
            }
            for(set<string>::iterator it = res.begin();it!=res.end();++it)
            {
                cout<<*it<<endl;
            }
        }
        else
        {
            puts("?");
        }
    }
    return 0;
}
