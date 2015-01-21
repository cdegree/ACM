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

int get_pos(int d)
{
    if(d==1||d==4||d==7)return 1;
    if(d==2||d==8)return 2;
    if(d==3||d==6||d==9)return 3;
}

bool cross(int left,int right)
{
    return get_pos(right)<get_pos(left);
}
char s[100005];

int gao(int u)
{
    int l,r;
    int cnt=0;
    int prel,prer;
    if(u==1)
    {
        l=0,r=1;
        if(cross(s[l]-'0',s[r]-'0'))return 1e8;
        int od=1;//right
        int len = strlen(s);
        for(int i=0;i<len-1;++i)
        {

            if(cross(s[l]-'0',s[r]-'0'))
            {
                ++cnt;
                if(od&1)
                {
                    l=r;
                    r=prer;
                }
                else
                {
                    r=l;
                    l=prel;
                }
                --i;
                ++od;
            }
            else
            {
                //printf("i = %d,%d - %d\n",i,s[l]-'0',s[r]-'0');
                if(od&1)
                {
                    prel=l;
                    l=i+2;
                }
                else
                {
                    prer=r;
                    r=i+2;
                }
                ++od;

            }

        }
    }
    else
    {
        int od=0;
        int len = strlen(s);
        l=1,r=0;
        if(cross(s[l]-'0',s[r]-'0'))return 1e8;
        for(int i=0;i<len-1;++i)
        {
            //printf("%d - %d\n",s[l]-'0',s[r]-'0');
            if(cross(s[l]-'0',s[r]-'0'))
            {
                ++cnt;
                if(od&1)
                {
                    l=r;
                    r=prer;
                }
                else
                {
                    r=l;
                    l=prel;
                }
                --i;
                ++od;
            }
            else
            {
                if(od&1)
                {
                    prel=l;
                    l=i+2;
                }
                else
                {
                    prer=r;
                    r=i+2;
                }
                ++od;
            }
        }
    }
    return cnt;
}


int main()
{
    while(1)
    {
        scanf("%s",s);
        if(s[0]=='#')break;
        int res = gao(0);
        //printf("%d\n",res);
        res = min(res, gao(1));
        printf("%d\n",res);
    }
	return 0;
}
