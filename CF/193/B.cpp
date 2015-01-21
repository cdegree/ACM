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

const int N  =200005;
LL sum[N];
bool vis[N];
LL a[N];
int main()
{
    int n,k;
    while(cin>>n>>k)
    {
        memset(vis,false,sizeof(vis));
        sum[0]=0;
        for(int i=1;i<=n;++i)
        {
            cin>>a[i];
            sum[i]=sum[i-1]+a[i];
        }
        LL best = 0;
        int a=-1,b=-1;
        for(int i=1;i+k-1<=n;++i)
        {
            if(best<sum[i+k-1]-sum[i-1])
            {
                best = sum[i+k-1]-sum[i-1];
                a=i;
            }
        }
        for(int i=a;i<=a+k-1;i++)
        {
            vis[i]=true;
        }
        best=0;
        for(int i=1;i+k-1<=n;++i)
        {
            if(!vis[i]&&!vis[i+k-1]&&best<sum[i+k-1]-sum[i-1])
            {
                best = sum[i+k-1]-sum[i-1];
                b=i;
            }
        }
        if(a>b)swap(a,b);
        printf("%d %d\n",a,b);
    }
	return 0;
}
