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

char mp[8][8];
void init()
{
    for(int i=0; i<7; ++i)
    {
        for(int j=0; j<7; ++j)
        {
            mp[i][j]='#';
        }
    }
}
int hiest;
bool remov[8][8];
bool remover()
{
    bool rm=0;
    memset(remov,0,sizeof(remov));
    for(int i=0; i<7; ++i)
    {
        int cnt=0;
        for(int j=0; j<7; ++j)
        {
            if(mp[i][j]!='#')++cnt;
        }
        for(int j=0; j<7; ++j)
        {
            if(mp[i][j]!='#'&&cnt==mp[i][j]-'0')
            {
                remov[i][j]=1;
                rm=1;
            }
        }
    }
    for(int j=0; j<7; ++j)
    {
        for(int i=0; i<7; ++i)
        {
            if(mp[i][j]!='#')
            {
                int l=i,r=i;
                while(l-1>=0&&mp[l-1][j]!='#')--l;
                while(r+1<7&&mp[r+1][j]!='#')++r;
                //printf("%d -> %d\n",l,r);
                for(int k=l; k<=r; ++k)
                {
                    if(mp[k][j]-'0'==r-l+1)
                    {
                        remov[k][j]=1;
                        rm=1;
                    }
                }
                i=r;
            }
        }
    }
    for(int i=0; i<7; ++i)for(int j=0; j<7; ++j)if(remov[i][j])mp[i][j]='#';
    return rm;
}
void fall()
{
    for(int i=0; i<7; ++i)
    {
        for(int j=1; j<7; ++j)
        {
            if(mp[i][j]!='#')
            {
                int lp=j;
                while(lp-1>=0&&mp[i][lp-1]=='#')--lp;
                mp[i][lp]=mp[i][j];
                if(lp<j)mp[i][j]='#';
            }
        }
    }
}
bool add(int v,int c)
{
    char ch = v+'0';
    --c;
    //puts("fff");
    bool found=0;
    for(int i=0; i<7; ++i)
    {
        if(mp[c][i]=='#')
        {
            found=1;
            mp[c][i]=ch;
            break;
        }
    }
    return found;
}
bool seven()
{
    bool ok=0;
    for(int i=0; i<7; ++i)
    {
        if(mp[i][6]!='#')
        {
            ok=1;
            break;
        }
    }
    return ok;
}
void pf()
{
    for(int i=6; i>=0; --i)
    {
        for(int j=0; j<7; ++j)
        {
            printf("%c",mp[j][i]);
        }
        puts("");
    }
    puts("");
}
int v[1005],c[1005];
int main()
{
    while(1)
    {
        int n;
        scanf("%d",&n);
        if(n==0)break;
        init();
        bool over=0;
        for(int i=0; i<n; ++i)
        {
            scanf("%d%d",v+i,c+i);
            if(!add(v[i],c[i]))
            {
                over=1;//break;
            }
            int cnt=0;
            while(remover())
            {
                while(remover())remover();
                fall();
            }

            //pf();
        }
        for(int i=0; i<n; ++i)
        {

            //pf();
        }
        if(over)
        {
            puts("Game Over!");
        }
        else
        {
            pf();
        }
        puts("");

    }
    return 0;
}
