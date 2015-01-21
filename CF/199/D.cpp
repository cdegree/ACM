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


const LL mod = 1e9+7;

const int N = 10005;
LL dp[8][N];
char s[3][N];

int tp[N];



LL get_dp(int n)
{
    memset(dp,0,sizeof(dp));
    int mask = 1<<3;
    dp[0][0]=1;
    for(int i=1;i<=n;++i)
    {
        if(tp[i]==0)
        {
            dp[]
        }
    }
}
void init()
{
    for(int i=0;i<n;++i)
    {
        tp[i+1]=0;
        for(int j=0;j<3;++j)
        {
            if(s[j][i]=='.')
            {

            }
            else
            {
                tp[i+1]|=1<<j;
            }
        }
    }
}
int main()
{
    int n;
    while(~scanf("%d",&n))
    {
        for(int i=0;i<n;++i)scanf("%s",s[i]);

    }
	return 0;
}
