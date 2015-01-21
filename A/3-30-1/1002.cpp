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

struct attack
{
    int a[3];
}A[105];
int res;
int n,m,k;
int belong[17];
bool NO(vector<int> sc)
{
    for(int i=0;i<n;i++)
    {
        if(sc[i]>5)return true;
    }
    return false;
}
vector<int> get_sc(vector<int> scary,int s1,int p1,int p2)
{
    vector<int> ret = scary ;
    int b1 = belong[s1];
    int b2 = belong[p1];
    int b3 = belong[p2];
    for(int i=0;i<n;i++)
    {
        if(i==s1)
        {
            ret[i] = max(scary[i]-2,1);
        }
        else if(i==p1)
        {
            ret[i] = scary[i]+2;
        }
        else if(i==p2)
        {
            ret[i] = scary[i]+2;
        }
        else if(belong[i]==b2)
        {
            ret[i] = scary[i]+1;
        }
        else if(belong[i]==b3)
        {
            ret[i] = scary[i]+1;
        }
    }
    return ret;
}
void gao2(vector<int> &add)
{
    for(int i=0;i<n;i++)
    {
        add[i] += 2;
    }
}
void pf(vector<int> g)
{
    puts("");
    for(int i=0;i<n;i++)
    {
        printf("%4d",g[i]);
    }
    puts("");
}
void gao(vector<int> scary,int cur)
{
    //printf("cur =%d\n",cur);
    //pf(scary);
    if(NO(scary))
    {
        res = max(res,cur-1);
        return ;
    }
    vector<int> n1,n2,n3 ;
    //printf("1:\n");
    n1 = get_sc(scary,A[cur].a[0],A[cur].a[1],A[cur].a[2]);
    //gao2(newstate);
    //pf(n1);
    gao(n1,cur+1);

    n2 = get_sc(scary,A[cur].a[1],A[cur].a[0],A[cur].a[2]);
    //gao2(newstate);
    //printf("2:\n");
    gao(n2,cur+1);
    n3 = get_sc(scary,A[cur].a[2],A[cur].a[0],A[cur].a[1]);
    //gao2(newstate);
    //printf("3:\n");
    gao(n3,cur+1);
}
int main()
{
    int T;
    scanf("%d",&T);
    for(int t=1;t<=T;t++)
    {
        int scary[17];
        scanf("%d%d%d",&n,&m,&k);
        for(int i=0;i<n;i++)scanf("%d",belong+i);
        for(int i=0;i<n;i++)scanf("%d",scary+i);
        for(int i=0;i<k;i++)
        {
            for(int j=0;j<3;j++)scanf("%d",&A[i].a[j]);
        }
        vector<int> sc;
        res=1;
        for(int i=0;i<n;i++)
        {
            sc.push_back(scary[i]);
        }
        gao(sc,0);
        printf("Case #%d: %d\n",t,res);
    }
	return 0;
}
