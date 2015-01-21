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

LL mod = 1000000007LL;
struct node
{
    int left_len,right_len;
    LL cnt;
    char s1[202],s2[202];
    void init()
    {
        s2[0]=s1[0]='\0';
        left_len=right_len=0;
    }
} nd[205];

char t[205],tp[205];
int len;
bool equal(char *s,int from,int to)
{
    int p=0;
    for(int i=from; i<to; ++i)
    {
        if(s[i]!=t[p])
        {
            return false;
        }
        ++p;
    }
    return true;
}
void pre_make(int id,char *s)
{
    int ls=strlen(s);
    int &L_len = nd[id].left_len;
    int &R_len = nd[id].right_len;
    R_len = L_len = min(ls,len-1);
    for(int i=0; i<L_len; ++i)
    {
        nd[id].s1[i]=s[i];
    }
    nd[id].s1[L_len]='\0';
    int q=0;
    for(int i=ls-R_len; i<ls; ++i)
    {
        nd[id].s2[q++]=s[i];
    }
    nd[id].s2[L_len]='\0';
    for(int i=0; i+len<=ls; ++i)
    {
        if(equal(s,i,i+len))
        {
            ++nd[id].cnt;
        }
    }
    nd[id].cnt%=mod;
}
char tmp[208];
void cat(int id,int id1,int id2)
{
    nd[id].cnt = nd[id1].cnt + nd[id2].cnt;
    nd[id].cnt %= mod;
    int &L_len = nd[id].left_len;
    int &R_len = nd[id].right_len;
    strcpy(tmp,nd[id1].s2);
    strcat(tmp,nd[id2].s1);
    //printf("tmp = %s\n",tmp);
    int ltmp=strlen(tmp);
    //printf("ltmp = %d,len = %d\n",ltmp,len);
    for(int i=0; i+len<=ltmp; ++i)
    {
        if(equal(tmp,i,i+len))
        {
            ++nd[id].cnt;
            //puts("ok");
        }
    }
    //printf("cnt = %d\n",nd[id].cnt);
    nd[id].cnt%=mod;

    if(strlen(nd[id1].s2)<len-1)
    {
        L_len=min(len-1,ltmp);
        //puts("here");
        for(int i=0; i<L_len; ++i)
        {
            nd[id].s1[i]=tmp[i];
        }
        nd[id].s1[L_len]='\0';
    }
    else
    {
        strcpy(nd[id].s1,nd[id1].s1);
    }
    if(strlen(nd[id2].s1)<len-1)
    {
        //puts("ok");
        R_len=min(len-1,ltmp);
        //printf("R_len=%d\n",R_len);
        int q=0;
        for(int i=ltmp-R_len; i<ltmp; ++i)
        {
            nd[id].s2[q++]=tmp[i];
        }
        nd[id].s2[R_len]='\0';
    }
    else
    {
        strcpy(nd[id].s2,nd[id2].s2);
    }
    //printf("nd[%d].s1=%s, .s2=%s\n",id,nd[id].s1,nd[id].s2);

}
int main()
{
    int n;
    while(~scanf("%s",t))
    {
        memset(nd,0,sizeof(nd));
        len = strlen(t);
        scanf("%s",tp);
        pre_make(1,tp);
        scanf("%s",tp);
        pre_make(2,tp);

        int m;
        scanf("%d",&m);
        for(int i=3; i<=m+2; ++i)
        {
            int u,v;
            scanf("%d %d",&u,&v);
            cat(i,u,v);
        }
        for(int i=1; i<=m+2; ++i)
        {
            //printf("%d:  %s    %s   cnt=%lld\n",i,nd[i].s1,nd[i].s2,nd[i].cnt);
        }
        printf("%I64d\n",nd[m+2].cnt%mod);
    }
    return 0;
}
