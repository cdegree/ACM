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

const int N = 150005;

int getmin(char *pat)  //最小表示法
{
   int len = strlen(pat);
   int i=0,j=1,k=0;
   while(i<len && j<len && k<len)
   {
       int t = pat[(i+k)%len] - pat[(j+k)%len];
       if(!t) k++;
       else
       {
           if(t>0) i = i+k+1;
           else j = j+k+1;
           if(i == j) j++;
           k = 0 ;
       }
   }
   return i<j?i:j;
}

int getmax(char *pat)  //最大表示法
{
   int len = strlen(pat);
   int i=0,j=1,k=0;
   while(i<len && j<len && k<len)
   {
       int t = pat[(i+k)%len] - pat[(j+k)%len];
       if(!t) k++;
       else
       {
           if(t>0) j = j+k+1;
           else i = i+k+1;
           if(i == j) j++;
           k = 0 ;
       }
   }
   return i<j?i:j;
}
char s[N];
bool vis[N];
char mx[N];
char r[N],tmp[N];
int main()
{
    int n,k;
    //freopen("Bin.txt","r",stdin);
    while(~scanf("%d%d",&n,&k))
    {
        memset(vis,false,sizeof(vis));
        memset(mx,'\0',sizeof(mx));
        scanf("%s",s);
        bool all=1;
        for(int i=0; i<n-1; ++i)
        {
            if(s[i]!=s[i+1])all=0;
        }
        if(all)
        {
            for(int i=0; i<n; ++i)printf("%c",s[i]);
            puts("");
            continue;
        }
        int len=0;
        int mxlen=0;
        for(int i=0; i<n; ++i)
        {
            if(!vis[i])
            {
                len=0;
                vis[i]=1;
                r[len++]=s[i];
                while( !vis[(i+k)%n] )
                {
                    vis[(i+k)%n]=1;
                    r[len++]=s[(i+k)%n];
                    i=(i+k)%n;
                }
                r[len]='\0';
                int pos = getmax(r);
                for(int i=0;i<len;++i)
                {
                    tmp[i]=r[(i+pos)%len];
                }
                tmp[len]='\0';
                if(strcmp(mx,tmp)<0)strcpy(mx,tmp);
            }
        }
        //puts("ok2");
        int p=0;
        mxlen=strlen(mx);
        while(p<n)
        {
            //printf("%d,%d\n",p,mxlen);
            printf("%c",mx[p%mxlen]);
            ++p;
        }
        puts("");
    }
    return 0;
}
