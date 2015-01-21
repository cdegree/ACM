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
const LL mod = 1000000007LL;
int a[17];
bool vis[17];
bool sum[33];
int cnt;
    LL n;
void gao(int u)
{
    if(u==n+1)
    {
        cnt++;
    }
    else
    {
        for(int i=1;i<=n;i++)
        {
            if(!vis[i]&&!sum[i+u])
            {
                vis[i]=true;
                sum[i+u]=true;
                gao(u+1);
                sum[i+u]=false;
                vis[i]=false;
            }
        }
    }
}
int main()
{
    cin>>n;
    LL res = n;
    for(int i=1;i<=n;i++){res*=n;res%=mod;  }
    cnt=0;
    gao(1);
    res *= cnt;
    res %= cnt;
    printf("%d\n",cnt);
	return 0;
}
