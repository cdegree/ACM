#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#define X first
#define Y second
#define sqr(x) ((x)*(x))
using namespace std;
const double eps = 1e-8 ;

typedef long long LL ;
const int N = 100005;
int a[N],L[N],R[N];

int main(int argc, char const *argv[])
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
	    int n;
	    scanf("%d",&n);
	    for(int i=1;i<=n;++i)
	    {
	        scanf("%d",a+i);
	    }
	    a[n+1]=2e9+9;
	    L[0] = -2e9-1;
	    R[0] = 2e9+1;
	    for(int i=1;i<=n;++i)
	    {
	        int low = a[i]/2 + ((a[i]&1)?1:0);
	        int up = a[i+1]/2;
	        L[i] = max(low,a[i]-R[i-1]);
	        R[i] = min(up,a[i]-L[i-1]);
	    }
	    int res=2e9;
	    for(int i=1;i<=n;++i)
	    {
	        //printf("%d -> %d\n",L[i],R[i]);
	        res = min(res,R[i]-L[i]+1);
	    }
	    if(res>=0)
	    {
	        printf("%d\n",res);
	    }
	    else
	    {
	        puts("0");
	    }
	}
	return 0;
}
