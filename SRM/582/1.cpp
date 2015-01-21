#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;
typedef long long LL;

struct enemy
{
    int s;
    LL c;
}E[55];
vector<int> ggs;
bool cmp(enemy a,enemy b)
{
    return a.s>b.s;
}
class SpaceWarDiv1 {
public:
	long long minimalFatigue(vector <int> gs, vector <int> es, vector <LL> ec) {
        int n = gs.size();
        ggs=gs;
        for(int i=0;i<n;++i)
        {
            E[i].s=es[i];
            E[i].c=ec[i];
        }
        sort(ggs.rbegin(),ggs.rend());
        sort(E,E+n,cmp);
        LL inf = 1e14+5;
        LL l=1,r=inf,mid,ans=-1;
        while(l<=r)
        {
            mid = (l+r)/2;
            if(ok(mid))
            {
                r = mid - 1;
                ans=mid;
            }
            else
            {
                l=mid+1;
            }
        }
        return ans;
    }
    bool ok(LL m)
    {
        int n =ggs.size();
        LL cnt[55];
        int es[55];
        for(int i=0;i<n;++i)
        {
            cnt[i]=E[i].c;
            es[i]=E[i].s;
        }
        for(int i=0;i<n;++i)
        {
            int s=ggs[i];
            LL res=m;
            for(int j=0;j<n;++j)
            {
                if(es[j]<=s)
                {
                    if(res>=cnt[j])
                    {
                        res-=cnt[j];
                        cnt[j]=0;
                    }
                    else
                    {
                        cnt[j]-=res;
                        res=0;
                    }
                }
                if(res==0)break;
            }
        }
        for(int i=0;i<n;++i)
        {
            if(cnt[i]>0)
            {
                return false;
            }
        }
        return true;
    }
};
