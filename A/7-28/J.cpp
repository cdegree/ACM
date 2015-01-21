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


int main()
{
    int T;
    scanf("%d",&T);
    for(int t=1;t<=T;++t)
    {
        LL r,c,sr,sc,dr,dc;
        printf("Case %d: ",t);
        LL n;
        scanf("%lld %lld %lld %lld %lld %lld",&r,&c,&sr,&sc,&dr,&dc);
        if(r<c)
        {
            swap(r,c);
            swap(sr,sc);
            swap(dr,dc);
        }
        if(sr==dr&&sc==dc)
        {
            puts("0");
        }
        else if(c==1|| ((sr+sc)%2)!=((dr+dc)%2) )
        {
            puts("impossible");
        }
        else if(sr-sc==dr-dc||sr+sc==dr+dc  )
        {
            puts("1");
        }
        else
        {
            LL osr=sr,osc=sc;
            LL l=1,r=1e10,mid,ans=-1;
            LL add = c-1;
            LL okr,okc;
            LL upsr,dsr,upsc,dsc;
            bool up=true;
            while(l<=r)
            {
                mid = (l+r)/2;
                if(mid&1)
                {
                    upsr=osr+add*mid;
                    dsr=osr-add*mid;
                    sc=c-osc+1;
                }
                else
                {
                    upsr=osr+add*mid;
                    dsr=osr-add*mid;
                    sc=osc;
                }
                //printf("mid = %lld upsr=%lld dsr=%lld sc=%lld\n",mid,upsr,dsr,sc);
                //printf("dr=%lld dc=%lld\n",dr,dc);
                if(  (dr+dc>=dsr+sc&&dr+dc<=upsr+sc)||(dr-dc<=upsr-sc&&dr-dc>=dsr-sc)  )
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
               printf("%lld\n",ans+1);
            }
            else
            {
                puts("impossible");
            }
        }

    }

	return 0;
}
