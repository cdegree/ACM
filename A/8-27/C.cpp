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

const int N = 1000005;
int cnt[N];
int a[N];
LL res[N];
int main()
{
    int n;
    freopen("Cin.txt","r",stdin);
    //freopen("Cout.txt","w",stdout);
    while(1)
    {
        scanf("%d",&n);
        if(n==0)break;
        memset(res,-1,sizeof(res));
        for(int i=0;i<n;++i)scanf("%d",a+i);
        int q;
        scanf("%d",&q);
        int L;
        while(q--)
        {
            scanf("%d",&L);
            if(~res[L])
            {
                printf("%I64d\n",res[L]);
                continue;
            }
            if(L==1)
            {
                printf("%d\n",n);
            }
            else
            {
                LL sum=0,ccnt=0;
                for(int i=0;i<L;++i)if(cnt[ a[i] ]++==0)ccnt++;
                sum+=ccnt;
                for(int i=0;i+L<n;++i)
                {
                    if(--cnt[ a[i] ]==0)
                    {
                        --ccnt;
                    }
                    if(cnt[ a[i+L] ]++==0)
                    {
                        ++ccnt;
                    }
                    sum+=ccnt;
                }
                for(int i=n-L;i<n;++i)
                {
                    --cnt[ a[i] ];
                }
                res[L]=sum;
                printf("%I64d\n",sum);
            }
        }
    }

	return 0;
}
