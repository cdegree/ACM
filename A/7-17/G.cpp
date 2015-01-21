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

char li[55][55];
int on[55];
struct light
{
    int on,offset;
}L[55];
bool cmp(light a,light b)
{
    return a.offset>b.offset;
}
int main()
{
    int T;
    scanf("%d",&T);
    int n,m,k;
    while(T--)
    {
        scanf("%d%d%d",&n,&m,&k);
        for(int i=0;i<n;++i)
        {
            scanf("%s",li[i]);
        }
        for(int i=0;i<n;++i)
        {
            L[i].on=0;
            L[i].offset=0;
            for(int j=0;j<m;++j)
            {
                L[i].on+=(li[i][j]=='*');
            }
            L[i].offset = (m-L[i].on)-L[i].on;
        }
        while(k>0)
        {
            --k;
            sort(L,L+n,cmp);
            L[0].on += L[0].offset;
            L[0].offset = -L[0].offset;
        }
        int sum=0;
        for(int i=0;i<n;++i)
        {
            sum+=L[i].on;
        }
        printf("%d\n",sum);
    }
	return 0;
}
