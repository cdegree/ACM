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

const int N = 100005;
int T[N],C[N];
int main()
{
    int n,q;
    while(~scanf("%d%d",&n,&q))
    {
        for(int i=1; i<=n; ++i)scanf("%d",T+i);
        bool all = 0;
        for(int i=1; i<=n; ++i)
        {
            scanf("%d",C+i);
            if(C[i]==1)all=1;
        }
        while(q--)
        {
            int p;
            scanf("%d",&p);
            if(p<=0)
            {
                puts("NO");
            }
            else if(all)
            {
                puts("YES");
            }
            else if(p%2==0)
            {
                puts("YES");
            }
            else
            {
                puts("NO");
            }
        }
    }
    return 0;
}
