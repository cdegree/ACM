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
#pragma comment(linker,"/STACK:102400000,102400000")

int dp[55][55];
int sg(int n,int m)
{
    if(n>m)swap(n,m);
    if(n==1&&m==1)return 0;
    int &ret = dp[n][m];
    if(~ret)return ret;
    set<int> st;
    for(int i=1;i<n;++i)
    {
        st.insert(sg(i,m)^sg(n-i,m));
    }
    for(int i=1;i<m;++i)
    {
        st.insert(sg(n,i)^sg(n,m-i));
    }
    for(int i=0;;++i)
    {
        if(st.find(i)==st.end())
        {
            return ret=i;
        }
    }
}
int main()
{
    int n,m;
    memset(dp,-1,sizeof(dp));
    while(~scanf("%d%d",&n,&m))
    {
        int ret=sg(n,m);
        if(ret>0)
        {
            puts("[:=[first]");
        }
        else
        {
            puts("[second]=:]");
        }
    }
	return 0;
}
