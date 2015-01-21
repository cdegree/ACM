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

char s[1005][1005];
int len=0;

void pf_regula(int l,int r,int st);
void pf_enum(int l,int r,int st)
{
    puts("<ol>");
    for(int i=l+1; i<=r+1; ++i)
    {
        if(i==r+1)
        {
            puts("<li>");
            printf("%s\n",&s[i-1][st]);
            puts("</li>");
        }
        else if(s[i][st]==s[i-1][st])
        {
            if(s[i][st]=='*')
            {
                int L = i-1;
                int R = i;
                while(R+1<=r&&s[L][st]==s[R+1][st])++R;
                puts("<li>");
                pf_regula(L,R,st+1);
                i=R+1;
                puts("</li>");
            }
            else if(s[i][st]=='#')
            {
                int L = i-1;
                int R = i;
                while(R+1<=r&&s[L][st]==s[R+1][st])++R;
                puts("<li>");
                pf_enum(L,R,st+1);
                i=R+1;
                puts("</li>");
            }
            else
            {
                puts("<li>");
                printf("%s\n",&s[i-1][st]);
                puts("</li>");
            }
        }
        else
        {
            puts("<li>");
            printf("%s\n",&s[i-1][st]);
            puts("</li>");
        }
    }
    puts("</ol>");
}
void pf_regula(int l,int r,int st)
{
    puts("<ul>");
    for(int i=l+1; i<=r+1; ++i)
    {
        if(i==r+1)
        {
            puts("<li>");
            printf("%s\n",&s[i-1][st]);
            puts("</li>");
        }
        else if(s[i][st]==s[i-1][st])
        {
            if(s[i][st]=='*')
            {
                int L = i-1;
                int R = i;
                while(R+1<=r&&s[L][st]==s[R+1][st])++R;
                puts("<li>");
                pf_regula(L,R,st+1);
                i=R+1;
                puts("</li>");
            }
            else if(s[i][st]=='#')
            {
                int L = i-1;
                int R = i;
                while(R+1<=r&&s[L][st]==s[R+1][st])++R;
                puts("<li>");
                pf_enum(L,R,st+1);
                i=R+1;
                puts("</li>");
            }
            else
            {
                puts("<li>");
                printf("%s\n",&s[i-1][st]);
                puts("</li>");
            }
        }
        else
        {
            puts("<li>");
            printf("%s\n",&s[i-1][st]);
            puts("</li>");
        }
    }
    puts("</ul>");

}

int main()
{
    freopen("Iin.txt","r",stdin);
    while(~scanf("%s",s[len]))++len;
    for(int i=1; i<=len; ++i)
    {
        if(i==len)
        {
            printf("%s\n",s[i-1]);
        }
        else if(s[i][0]==s[i-1][0])
        {
            int l = i-1;
            int r = i;
            while(r+1<len&&s[r+1][0]==s[l][0])++r;
            if(s[l][0]=='*')
            {
                pf_regula(l,r,1);
                i=r+1;
            }
            else if(s[l][0]=='#')
            {
                pf_enum(l,r,1);
                i=r+1;
            }
            else
            {
                printf("%s\n",s[i-1]);
                //if(i==len-1)printf("%s\n",s[i]);
            }
        }
        else
        {
            printf("%s\n",s[i-1]);
            //if(i==len-1)printf("%s\n",s[i]);
        }
    }
    return 0;
}
