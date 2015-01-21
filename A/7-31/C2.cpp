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
#define FOR( i, a, b ) for(int i = a; i <= b; ++i )
const int fa=111;
int n,k,m;
int aa[fa];
vector<int>a[fa];
struct wgh
{
    int x,y;
};
map<int,int>mp;
int main()
{
    //freopen("out.txt","w",stdout);
    //freopen("in.txt","r",stdin);
    int i,j;
    while(scanf("%d%d%d",&n,&k,&m)!=EOF)
    {
        memset(aa,0,sizeof(aa));
        for(i=1; i<fa; i++)
        {
            a[i].clear();
        }
        mp.clear();
        for(i=0; i<n; i++)
        {
            aa[i+1]=i%k+1;
            a[i%k+1].push_back(i+1);
            printf("%d\n",aa[i+1]);
        }
        for(i=1; i<k; i+=2)
        {
            printf("%d %d\n",a[i][0],a[i+1][0]);
            m--;
            wgh o;
            o.x=a[i][0];
            o.y=a[i+1][0];
            mp[a[i][0]*fa+a[i+1][0]]=1;
        }
        if(k%2==1)
        {
            printf("%d %d\n",a[1][0],a[k][0]);
            wgh o;
            o.x=a[1][0];
            o.y=a[k][0];
            mp[a[1][0]*fa+a[k][0]]=1;
            m--;
        }
        while(m)
        {
            for(i=1;i<=n;i++)
            {
                for(j=i+1;j<=n;j++)
                for(int ii=0;ii<a[i].size();ii++)
                for(int jj=0;jj<a[j].size();jj++)
                {
                    wgh o;
                    o.x=a[i][ii];
                    o.y=a[j][jj];
                    if(mp[o.x*fa+o.y]==false)
                    {
                        printf("%d %d\n",o.x,o.y);
                        m--;
                        if(m==0)return 0;
                    }
                }
            }
        }
    }
    return 0;
}
