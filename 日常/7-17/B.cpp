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
const int N = 1000006;
int ind[N];
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int n,m;
        scanf("%d%d",&n,&m);
        memset(ind,0,sizeof(ind));
        for(int i=1;i<=n;++i)ind[i]=i-1;
        for(int i=0;i<m;++i)
        {
            int u,v;
            scanf("%d%d",&u,&v);
            if(u>v)
            {
                ind[u]--;
                ind[v]++;
            }
            else
            {
                ind[u]++;
                ind[v]--;
            }
        }
        int pos=-1;
        for(int i=1;i<=n;++i)
        {
            if(ind[i]==n-1)
            {
                pos=i;
                break;
            }
        }
        if(~pos)
        {
            printf("%d %d\n",2,pos);
        }
        else
        {
            puts("1");
        }
    }
	return 0;
}
