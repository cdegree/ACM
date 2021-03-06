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
const int maxn = 100020;
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
int belong[maxn];
char s[maxn];
int pos[11][2];



bool judge(int mid,int len,int n)
{
    for(int j=0; j<n; ++j)pos[j][0]=maxn,pos[j][1]=0;
    bool ok=0;
    for(int i=1; i<=len; ++i)
    {
        if(height[i]>=mid)
        {
            int b = belong[ sa[i-1] ];
            if(sa[i-1]>pos[b][1])pos[b][1]=sa[i-1];
            if(sa[i-1]<pos[b][0])pos[b][0]=sa[i-1];
            b = belong[ sa[i] ];
            if(sa[i]>pos[b][1])pos[b][1]=sa[i];
            if(sa[i]<pos[b][0])pos[b][0]=sa[i];
        }
        else
        {
            bool valid=1;
            for(int j=0; j<n; ++j)
            {
                if(pos[j][1]-pos[j][0]<mid)
                {
                    valid=0;
                }
            }
            if(valid)
            {
                ok=1;
                break;
            }
            for(int j=0; j<n; ++j)pos[j][0]=maxn,pos[j][1]=0;
        }
    }
    bool valid=1;
    for(int j=0; j<n; ++j)
    {
        if(pos[j][1]-pos[j][0]<mid)
        {
            valid=0;
        }
    }
    if(valid)ok=1;
    return ok;
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int n;
        scanf("%d",&n);
        int len=0;
        for(int i=0; i<n; ++i)
        {
            scanf("%s",s);
            for(int j=0; j<strlen(s); ++j)
            {
                belong[len]=i;
                r[len++]=s[j];
            }
            belong[len]=10;
            r[len++]='z'+i+1;
        }
        r[len]=0;
        da(r,sa,len+1,256);
        calheight(r,sa,len);
        int L=0,R=maxn,ans=0,mid;
        while(L<=R)
        {
            mid=(L+R)>>1;
            if(judge(mid,len,n))
            {
                ans=mid;
                L=mid+1;
            }
            else R=mid-1;
        }
        printf("%d\n",ans);
    }
    return 0;
}
