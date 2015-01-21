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

char s[102][102];
int res[102][2];
int main()
{
    int n;
    while(cin>>n)
    {
        for(int i=0; i<n; ++i)
        {
            scanf("%s",s[i]);
        }
        int len=0;
        bool OK=true;
        for(int i=0; i<n; ++i)
        {
            bool have=false;
            for(int j=0; j<n; ++j)
            {
                if(s[i][j]=='.')
                {
                    res[len][0]=i;
                    res[len++][1]=j;
                    have=true;
                    break;
                }
            }
            if(!have)
            {
                OK=false;
                break;
            }
        }
        if(OK)
        {
            for(int i=0; i<len; ++i)
            {
                printf("%d %d\n",res[i][0]+1,res[i][1]+1);
            }
        }
        else
        {
            OK=true;
            len=0;
            for(int i=0; i<n; ++i)
            {
                bool have=false;
                for(int j=0; j<n; ++j)
                {
                    if(s[j][i]=='.')
                    {
                        res[len][0]=j;
                        res[len++][1]=i;
                        have=true;
                        break;
                    }
                }
                if(!have)
                {
                    OK=false;
                    break;
                }
            }
            if(OK)
            {
                for(int i=0; i<len; ++i)
                {
                    printf("%d %d\n",res[i][0]+1,res[i][1]+1);
                }
            }
            else
            {
                puts("-1");
            }
        }
    }
    return 0;
}
