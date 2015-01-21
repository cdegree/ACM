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

const LL inf = 100000000000LL;
struct program
{
    string s;
    LL mn,mx;
    LL val;
    int opcnt;
    char op[4];
    LL on;
    bool cut;
} P[555];

string f,cmp,tn,ton,rt;
set<pair<string,LL> > sp;
bool remain[555];
bool used[555];

bool coverall(program a,program b)
{
    return min(a.mn,b.mn)==-inf&&max(a.mx,b.mx)==inf&& min(a.mx,b.mx)>=max(a.mn,b.mn);
}
bool coverall(program a,program b, program c)
{
    if(a.val==b.val&&a.val==c.val&& ((c.opcnt|a.opcnt|b.opcnt)==7) )return 1;
    return 0;
}
int main()
{
    int n;
    while(~scanf("%d",&n))
    {
        memset(used,false,sizeof(used));
        memset(remain,0,sizeof(remain));
        for(int i=0; i<n; ++i)
        {
            LL val,l;
            cin>>f>>P[i].s>>P[i].op>>P[i].val>>tn>>ton>>P[i].on>>rt;
            val=P[i].val;
            //scanf("%s %s %s %lld %s %s %lld %s",f,P[i].s,P[i].op,&val,tn,ton,right,&P[i].on);
            if(P[i].op[0]=='=')
            {
                P[i].mn=P[i].mx=val;
                P[i].opcnt=1;
            }
            else if(P[i].op[0]=='<')
            {
                P[i].mn=-inf;
                P[i].mx=val-1;
                P[i].opcnt=2;
            }
            else
            {
                P[i].mn=val+1;
                P[i].mx=inf;
                P[i].opcnt=4;
            }
            P[i].cut=0;
        }
        for(int i=0;i<n;++i)
        {
            for(int j=0;j<n;++j)
            {
                if(i==j)continue;
                if(P[i].on==P[j].on&&!P[i].cut&&P[i].s==P[j].s&&P[i].mn<=P[j].mn&&P[i].mx>=P[j].mx)
                {
                    P[j].cut=1;
                }
            }
        }
        sp.clear();
        int len=0;
        for(int i=0; i<n; ++i)
        {
            for(int j=0; j<n; ++j)
            {
                if(i==j||used[i]||used[j])continue;
                if( P[i].s==P[j].s&&P[i].on==P[j].on&&coverall(P[i],P[j]))
                {
                    pair<string,LL> pa = make_pair( P[i].s,P[i].on);
                    if(sp.find( pa )== sp.end())
                    {
                        used[i]=1,used[j]=1;
                        remain[i]=1;
                        remain[j]=1;
                        sp.insert(pa);
                    }
                }
            }
        }
        for(int i=0; i<n; ++i)
        {
            for(int j=0; j<n; ++j)
            {
                for(int k=0; k<n; ++k)
                {
                    if(i!=j&&i!=k&&j!=k&&!used[i]&&!used[j]&&!used[k])
                    {
                        if(P[i].s==P[j].s&&P[i].s==P[k].s)
                        {
                            if(coverall(P[i],P[j],P[k]))
                            {
                                pair<string,LL> pa = make_pair( P[i].s,P[i].on);
                                if(sp.find( pa )== sp.end())
                                {
                                    used[i]=1,used[j]=1,used[k]=1;
                                    remain[i]=1;
                                    remain[j]=1;
                                    remain[k]=1;
                                    sp.insert(pa);
                                }
                            }
                        }
                    }
                }
            }
        }
        for(int i=0;i<n;++i)
        {
            cout<<P[i].s<<" op = "<<P[i].op<<" ";
            printf("%lld -> %lld   on %lld\n",P[i].mn,P[i].mx,P[i].on);
        }
        int res=0;
        for(set<pair<string,LL> >::iterator it = sp.begin() ;it!=sp.end();++it )
        {
            string s = (*it).X;
            LL p = (*it).Y;
            for(int k=0;k<n;++k)
            {
                if( !remain[k] &&( P[k].cut || (s==P[k].s||p==P[k].on ) ) )
                {
                    ++res;
                    remain[k]=1;
                    printf("k=%d\n",k);
                }
            }
        }
        cout<<res<<endl;
    }
    return 0;
}
