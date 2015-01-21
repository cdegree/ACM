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

LL dp[55][55],ddp[55];
int gao(int n,int m)
{
    if(n==1)return 1;
    else if(n==2)return 1;
    else
    {

    }
}
void init()
{
    dp[0][1]=1;
    for(int i=1;i<=50;++i)
    {
        for(int j=1;j<=i;++j)
        {
            dp[i][j]=dp[i-j][j];
            if(j-1>=0)dp[i][j]+= dp[i][j-1];
        }
    }
}
int main()
{
    init();
	return 0;
}
