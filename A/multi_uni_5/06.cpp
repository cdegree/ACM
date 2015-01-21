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

const int N = 10005;
vector<int> Mv[N];

LL a[N*10],presum[N*10];
int n,m;
void init()
{
    for(int i=0;i<N;++i)Mv[i].clear();
}
int main()
{
    //printf("%d\n",(-9)%4);
    while(~scanf("%d%d",&n,&m))
    {
        init();
        for(int i=1;i<=n;++i)scanf("%I64d",a+i);
        presum[0]=0;
        for(int i=1;i<=n;++i)
        {
            presum[i]=presum[i-1]+a[i]+m*1000000000LL;
            presum[i]%=m;
        }
        for(int i=1;i<=n;++i)Mv[ presum[i] ].push_back(i);
        int mx = 0 ;
        if(Mv[0].size()>0) mx = Mv[0][ Mv[0].size()-1 ];
        for(int i=1;i<m;++i)if(Mv[i].size()>0)mx = max(mx, Mv[i][ Mv[i].size()-1 ] - Mv[i][0]  );
        printf("%d\n",mx);
    }
	return 0;
}
