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

int get_sg(int k)
{
    //printf("k=%d\n",k);
    if(k==1)return 0;
    if(k==2)return 1;
    set<int> s;
    for(int i=0;i<k;++i)
    {
        s.insert(get_sg(k-i-1)^(i));
    }
    for(int i=0;;++i)
    {
        if(s.find(i)==s.end())return i;
    }
}
int b[1000006];
bool cmp(int p,int q)
{
    return p>q;
}
int main()
{
    int T;
    for(int i=0;i<20;++i)
    {
        printf("%d:%d\n",i,get_sg(i));
    }
    scanf("%d",&T);
    int cnt[4];

    while(T--)
    {
        int n;
        memset(cnt,0,sizeof(cnt));
        scanf("%d",&n);
        int sg=0;
        for(int i=0; i<n; ++i)
        {
            int a;
            scanf("%d",&a);
        }
        if(sg>0)
        {
            puts("Carol");
        }
        else
        {
            puts("Dave");
        }
    }
    return 0;
}
