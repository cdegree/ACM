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
bool vis[1000];

int main()
{
    int x,y,n=100;
    while(cin>>x>>y)
    {
        memset(vis,false,sizeof(vis));
        vis[0]=true;
        for(int i=1;i<=n;i++)
        {
            if(i-x>=0&&vis[i-x])
            {
                vis[i]=true;
            }
            if(i-y>=0&&vis[i-y])
            {
                vis[i]=true;
            }
        }
        int cnt=0;
        for(int i=1;i<=n;i++)
        {
            if(vis[i])cnt++;
            else printf("%4d",i);
        }
        printf("\ncnt = %d\n",cnt);
    }
	return 0;
}
