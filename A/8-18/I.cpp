#include <cstdlib>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <fstream>
#include <numeric>
#include <iomanip>
#include <bitset>
#include <list>
#include <stdexcept>
#include <functional>
#include <utility>
#include <ctime>
using namespace std;
#define ll long long
#pragma comment(linker,"/STACK:102400000,102400000")
#define FOR( i, a, b ) for(int i = a; i <= b; ++i )
const int maa=1e9;
const int fa=51;
const int maxn=10101;
int n,m,l;
int h[fa];
bool dp[fa][maxn];
bool bo[fa];
int ans;
int ma[fa];
struct wgh
{
    int x,y;
}aa;
wgh path[fa][maxn];
int main()
{
    //freopen("out.txt","w",stdout);
    //freopen("in.txt","r",stdin);
    int i,j,k;
    while(~scanf("%d",&n))
    {
        memset(dp,0,sizeof(dp));
        memset(ma,0,sizeof(ma));
        memset(bo,0,sizeof(bo));
        l=0;
        for(i=1;i<=n;i++)
        {
            scanf("%d",&h[i]);
            l+=2;
            l+=abs(h[i]-h[i-1]);
        }
        l+=h[n];
        ans=maa;
        int o=0;
        dp[0][0]=true;
        ma[0]=0;
        for(i=1;i<=n;i++)
        {
            for(j=0;j<i;j++)
            for(int ii=0;ii<=ma[j];ii++)
            {
                if(dp[j][ii]==true)
                {
                    if(h[j]>=h[i])
                    {
                        dp[i][ii+2]=true;
                        ma[i]=max(ma[i],ii+2);
                        int u=ii+2;
                        path[i][u].x=j;
                        path[i][u].y=ii;
                        //cout<<u<<endl;
                        if(u>=l/2)
                        {
                            if(ans>u)
                            {
                                ans=u;
                                aa.x=i;
                                aa.y=u;
                            }
                        }
                    }
                    else
                    {
                        int o=abs(h[i]-h[j]);
                        dp[i][ii+2+o*2]=true;
                        ma[i]=max(ma[i],ii+2+o*2);
                        int u=ii+2+o*2;
                        path[i][u].x=j;
                        path[i][u].y=ii;
                        //cout<<u<<endl;
                        if(u>=l/2)
                        {
                            if(ans>u)
                            {
                                ans=u;
                                aa.x=i;
                                aa.y=u;
                            }
                        }
                    }
                }
            }
        }
        printf("%d\n",l-ans);
        wgh t=aa;
        while(t.x!=0)
        {
            bo[t.x]=true;
            t=path[t.x][t.y];
        }
        int oo=0;
        for(i=1;i<=n;i++)
        {
            if(bo[i]==false)
            {
                oo++;
            }
        }
        printf("%d\n",oo);
        k=0;
        for(i=1;i<=n;i++)
        {
            if(bo[i]==false)
            {
                if(k!=0)
                printf(" %d",i);
                else
                {
                    printf("%d",i);
                }
                k++;
            }
        }
        printf("\n");
    }
    return 0;
}
