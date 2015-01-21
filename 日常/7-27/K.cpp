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
const int  N =1005;
char s1[N],s2[N];

bool equal(char a,char b)
{
    if(a=='?')return true;
    else return a==b;
}
bool OK[N];
bool can[N];
int dp[N];
int main()
{
    while(~scanf("%s%s",s1,s2))
    {
        int n=strlen(s1);
        int m=strlen(s2);
        int cnt=0;
        memset(can,false,sizeof(can));
        memset(OK,false,sizeof(OK));
        memset(dp,0,sizeof(dp));
        for(int i=m-2; i>=0; --i)
        {
            if(s2[i]==s2[m-1])
            {
                int j=i,k=m-1;
                while(j>=0&&s2[j]==s2[k])
                {
                    --j,--k;
                }
                if(j<0)
                {
                    OK[i]=true;
                    //printf("%d OK\n",i);
                }
                else
                {
                    OK[i]=false;
                }
            }
        }
        for(int i=0; i+m<=n; ++i)
        {
            bool ok=true;
            for(int j=0; j<m; ++j)
            {
                if(!equal(s1[i+j],s2[j]))
                {
                    //printf("%d %d\n",i+j,j);
                    ok=false;
                    break;
                }
            }
            if(ok)
            {
                can[i+m-1]=true;
                // printf("%d can\n",i+m-1);
            }
        }
        bool first=true;
        for(int i=0; i<n; ++i)
        {
            if(can[i])
            {
                for(int j=0; j<=i; ++j)
                {
                    if(i-j>=m&&can[j])
                    {
                        dp[i]=max(dp[i],dp[j]+1);
                    }
                    else if((OK[j-(i-m)-1]&&can[j]))
                    {
                        dp[i]=max(dp[i],dp[j]+1);
                    }
                }
            }
        }
        cnt=0;
        for(int i=0; i<n; ++i)
        {
            cnt=max(cnt,dp[i]);
        }
        for(int i=0;i<n;++i)
        {
            if(can[i]){++cnt;break;}
        }
        printf("%d\n",cnt);
    }
    return 0;
}
