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


void dfs(int u)
{
    if(u>70000)return ;
    dfs(u+1);
}
bool used[600006];
int main()
{
    freopen("Ein.txt","w",stdout);
    int T=5;
    int M = 100;
    printf("%d\n",T);
    for(int j=0; j<T; ++j)
    {
        int n = M;
        memset(used,0,sizeof(used));
        printf("%d\n",n);
        for(int i=1; i<=n; ++i)
        {
            int u;
            do
            {
                u=rand();
            }while(u<=0||u>M||used[u]);
            used[u]=1;
            printf("%d ",u);
        }
        puts("");
        puts("01");
    }
    return 0;
}
