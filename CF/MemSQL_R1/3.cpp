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

LL P2[66];
LL up=1000000000000000000LL;

void init()
{
    for(int i=0;(1LL<<i)<=up;++i)
    {
        P2[i]=(1LL<<i);
    }
}
int count_cnt(LL n)
{
    int ret=0;
    while(n>0)
    {
        ++ret;
        n/=10;
    }
    return ret;
}

set<LL> get_res(LL n)
{
    set<LL> sn;
    sn.clear();
    for(int i=0;P2[i]-1<=n;++i)
    {
        LL l=1,r=1500000001LL,ans=-1,mid;
        while(l<=r)
        {
            mid = (l+r)/2;
            LL tmp = mid*(mid-1)/2 + mid*(P2[i]-1);
            if(count_cnt(mid)+count_cnt((P2[i]))>19)
            {
                r = mid ;
                continue;
            }
            if(tmp<=n)
            {
                l = mid + 1;
                if(tmp==n)
                {
                    ans=mid;
                }
            }
            else
            {
                r = mid - 1;
            }
        }
        if(~ans&&ans%2==1)
        {
            sn.insert(ans*P2[i]);
        }
    }
    return sn;
}
int main()
{
    LL n,m;
    init();
    while(cin>>n)
    {
        set<LL> ret = get_res(n);
        if(ret.size()==0)
        {
            cout<<-1<<endl;
        }
        else
        {
            for(set<LL>::iterator it = ret.begin();it!=ret.end();++it )
            {
                cout<<*it<<endl;
            }
        }
    }
	return 0;
}
