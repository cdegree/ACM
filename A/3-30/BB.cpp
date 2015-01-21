#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <algorithm>
#include <queue>
#include <iostream>

using namespace std;

int T;
int n;
long long a[100010],b[100010];
bool isprime(long long t)
{
    long long x=sqrt(t);
    if(t==1)
        return false;
    if(t==2)
        return true;
    if(t%2==0)
        return false;
    for(int i=3; i<=x; i+=2)
        if(t%i==0)
            return false;
    return true;
}
int prime[100005];
bool ispri[100005];
int len;
void init()
{
    len=0;
    for(int i=2;i<100005;i++)ispri[i]=true;
    for(int i=2;i<100005;i++)
    {
        if(ispri[i])
        {
            for(int j=i+i;j<100005;j+=i)
            {
                ispri[j]=false;
            }
            prime[len++]=i;
        }
    }
}


int main()
{
    //freopen("input.txt","r",stdin);
    scanf("%d",&T);
    int cas=0;
    while(T--)
    {
        printf("Case #%d: ",++cas);
        scanf("%d",&n);
        long long big=1;
        for(int i=1; i<=n; i++)
        {
            scanf("%lld",&b[i]);
            if(big<=1000000000)
                big*=b[i];
        }
        if(n==1)
        {
            printf("%lld\n",b[1]+1);
            continue;
        }
        sort(b+1,b+1+n);
        long long st=b[n]+1;
        bool pd=true;
        for(; st<=big; st++)
        {
            if(isprime(st))
            {
                pd=false;
                printf("%lld\n",st);
                break;
            }
            printf("%d\n",st);
            long long temp=st;
            for(int i=n-1; i>=1; i--)
            {
                if(b[i]==1)
                    break;
                if(temp<=b[n])
                    break;
                for(int j=b[i]; j>=2; j--)
                    if(temp%j==0)
                    {
                        temp/=j;
                        break;
                    }
            }
            if(temp>b[n])
            {
                pd=false;
                printf("%lld\n",temp);
                break;
            }
        }
        if(pd)
            puts("Good Function");
    }
}
