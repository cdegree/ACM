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
        memset(cnt,0,sizeof(cnt));
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
                    dp[i][i+1]=2;
                    //pre[i][i+1][0]=i,pre[i][i+1][1]=i+1;
                }
                else dp[i][i+1]=1;
            //pre[i][i+1][0]=i,pre[i][i+1][1]=i+1;
            for(int l=2; l<n; ++l)
            {
                for(int i=0; i+l<n; ++i)
                {
                    //printf("%d->%d\n",i,i+l);
                    if(s[i]==s[i+l])
                    {
                        //printf("from %d,%d\n",i+1,i+l-1);
                        //printf("to %d,%d\n",i,i+l);
                        dp[i][i+l]=dp[i+1][i+l-1]+2;
                        pre[i][i+l][0]=i+1;
                        pre[i][i+l][1]=i+l-1;
                        //printf("dp=%d\n",dp[i][i+l]);
                    }
                    else
                    {
                        if(dp[i+1][i+l]>dp[i][i+l-1])
                        {
                            dp[i][i+l]=dp[i+1][i+l];
                            pre[i][i+l][0]=i+1;
                            pre[i][i+l][1]=i+l;
                        }
                        else
                        {
                            dp[i][i+l]=dp[i][i+l-1];
                            pre[i][i+l][0]=i;
                            pre[i][i+l][1]=i+l-1;
                        }
                    }
                }
            }
            queue<int> Q;
            stack<int> S;
            //printf("%d",dp[1][3]);
            int l=0,r=n-1;
            bool f=false;
            for(int i=0; i<n; ++i)
            {
                for(int j=i+1; j<n; ++j)
                {
                    if(dp[i][j]>=100)
                    {
                        l=i;
                        r=j;
                        f=true;
                        break;
                        //printf("ans = %d %d\n",i,j);
                    }
                }
                if(f)break;
            }
            int cnt=0;
            //printf("dp = %d\n",dp[l][r]);
            int lastl=l-1,lastr=r+1;
            if(s[l]==s[r]&&lastl<l&&r<lastr)
            {
                //printf("%d == %d  dp=%d\n",l,r,dp[l][r]);
                if(dp[l][r]>1)
                {
                    Q.push(l);
                    S.push(r);
                    lastl=l;
                    lastr=r;
                    cnt+=2;
                }
                else
                {
                    Q.push(l);
                    lastl=l;
                    ++cnt;
                }
            }
            //int predp=dp[l][r];
            int nl,nr;
            nl=pre[l][r][0],nr=pre[l][r][1];
            l=nl,r=nr;
            while(~l&&~r&&cnt<100)
            {
                //printf("%d == %d   dp = %d\n",l,r,dp[l][r]);
                if(s[l]==s[r]&&l>lastl&&r<lastr)
                {
                    if(dp[l][r]>1)
                    {
                        Q.push(l);
                        S.push(r);
                        lastl=l;
                        lastr=r;
                        cnt+=2;
                    }
                    else
                    {
                        Q.push(l);
                        lastl=l;
                    }
                }
                nl=pre[l][r][0];
                nr=pre[l][r][1];
                //if(nl==l&&nr==r)break;
                l=nl,r=nr;
            }
            //printf("l=%d,r=%d\n",l,r);
            //printf("lastl=%d,lastr=%d\n",lastl,lastr);
            if(lastl+1<lastr&&cnt<100)
            {
                Q.push(lastl+1);
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
