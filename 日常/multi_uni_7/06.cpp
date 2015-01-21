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

const int N = 105;
int list[N][N];
bool used[N][N];
int cnt[N][N];
int n,m;
int add(int cur,int k)
{
    ++cur;
    if(cur>k)cur=1;
    return cur;
}
int main()
{

    while(~scanf("%d%d",&n,&m))
    {
        if(0)
        {
            memset(used,false,sizeof(used));
            int cur=1;
            int pos=1;
            for(int i=1; i<=n; ++i)
            {
                while(used[pos][cur])pos=add(pos,m);
                for(int j=1; j<=m; ++j)
                {
                    list[pos][i]=cur;
                    used[pos][cur]=1;
                    //printf("%d use %d\n",j,cur);
                    cur=add(cur,n);
                    pos=add(pos,m);
                }
            }
            for(int i=1; i<=m; ++i)
            {
                for(int j=1; j<=n; ++j)
                {
                    printf("%d%c",list[i][j],j==n?'\n':' ');
                }
            }
        }
        else
        {
            memset(used,false,sizeof(used));
            memset(cnt,0,sizeof(cnt));
            int cur=1;
            int pos=1;
            for(int i=1; i<=m; ++i)
            {
                list[i][1]=cur;
                for(int j=1;j<=n;++j)cnt[j][cur]++;
                used[i][cur]=1;
                cur=add(cur,n);
            }
            for(int i=2; i<=n; ++i) //lie
            {
                for(int j=1; j<=m; ++j) //hang
                {
                    int pp=-1;
                    int mn=1e7;
                    for(int k=1; k<=n; ++k) // shu
                    {
                        if(!used[j][k]&&cnt[ list[j][i-1] ][k]<mn)
                        {
                            mn=cnt[ list[j][i-1] ][k];
                            pp=k;
                        }
                    }
                    list[j][i]=pp;
                    used[ j ][pp]=1;
                    ++cnt[ list[j][i-1] ][pp];
                }
            }
            for(int i=1; i<=m; ++i)
            {
                for(int j=1; j<=n; ++j)
                {
                    printf("%d%c",list[i][j],j==n?'\n':' ');
                }
            }
        }
    }
    return 0;
}
