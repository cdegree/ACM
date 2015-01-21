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

LL C[303][5];
LL cnt[55];
int main()
{
    memset(C,0,sizeof(C));
    for(LL i=1; i<=300; ++i)
    {
        C[i][0]=1;
        C[i][1]=i;
        C[i][2]=i*(i-1)/2;
        C[i][3]=i*(i-1)*(i-2)/6;
        C[i][4]=i*(i-1)*(i-2)*(i-3)/24;
    }
    LL n,m;
    while(true)
    {
        scanf("%lld %lld",&n,&m);
        if(n==0&&m==0)break;
        LL cnt3=0,cnt4=0;
        memset(cnt,0,sizeof(cnt));
        for(int i=0; i<n; ++i)
        {
            int a;
            scanf("%d",&a);
            cnt[a]++;
        }
        for(int i=1; i<=m; ++i)
        {
            if(cnt[i]>=3)
            {
                cnt3+=C[cnt[i]][3];
                if(cnt[i]>=4)cnt4+=C[cnt[i]][4];
                cnt4+=C[cnt[i]][3]*LL(n-cnt[i]);
            }
        }
        for(int i=1; i<=m; ++i)
        {
            for(int j=i+1; j<=m; ++j)
            {
                for(int k=j+1; k<=m; ++k)
                {
                    cnt3+=cnt[i]*cnt[j]*cnt[k];
                    cnt4+=C[cnt[i]][1]*C[cnt[j]][1]*C[cnt[k]][2];
                    cnt4+=C[cnt[i]][1]*C[cnt[j]][2]*C[cnt[k]][1];
                    cnt4+=C[cnt[i]][2]*C[cnt[j]][1]*C[cnt[k]][1];
                }
            }
        }
        for(int i=1;i<=m;++i)
        {
            for(int j=i+1;j<=m;++j)
            {
                for(int k=j+1;k<=m;++k)
                {
                    for(int v=k+1;v<=m;++v)
                    {
                        cnt4+=cnt[i]*cnt[j]*cnt[k]*cnt[v];
                    }
                }
            }
        }
        printf("%lld %lld\n",cnt3,cnt4);
    }
    return 0;
}
