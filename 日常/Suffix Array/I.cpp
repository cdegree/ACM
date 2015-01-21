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

const int maxn = 600003;
#define F(x) ((x)/3+((x)%3==1?0:tb))
#define G(x) ((x)<tb?(x)*3+1:((x)-tb)*3+2)
int wa[maxn],wb[maxn],wv[maxn],Ws[maxn];
int c0(int *r,int a,int b)
{
    return r[a]==r[b]&&r[a+1]==r[b+1]&&r[a+2]==r[b+2];
}
int c12(int k,int *r,int a,int b)
{
    if(k==2) return r[a]<r[b]||r[a]==r[b]&&c12(1,r,a+1,b+1);
    else return r[a]<r[b]||r[a]==r[b]&&wv[a+1]<wv[b+1];
}
void sort(int *r,int *a,int *b,int n,int m)
{
    int i;
    for(i=0; i<n; i++) wv[i]=r[a[i]];
    for(i=0; i<m; i++) Ws[i]=0;
    for(i=0; i<n; i++) Ws[wv[i]]++;
    for(i=1; i<m; i++) Ws[i]+=Ws[i-1];
    for(i=n-1; i>=0; i--) b[--Ws[wv[i]]]=a[i];
    return;
}
void dc3(int *r,int *sa,int n,int m)
{
    int i,j,*rn=r+n,*san=sa+n,ta=0,tb=(n+1)/3,tbc=0,p;
    r[n]=r[n+1]=0;
    for(i=0; i<n; i++) if(i%3!=0) wa[tbc++]=i;
    sort(r+2,wa,wb,tbc,m);
    sort(r+1,wb,wa,tbc,m);
    sort(r,wa,wb,tbc,m);
    for(p=1,rn[F(wb[0])]=0,i=1; i<tbc; i++)
        rn[F(wb[i])]=c0(r,wb[i-1],wb[i])?p-1:p++;
    if(p<tbc) dc3(rn,san,tbc,p);
    else for(i=0; i<tbc; i++) san[rn[i]]=i;
    for(i=0; i<tbc; i++) if(san[i]<tb) wb[ta++]=san[i]*3;
    if(n%3==1) wb[ta++]=n-1;
    sort(r,wb,wa,ta,m);
    for(i=0; i<tbc; i++) wv[wb[i]=G(san[i])]=i;
    for(i=0,j=0,p=0; i<ta && j<tbc; p++)
        sa[p]=c12(wb[j]%3,r,wa[i],wb[j])?wa[i++]:wb[j++];
    for(; i<ta; p++) sa[p]=wa[i++];
    for(; j<tbc; p++) sa[p]=wb[j++];
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

char s1[maxn],s2[maxn];

LL cnt[maxn],h[maxn];
int top;
int main()
{
    int k,n,m;
    while(1)
    {
        scanf("%d",&k);
        if(k==0)break;
        memset(cnt,0,sizeof(cnt));
        memset(h,0,sizeof(h));
        scanf("%s%s",s1,s2);
        m=n=strlen(s1);
        s1[n]='$';
        s1[n+1]='\0';
        strcat(s1,s2);
        n=strlen(s1);
        for(int i=0; i<n; ++i)r[i]=s1[i];
        r[n]=0;
        dc3(r,sa,n+1,200);
        calheight(r,sa,n);
        int cnt1=0,cnt2=0;
        LL res=0;
        top=0;
        LL here_cnt=0;
        for(int i=1; i<=n; ++i)
        {
            if(height[i]>=k)
            {
                LL tmp=0;
                while(top>=0&&height[i]<=h[top])
                {
                    here_cnt-=( cnt[top]*(h[top]-k+1) );
                    tmp+=cnt[top];
                    cnt[top]=0;
                    --top;
                }
                ++top;
                cnt[top]=tmp;
                h[top]=height[i];
                if(sa[i-1]>m)++cnt[top];
                here_cnt+=(cnt[top]*(h[top]-k+1));
                if(sa[i]<m)
                {
                    res+=here_cnt;
                }
            }
            else
            {
                top=0;
                here_cnt=0;
                h[0]=1000000;
                cnt[0]=0;
            }
        }
        top=0;
        here_cnt=0;
        for(int i=1; i<=n; ++i)
        {
            if(height[i]>=k)
            {
                LL tmp=0;
                while(top>=0&&height[i]<=h[top])
                {
                    here_cnt-=( cnt[top]*(h[top]-k+1) );
                    tmp+=cnt[top];
                    cnt[top]=0;
                    --top;
                }
                ++top;
                cnt[top]=tmp;
                h[top]=height[i];
                if(sa[i-1]<m)++cnt[top];
                here_cnt+=(cnt[top]*(h[top]-k+1));
                if(sa[i]>m)
                {
                    res+=here_cnt;
                }
            }
            else
            {
                top=0;
                here_cnt=0;
                cnt[0]=0;
                h[0]=1000000;
            }
        }
        printf("%I64d\n",res);
    }
    return 0;
}
