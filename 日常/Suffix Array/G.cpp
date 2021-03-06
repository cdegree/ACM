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

const int maxn = 100005;
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

char s[maxn];
int r[maxn],sa[maxn];
int dp_max[maxn][21];  //20不一定是唯一的。需要计算log(n)/log(2)
int dp_min[maxn][21];
void rmq_init(int *c,int n)
{
    for(int i=1; i<=n; i++)
        dp_max[i][0] = dp_min[i][0] = c[i];
    double limit = log(1.0*n)/log(2.0);
    for(int j=1; j<=(int)limit; j++)
        for(int i=1; i+(1<<j)-1<=n; i++)
        {
            dp_max[i][j] = max(dp_max[i][j-1],dp_max[i+(1<<(j-1))][j-1]);
            dp_min[i][j] = min(dp_min[i][j-1],dp_min[i+(1<<(j-1))][j-1]);
        }
}
int get_max(int a,int b)
{
    int k = (int)(log(b-a+1.0)/log(2.0));
    return max(dp_max[a][k],dp_max[b-(1<<k)+1][k]);
}
int get_min(int a,int b)
{
    int k = (int)(log(b-a+1.0)/log(2.0));
    return min(dp_min[a][k],dp_min[b-(1<<k)+1][k]);
}


int query(int l,int r)
{
    int a=rank[l],b=rank[r];
    if(a>b)swap(a,b);
    return get_min(a+1,b);
}
int scmp(char *a,int *b,int l,int r)
{
    for(int j=l,i=0; j<r; ++j,++i)
    {
        if(a[i]!=b[j])
        {
            if(a[i]>b[j])return 1;
            else return -1;
        }
    }
    return 0;
}
char res[maxn];
int main()
{
    int T=1;
    while(~scanf("%s",s))
    {
        if(s[0]=='#')break;
        int n = strlen(s);

        for(int i=0; i<n; ++i)r[i]=s[i];
        r[n]=0;
        printf("Case %d: ",T++);
        da(r,sa,n+1,257);
        calheight(r,sa,n);
        rmq_init(height,n);
        int mx=1,pos=0;
        int cnt;
        memset(res,0,sizeof(res));
        res[0]=r[sa[1]];
        res[1]='\0';
        int br=n+1;
        for(int i=1; i<=n; ++i)
        {
            for(int j=0; j+i<n; j+=i)
            {
                int len = query(j,j+i);
                int p = j - (i-len%i);
                int L=j,R=j+i;
                if(p>=0&&query(p,p+i)>=i)len = query(p,p+i),L=p,R=p+i;
                while(L-1>=0&&r[L-1]==r[R-1])--L,--R,++len;
                if(len/i+1>mx)
                {
                    int p = len%i;
                    br=n+1;
                    mx=len/i+1;
                    for(int k=L; k<=L+p; ++k)
                    {
                        if(rank[k]<br)
                        {
                            br=rank[k];
                            cnt=0;
                            for(int j=k; j<mx*i+k; ++j)res[cnt++]=r[j];
                            res[cnt]='\0';
                        }
                    }
                }
                else if(len/i+1==mx)
                {
                    int p = len%i;
                    for(int k=L; k<=L+p; ++k)
                    {
                        if(rank[k]<br)
                        {
                            br=rank[k];
                            cnt=0;
                            for(int j=k; j<mx*i+k; ++j)res[cnt++]=r[j];
                            res[cnt]='\0';
                        }
                    }
                }
            }
        }
        printf("%s\n",res);
    }
    return 0;
}
