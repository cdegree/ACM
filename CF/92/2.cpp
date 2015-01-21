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

int mp[1003][1003];
int res[1000006][2];
int ind[1004];
int main()
{
    int n,m;
    while(cin>>n>>m)
    {
        memset(mp,0,sizeof(mp));
        memset(ind,0,sizeof(ind));
        for(int i=0;i<m;++i)
        {
            int u,v;
            scanf("%d%d",&u,&v);
            mp[u][v]=-1;
            mp[v][u]=-1;
            ind[u]++;
            ind[v]++;
        }
        int src=-1;
        for(int i=1;i<=n;++i)
        {
            if(ind[i]==0)
            {
                src=i;
                break;
            }
        }
        int len=n-1;
        cout<<len<<endl;
        for(int i=1;i<=n;++i)
        {
            if(i!=src)
            printf("%d %d\n",src,i);
        }
    }
	return 0;
}
