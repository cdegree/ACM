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

int dp[120];
int sg(int n)
{
    int &ret =dp[n];
    if(~ret)return ret;
    ret=0;
    if(n==0)return ret=0;
    if(n==1||n==2)return ret=1;
    int i=0;
    set<int> S;
    S.insert(sg(n-2));
    S.insert(sg(n-3));
    for(int i=1;i<=n-3;++i)
    {
        S.insert(sg(i)^sg(n-i-3));
    }
    for(int i=0;;++i)
    {
        if(S.find(i)==S.end())return ret=i;
    }
}
int main()
{
    memset(dp,-1,sizeof(dp));
    int n;
    while(~scanf("%d",&n))
    {
        int res;
        if(n<68)res = sg(n);
        else res = sg((n-68)%34+68);
        printf("%s\n",res>0?"White":"Black");
    }
	return 0;
}
