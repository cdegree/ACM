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

char s[50005];
int dp[2605][2605],pre[2605][2605][2];
int cnt[26];
int main()
{
    int n;
    while(~scanf("%s",s))
    {
        n=strlen(s);
        for(int i=0; i<n; ++i)
        {
            ++cnt[ s[i]-'a' ];
        }
        bool found=false;
        for(int i=0; i<26; ++i)
        {
            if(cnt[i]>=100)
            {
                for(int j=0; j<100; ++j)
                {
                    printf("%c",i+'a');
                }
                puts("");
                found=1;
                break;
            }
        }
        if(!found)
        {
            memset(dp,-1,sizeof(dp));
            memset(pre,-1,sizeof(pre));
            for(int i=0; i<n; ++i)dp[i][i]=1;
            for(int i=0; i+1<n; ++i)if(s[i]==s[i+1])
                {
                    dp[i][i+1]=2,pre[i][i+1][0]=i,pre[i][i+1][1]=i+1;
                }
                else dp[i][i+1]=1;pre[i][i+1][0]=i,pre[i][i+1][1]=i;
            for(int l=2; l<n; ++l)
            {
                for(int i=0; i+l<n; ++i)
                {
                    if(dp[i+1][i+l]>dp[i][i+l-1])
                    {
                        dp[i][i+l]=dp[i+1][i+l];
                        pre[i][i+l][0]=pre[i+1][i+l][0];
                        pre[i][i+l][1]=pre[i+1][i+l][1];
                    }
                    else
                    {
                        dp[i][i+l]=dp[i][i+l-1];
                        pre[i][i+l][0]=pre[i][i+l-1][0];
                        pre[i][i+l][1]=pre[i][i+l-1][1];
                    }
                    if(s[i]==s[i+l]&&dp[i][i+l]<=dp[i+1][i+l-1]+1)
                    {
                        dp[i][i+l]=dp[i+1][i+l-1]+1;
                        pre[i][i+l][0]=(pre[i+1][i+l-1][0]==-1)?(i+1):pre[i+1][i+l-1][0];
                        pre[i][i+l][1]=(pre[i+1][i+l-1][1]==-1)?(i+l-1):pre[i+1][i+l-1][1];
                    }
                }
            }
            queue<int> Q;
            stack<int> S;
            int l=0,r=n-1;
            if(s[l]==s[r])
            {
                printf("%d == %d\n",l,r);
                Q.push(l);
                S.push(r);
            }
            l=pre[0][n-1][0],r=pre[0][n-1][1];
            while(~l&&~r&&l!=r)
            {
                //printf("%d  %d\n",l,r);
                Q.push(l);
                S.push(r);
                int nl=pre[l][r][0];
                int nr=pre[l][r][1];
                l=nl,r=nr;
            }
            printf("l=%d,r=%d\n",l,r);
            if(l==r&&~l)
            {
                Q.push(l);
            }
            while(!Q.empty())
            {
                //printf("i=%d\n",Q.front());
                printf("%c",s[Q.front()]);
                Q.pop();
            }
            while(!S.empty())
            {
                printf("%c",s[S.top()]);
                S.pop();
            }
            puts("");
        }
    }
    return 0;
}
