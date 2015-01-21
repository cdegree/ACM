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

using namespace std;

typedef long long LL ;
const int N = 505;
int dis[N];
int belongto[10005];
int n,m,l;
int cost[N][N];
const int inf = 1e8;
int spfa(int st,int ed1,int ed2)
{
    bool vis[N];
    for(int i=1;i<=m;i++)dis[i]=inf,vis[i]=0;
    dis[st]=0;
    //printf("st = %d\n",st);
    for(int i=0;i<m;i++)
    {
        int mn = inf;
        int pos = -1;
        for(int j=1;j<=m;j++)
        {
            if(!vis[j]&&dis[j]<mn)
            {
                mn=dis[j];
                pos=j;
            }
        }
        if(pos==-1)break;
        vis[pos]=true;
        for(int j=1;j<=m;j++)
        {
            if( !vis[j] && dis[pos] + cost[pos][j] < dis[j])
            {
                dis[j] = dis[pos] + cost[pos][j];
            }
        }
    }

    return dis[ed1]+dis[ed2];
}

int main()
{

    int T=0;
    freopen("in.txt","r",stdin);
    while(scanf("%d %d %d",&n,&m,&l)!=EOF)
    {
        int t;
        for(int i=1;i<=n;++i)
        {
            scanf("%d",&t);
            belongto[i]=t;
        }
        int a,b,c;
        for(int i=1;i<=m;++i)for(int j=1;j<=m;++j)cost[i][j]=inf;
        for(int i=1;i<=m;++i)cost[i][i]=0;
        for(int i=0;i<l;++i)
        {
            scanf("%d %d %d",&a,&b,&c);
            cost[a][b]=c;
            cost[b][a]=c;
        }
        for(int k=1;k<=m;++k)
        {
            for(int i=1;i<=m;++i)
            {
                for(int j=1;j<=m;++j)
                {
                    cost[i][j]=(cost[i][j]<cost[i][k]+cost[k][j])?cost[i][j]:cost[i][k]+cost[k][j];
                }
            }
        }
        printf("Case #%d\n",++T);
        int q;
        scanf("%d",&q);
        int s1,s2,s3,c1,c2,c3;
        LL mn,mx;
        for(int i=1;i<=q;++i)
        {
            scanf("%d %d %d",&a,&b,&c);
            printf("Line %d: ",i);
            s1 = belongto[a];
            s2 = belongto[b];
            s3 = belongto[c];
            //c1 = spfa(s1,s2,s3);
            //c2 = spfa(s2,s3,s1);
            //c3 = spfa(s3,s1,s2);
            c1 = cost[s1][s2];
            c2 = cost[s1][s3];
            c3 = cost[s2][s3];
            //printf("%d %d %d\n",c1,c2,c3);
            mx = c1>c2?c1:c2;
            mx = mx>c3?mx:c3;
            mn = c1+c2+c3-mx;
            //printf("%d,%d,%d   mn = %d\n",c1,c2,c3,mn);
            if(mx==inf)
            {
                printf("Impossible to connect!\n");
            }
            else
            {
                printf("The minimum cost for this line is %d.\n",mn);
            }
        }
    }
	return 0;
}
