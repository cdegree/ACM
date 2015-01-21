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
#include <string>
#include <iostream>
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

int r[maxn],sa[maxn];

int main()
{
    int n,m;
    while(1)
    {
        scanf("%d",&n);
        if(!n)break;
        m=200;
        int pre,a;
        scanf("%d",&pre);
        for(int i=0; i<n-1; ++i)
        {
            scanf("%d",&a);
            r[i]=a-pre+100;
            pre=a;
        }
        r[n-1]=0;
        da(r,sa,n,m);
        calheight(r,sa,n-1);
        int L=4,R=20000,mid,ans=-1;
        while(L<=R)
        {
            mid=(L+R)>>1;
            int mn=1e8,mx=0,ok=0;
            for(int i=1; i<n; ++i){
                if(height[i]>=mid)
                {
                    mn=min(mn,sa[i]);
                    mx=max(mx,sa[i]);
                    mn=min(mn,sa[i-1]);
                    mx=max(mx,sa[i-1]);
                }
                else
                {
                    if(mx-mn>mid)
                    {
                        ok=1;
                        break;
                    }
                    mn=1e8,mx=0;
                }
            }
            if(mx-mn>mid)ok=1;
            if(ok)
            {
                ans=mid;
                L = mid+1;
            }
            else R=mid-1;
        }
        printf("%d\n",ans+1);
    }
    return 0;
}
