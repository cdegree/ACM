#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <algorithm>
#include <queue>
#include <iostream>

using namespace std;
int a[10010],b[10010];
int n;
bool vis[100010];
bool final[10010];
void dfs(int step)
{
	if(step==n+1)
	{
	    for(int i=0;i<10010;i++)
            if(vis[i])
                final[i]=vis[i];
	    return ;
	}


	bool fuck[100010];
	for(int i=0;i<100010;i++)
		fuck[i]=vis[i];
	for(int i=1;i<=b[step];i++)
	{
		for(int j=10000;j>=1;j--)
		{
			if(vis[j])
			{
				vis[j*i]=true;
				//cout<<j*i<<endl;
			}
		}
		dfs(step+1);
		for(int j=0;j<100010;j++)
			vis[j]=fuck[j];
	}
}
int main()
{
    //freopen("input.txt","r",stdin);
    while(cin>>n)
    {
    	memset(vis,false,sizeof(vis));
    	memset(final,false,sizeof(final));
    	vis[1]=true;
    	for(int i=1;i<=n;i++)
    		cin>>b[i];
    	dfs(1);
    	for(int i=1;i<100010;i++)
    	{
    		if(!final[i])
    		{
    			cout<<"ans="<<i<<endl;
    			break;
    		}
    	}
    }
}
