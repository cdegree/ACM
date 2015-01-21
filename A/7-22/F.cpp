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
using namespace std;

typedef long long LL ;

vector<LL> gao(int n)
{
    vector<LL> ret;
    LL e=1;
    for(LL i =1 ; i<n; ++i)
    {
        e*=10;
    }
    LL m = e;
    e*=10;
    while(m<e)
    {
        ret.push_back(m);
        ++m;
    }
    return ret;
}

int res[5]={0,14,155,1575};
int main()
{
    int n;
    while(~scanf("%d",&n))
    {
        if(n<=3)
        {
            printf("%d\n",res[n]);
        }
        else
        {
            printf("%d",res[3]);
            for(int i=0;i<n-3;++i)
            {
                printf("0");
            }
            puts("");
        }
        /*
        vector<LL> a = gao(n);
        vector<LL> b = gao(n);
        LL e=1;
        for(LL i =1 ; i<=n; ++i)
        {
            e*=10;
        }
        set<LL> c;
        for(int i=0; i<a.size(); ++i)
        {
            for(int j=0; j<b.size(); ++j)
            {
                //printf("%lld , %lld\n",a[i],b[j]);
                LL now = a[i]*e+b[j];
                if(((now%a[i])==0)&&((now%b[j])==0))
                {
                    c.insert(now);
                }
            }
        }
        int i=0;
        for( set<LL>::iterator it = c.begin(); it != c.end(); ++it)
        {
            //printf("%d: %lld\n",i++,(*it));
        }
        cout<<c.size()<<endl;
        */
        /*
        vector<LL> a = gao(n);
        vector<LL> b = gao(n);
        LL e=1;
        for(LL i =1 ; i<=n; ++i)
        {
            e*=10;
        }
        set<LL> c;
        for(int i=0; i<a.size(); ++i)
        {
            for(int j=0; j<b.size(); ++j)
            {
                //printf("%lld , %lld\n",a[i],b[j]);
                LL now = a[i]*e+b[j];
                if(((now%a[i])==0)&&((now%b[j])==0))
                {
                    c.insert(now);
                }
            }
        }
        int i=0;
        for( set<LL>::iterator it = c.begin(); it != c.end(); ++it)
        {
            //printf("%d: %lld\n",i++,(*it));
        }
        cout<<c.size()<<endl;
        *//*
        vector<LL> a = gao(n);
        vector<LL> b = gao(n);
        LL e=1;
        for(LL i =1 ; i<=n; ++i)
        {
            e*=10;
        }
        set<LL> c;
        for(int i=0; i<a.size(); ++i)
        {
            for(int j=0; j<b.size(); ++j)
            {
                //printf("%lld , %lld\n",a[i],b[j]);
                LL now = a[i]*e+b[j];
                if(((now%a[i])==0)&&((now%b[j])==0))
                {
                    c.insert(now);
                }
            }
        }
        int i=0;
        for( set<LL>::iterator it = c.begin(); it != c.end(); ++it)
        {
            //printf("%d: %lld\n",i++,(*it));
        }
        cout<<c.size()<<endl;
        *//*
        vector<LL> a = gao(n);
        vector<LL> b = gao(n);
        LL e=1;
        for(LL i =1 ; i<=n; ++i)
        {
            e*=10;
        }
        set<LL> c;
        for(int i=0; i<a.size(); ++i)
        {
            for(int j=0; j<b.size(); ++j)
            {
                //printf("%lld , %lld\n",a[i],b[j]);
                LL now = a[i]*e+b[j];
                if(((now%a[i])==0)&&((now%b[j])==0))
                {
                    c.insert(now);
                }
            }
        }
        int i=0;
        for( set<LL>::iterator it = c.begin(); it != c.end(); ++it)
        {
            //printf("%d: %lld\n",i++,(*it));
        }
        cout<<c.size()<<endl;
        *//*
        vector<LL> a = gao(n);
        vector<LL> b = gao(n);
        LL e=1;
        for(LL i =1 ; i<=n; ++i)
        {
            e*=10;
        }
        set<LL> c;
        for(int i=0; i<a.size(); ++i)
        {
            for(int j=0; j<b.size(); ++j)
            {
                //printf("%lld , %lld\n",a[i],b[j]);
                LL now = a[i]*e+b[j];
                if(((now%a[i])==0)&&((now%b[j])==0))
                {
                    c.insert(now);
                }
            }
        }
        int i=0;
        for( set<LL>::iterator it = c.begin(); it != c.end(); ++it)
        {
            //printf("%d: %lld\n",i++,(*it));
        }
        cout<<c.size()<<endl;
        *//*
        vector<LL> a = gao(n);
        vector<LL> b = gao(n);
        LL e=1;
        for(LL i =1 ; i<=n; ++i)
        {
            e*=10;
        }
        set<LL> c;
        for(int i=0; i<a.size(); ++i)
        {
            for(int j=0; j<b.size(); ++j)
            {
                //printf("%lld , %lld\n",a[i],b[j]);
                LL now = a[i]*e+b[j];
                if(((now%a[i])==0)&&((now%b[j])==0))
                {
                    c.insert(now);
                }
            }
        }
        int i=0;
        for( set<LL>::iterator it = c.begin(); it != c.end(); ++it)
        {
            //printf("%d: %lld\n",i++,(*it));
        }
        cout<<c.size()<<endl;
        */
    }
    return 0;
}
