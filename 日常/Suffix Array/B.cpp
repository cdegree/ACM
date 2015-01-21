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
const int maxn = 20005;

int wa[maxn],wb[maxn],wv[maxn],Ws[maxn];

int cmp(int *r,int a,int b,int l)

{
    return r[a]==r[b]&&r[a+l]==r[b+l];
}

void da(int *r,int *sa,int n,int m)
{
    int i,j,p,*x=wa,*y=wb,*t;

    for(i=0;i<m;i++) Ws[i]=0;
    for(i=0;i<n;i++) Ws[x[i]=r[i]]++;
    for(i=1;i<m;i++) Ws[i]+=Ws[i-1];
    for(i=n-1;i>=0;i--) sa[--Ws[x[i]]]=i;

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
int R[maxn];
int sa[maxn];
int n,k;
bool judge(int mid)
{
    int l=0,r=0;
    for(int i=1;i<n;++i)
    {
        if(height[i]>=mid)
        {
            r=i;
            if(r-l+1>=k)
            {
                return true;
            }
        }
        else
        {
            l=i;
            r=i+1;
        }
    }
    return false;
}

int main()
{

    while(~scanf("%d%d",&n,&k))
    {
        for(int i=0; i<n; ++i)
        {
            scanf("%d",R+i);
            ++R[i];
        }
        R[n]=0;
        ++n;
        da(R,sa,n,maxn);
        calheight(R,sa,n-1);
        int l=0,r=1e8,mid,ans=-1;
        while(l<=r)
        {
            mid=(l+r)/2;
            if(judge(mid))
            {
                ans=mid;
                l=mid+1;
            }
            else r=mid-1;
        }
        printf("%d\n",ans);
    }
    return 0;
}
