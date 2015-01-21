#include <iostream>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <algorithm>
#include <stdlib.h>
#include <string>
#include <queue>
#include <vector>

#define maxn 2200000
#define oo 1000000000
#define clearAll(a) memset(a,0,sizeof(a))
#define sq(a) ((a)*(a))

using namespace std;

typedef long long ll;

int dis[maxn];
int q[maxn*2];
int pre[maxn];
int pre_state[maxn];
int g[25][25];
int num[25];
int set[25];
int n,m;
bool vis[maxn];
int find(int x)
{
	return (set[x]==x)?x:set[x]=find(set[x]);
}

void output(int i,int d)
{
	if (pre[i]==-1)
	{
		printf("%d:",d);
		return ;
	}
    output(pre_state[i],d+1);
	printf(" %d",pre[i]);

}

int main()
{
    freopen("Ain.txt","r",stdin);
    //freopen("C:\\Users\\py\\Desktop\\output.txt","w",stdout);

    while (true)
    {
    	scanf("%d%d",&n,&m);
    	if (n==0&&m==0)
    	{
    	    puts("");
    	    break;
        }

    	clearAll(g);
    	clearAll(num);
    	memset(dis,-1,sizeof(dis));
    	memset(vis,false,sizeof(vis));
    	int x,y;
    	bool flag = true;

    	//for (int i=0;i<n;i++) set[i]=i;

    	for (int i=1;i<=m;i++)
    	{
    		scanf("%d%d",&x,&y);
    		num[x]++;
    		num[y]++;
    		g[x][num[x]]=y;
    		g[y][num[y]]=x;
    		/*
    		xx = find(x);
    		yy = find(y);
    		if (xx==yy)flag=false;
    		else set[xx]=yy;
    		*/
    	}

  //  	if (!flag)
    	{
   // 		printf("Impossible\n");
   // 		continue;
    	}

    	int l=0,r=0,now,next,tmp;
    	int init = ((1<<n)-1);
    	pre[init]=-1;
    	q[l]=init;
    	dis[init]=0;

    	while (l<=r)
    	{
    		now = q[l++];
    		if(vis[now])break;
    		vis[now]=true;
    		if(now==0)break;

    		for (int i=0;i<n;i++)
    		{
    			if (now&(1<<i))
	    		{
	    			tmp = (now^(1<<i));
	    			next = 0;
	    			for (int j=0;j<n;j++)
					{
							if (tmp&(1<<j))
							{
								for (int k=1;k<=num[j];k++)
								{
									next|=(1<<g[j][k]);
				 				}
							}
					}
	    			if (dis[next]!=-1) continue;
	    			dis[next]=dis[now]+1;
	    			pre[next]=i;
	    			pre_state[next]=now;
					q[++r]=next;
    			}
    		}
    	}

    	if (dis[0]==-1) printf("Impossible"); 
    	else output(0,0);

    	printf("\n");
    }

    return 0;
}