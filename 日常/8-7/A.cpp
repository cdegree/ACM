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

const int N = 1005;
struct CaoDai
{
    char nam[22];
    LL from,to;
}C[N];
int n,m;
int main()
{
    while(1)
    {
        scanf("%d%d",&n,&m);
        if(n==0&&m==0)break;
        for(int i=0;i<n;++i)
        {
            LL last,to;
            scanf("%s%lld%lld",C[i].nam,&last,&C[i].to);
            C[i].from=C[i].to-last+1;
        }
        LL y;
        for(int i=0;i<m;++i)
        {
            scanf("%lld",&y);
            int pos=-1;
            for(int j=0;j<n;++j)
            {
                if(y>=C[j].from&&y<=C[j].to)
                {
                    pos=j;
                    break;
                }
            }
            if(~pos)
            {
                printf("%s %lld\n",C[pos].nam,y-C[pos].from+1);
            }
            else
            {
                puts("Unknown");
            }
        }
    }
	return 0;
}
