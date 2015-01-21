#include<stdio.h>
#define BG 1000000000000000000LL
#define long_long long long
long_long ans,l,h,p,n;
long_long a[18],b[505];
long_long gcd(long_long a,long_long b)
{
    if (b==0) return a;
    else return gcd(b,a%b);
}
long_long calc(long_long g,long_long k,long_long t)
{
    long_long gg,s;
    if (t==n+1)
    {
        if (k!=0)
        {
            s=gcd(p,g);
            if (p/s>BG/g) s=h+1;
            else
                s=p/s*g;
            if (k%2==0)
                ans-=h/g-(l-1)/g;//+(l-1)/(s)-h/(s);
            else
                ans+=h/g-(l-1)/g;//+(l-1)/(s)-h/(s);
        }
        return 0;
    }
    gg=gcd(g,a[t]);
    if (g/gg>BG/a[t]) gg=h+1;
    else gg=g/gg*a[t];
    calc(gg,k+1,t+1);
    calc(g,k,t+1);
}
int main()
{
    long_long m,i,k;
    while(scanf("%lld%lld%lld%lld",&n,&m,&l,&h)!=EOF)
    {
        if ((n==0)&&(m==0)&&(l==0)&&(h==0)) break;
        for(i=1; i<=n; i++)
            scanf("%lld",&a[i]);
        for(i=1; i<=m; i++)
            scanf("%lld",&b[i]);
        p=b[1];
        for(i=2; i<=m; i++)
        {
            k=gcd(p,b[i]);
            if (p/k>BG/b[i]) p=h+1;
            else
                p=p/k*b[i];
        }
        printf("p = %lld\n",p);
        ans=0;
        calc(1,0,1);
        printf("%lld\n",ans);
    }
}
