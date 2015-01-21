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

LL sum[300005],sumb[300005];
LL a[300005];

map<int,int> mp;
set< pair<int,int> > st[300005];

struct seg
{
    int l,r;
    LL sum;
}S[300005];
bool cmp(seg a,seg b)
{
    return a.sum>b.sum;
}
int res[300005];
int main()
{
    int n;
    while(cin>>n)
    {
        for(int i=0;i<n;++i)st[i].clear();
        mp.clear();
        sumb[0]=sum[0]=0;
        int T=0;
        for(int i=1;i<=n;++i)
        {
            scanf("%I64d",a+i);
            if(mp.find( a[i] )==mp.end())
            {
                mp[ a[i] ]=T++;
                st[ T-1 ].insert( make_pair( a[i],i ) );
            }
            else
            {
                st[ mp[a[i] ] ].insert( make_pair( a[i],i ) );
            }
            sum[i]=sum[i-1]+a[i];
            sumb[i]=sumb[i-1];
            if(a[i]<0)sumb[i]+=a[i];
            //printf(" s %I64d    sb    %I64d\n",sum[i],sumb[i]);
        }
        int len=0;
        for(int i=0;i<T;++i)
        {
            if(st[i].size()>1)
            {
                pair<int,int> l=*(st[i].begin());
                pair<int,int> r=*(st[i].rbegin());
                int lp = l.second;
                int rp = r.second;
                LL nowsum = sum[rp]-sum[lp-1];
                if(lp+1<=rp-1)
                {
                    nowsum -= (sumb[rp-1]-sumb[lp]);
                }
                S[len].sum=nowsum;
                S[len].l=lp;
                S[len++].r=rp;
            }
        }
        sort(S,S+len,cmp);
//        for(int i=0;i<len;++i)
//        {
//            printf("%d :  %d -> %d  = %I64d\n",i,S[i].l,S[i].r,S[i].sum);
//        }

        printf("%I64d ",S[0].sum);

        //printf("%d -> %d\n",S[0].l,S[0].r);
        len=0;
        for(int i=S[0].l+1;i<S[0].r;++i)
        {
            if(a[i]<0)
            {
                res[len++]=i;
            }
        }
        for(int i=1;i<S[0].l;++i)
        {
            res[len++]=i;
        }
        for(int i=S[0].r+1;i<=n;++i)
        {
            res[len++]=i;
        }
        printf("%d\n",len);
        for(int i=0;i<len;++i)
        {
            printf("%d%c",res[i],i==len-1?'\n':' ');
        }
    }
	return 0;
}
