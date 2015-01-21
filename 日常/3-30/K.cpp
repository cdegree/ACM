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

char s[200005];
//string s;
struct node
{
    char *sb;
    int len;
    node(){}
    void newnode(char *st,int _len)
    {
        len = _len;
        sb = new char[len];
        for(int i=0;i<len;i++)
        {
            sb[i]=st[i];
        }
    }
}nd[200005];
char tmp[200005];
bool cmp(node a,node b)
{
    return a.len<b.len;
}
int n;
int get_st1(int len)
{
    if(n%2==0)
    {
        return n/2 - len/2;
    }
    else
    {
        return n/2 - len/2 +1 ;
    }
}
int get_st2(int len)
{
    if(n%2==0)
    {
        return n/2 - len/2 - 1;
    }
    else
    {
        return n/2 - len/2 + 2;
    }
}
bool scmp(char *s1,char *s2,int len)
{
    int i=0;

    while(i<len)
    {
        if( s1[i] != s2[i] )return false;
        ++i;
    }
    return true;
}
int main()
{

    int T;
    scanf("%d",&T);
    for(int t=1;t<=T;t++)
    {
        scanf("%s",s);
        n = strlen(s);
        int q;
        scanf("%d",&q);
        int cnt=0;
        for(int i=0;i<q;i++)
        {
            scanf("%s",tmp);
            int len = strlen(tmp);
            if( (n%2==0&&len%2==1)||(n%2==1&&len%2==0) )nd[cnt++].newnode(tmp,len);
        }
        printf("Case #%d: ",t);
        {
            bool found=false;
            for(int i=0;i<cnt&&!found;i++)
            {
                int st1 = get_st1(nd[i].len);
                if(scmp(s+st1,nd[i].sb,nd[i].len))
                {
                    found=true;
                }
                int st2 = get_st2(nd[i].len);
                if(scmp(s+st2,nd[i].sb,nd[i].len))
                {
                    found=true;
                }
            }
            if(found)
            {
                puts("zplinti1");
            }
            else
            {
                puts("bearchild");
            }

        }
    }
	return 0;
}
