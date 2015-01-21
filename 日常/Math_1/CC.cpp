#include<stdio.h>
#include<string.h>
#include<math.h>
__int64 ar[200],br[200];
__int64 a[200],b[200];
double pp=0.00001;
__int64 n,m;
__int64 fun()
{
    __int64 f,sum,i,j,s1,s2;
    memset(ar,0,sizeof(ar));
    memset(br,0,sizeof(br));
    memset(a,0,sizeof(a));
    memset(b,0,sizeof(b));
    if(n==m)
    {
        i=0;f=m;
        while(f>=1)
        {
            f/=2;
            i++;
        }
        f=i;

        for(;i>0;i--)
        {
            if(i==1)
            {
              return 1;
            }
            s1=(__int64)(pow((n+0.0),(double)(1.0/i))+pp);
            s2=1;
            for(j=0;j<i;j++)
                s2*=s1;

            if(s2==n)
            {
                return (i);
            }
        }
    }
    else
    {
        i=0;f=m;
        while(f>=1)
        {
            f/=2;
            i++;
        }
        f=i;
        for(;i>0;i--)
        {
            if(i==1)
            {
                br[1]=n-1;
                ar[1]=m;
            }
            else
            {
                s1=(__int64)(pow((n+0.0),((1.0)/(i+0.0)))+pp);
                s2=1;
                for(j=0;j<i;j++)
                    s2*=s1;
                if(s2>n)
                    s1--;

                s2=1;
                for(j=0;j<i;j++)
                    s2*=s1;

                if(s2==n)
                    s1--;
                br[i]=s1;

                s1=(__int64)(pow((m+0.0),((1.0)/(i+0.0)))+pp);
                s2=1;
                for(j=0;j<i;j++)
                    s2*=s1;

                if(s2>m)
                    s1--;
                ar[i]=s1;
            }
        }
        for(i=f;i>=1;i--)
        {
            b[i]=ar[i]-br[i];
            a[i]=b[i];
            for(j=i+i;j<=f;j+=i)
                a[i]-=a[j];
        }
        sum=0;
        for(i=1;i<=f;i++)
            sum+=i*a[i];
        return (sum);
    }
}
int main()
{
    while(scanf("%I64d%I64d",&n,&m)!=EOF)
    {
        if(n==0&&m==0)
            break;
        printf("%I64d\n",fun());
    }
    return 0;
}
