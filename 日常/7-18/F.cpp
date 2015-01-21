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

const int maxn = 1000005;

LL tree_cnt[maxn],tree_price[maxn];

void add_cnt(int pos,LL val)
{
    while(pos<maxn)
    {
        tree_cnt[pos] += val;
        pos += (pos&-pos);
    }
}

LL sum_cnt(int pos)
{
    LL ret = 0;
    while(pos>0)
    {
        ret += tree_cnt[pos];
        pos -= ((-pos)&pos);
    }
    return ret;
}

void add_price(int pos,LL val)
{
    while(pos<maxn)
    {
        tree_price[pos] += val;
        pos += ((-pos)&pos);
    }
}

LL sum_price(int pos)
{
    LL ret = 0;
    while(pos>0)
    {
        ret += tree_price[pos];
        pos -= (-pos&pos);
    }
    return ret;
}
int main()
{
    freopen("Fin.txt","r",stdin);
    char s[11];
    LL a,b;
    for(int i=0; i<maxn; ++i)
    {
        tree_cnt[i]=0;
        tree_price[i]=0;
    }
    map<LL,LL> mp;   // price , n;
    mp.clear();
    while(~scanf("%s%I64d%I64d",s,&a,&b))
    {
        if(s[0]=='A')
        {
            add_cnt(b,a);
            add_price(b,a*b);
            mp[b]+=b; // price , n
        }
        else
        {
            LL l=1,r=maxn-1,mid,ans=-1;
            while(l<=r)
            {
                mid = (l+r)/2;
                if(sum_cnt(mid)>=a)
                {
                    ans = mid;
                    r = mid - 1;
                }
                else
                {
                    l = mid + 1;
                }
            }
            if(~ans)
            {
                LL ccnt = sum_cnt(ans);
                LL ex = ccnt - a;
                LL sumprice = sum_price(ans);
                sumprice -= ex*ans;
                //printf("ex = %lld sump = %lld  get = %lld\n",ex,sumprice,b);
                if(sumprice<=b)
                {
                    puts("HAPPY");
                    for( map<LL,LL>::iterator it = mp.begin(); it!=mp.end() ; )
                    {
                        LL pri = it->first;
                        if(pri<ans)
                        {
                            LL cnt = sum_cnt(pri);
                            add_cnt(pri,-cnt);
                            add_price(pri,-cnt*pri);
                            ++it;
                            mp.erase(pri);
                        }
                        else
                        {
                            break;
                        }
                    }
                    ccnt = sum_cnt(ans);
                    ex = ccnt - ex;
                    add_cnt(ans,-ex);
                    add_price(ans,-ex*ans);
                }
                else
                {
                    puts("UNHAPPY");
                }
            }
            else
            {
                puts("UNHAPPY");
            }

        }
        //printf("1 = %lld\n",sum_cnt(1));
        //printf("200 = %lld\n",sum_cnt(200)-sum_cnt(199));
    }
    return 0;
}
