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
#pragma comment(linker,"/STACK:102400000,102400000")
using namespace std;
const double PI = acos(-1.0);
map<int, int>::iterator it;
typedef long long LL ;
template<typename T> void checkmin(T &x, T y) {x = min(x, y);}
template<typename T> void checkmax(T &x, T y) {x = max(x, y);}

const int N= 505;
int dp[N];
int Seg[N][N];
int main()
{
    int n;
    while(~scanf("%d",&n))
    {
        memset(Seg,0,sizeof(Seg));
        memset(dp,0,sizeof(dp));
        for(int i=0;i<n;++i)
        {
            int a,b;
            scanf("%d%d",&a,&b);
            if(a+1<=n-b&&Seg[a+1][n-b]<n-b-a)Seg[a+1][n-b]++;

        }
        for(int i=1;i<=n;++i)
        {
            for(int j=0;j<i;++j)
            {
                dp[i]=max(dp[i],dp[j]+Seg[j+1][i]);
            }
        }
        printf("%d\n",dp[n]);
    }
	return 0;
}
