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

const int N=1000005;
LL C[N];
LL suffix_sum[N],sum[N];
int main()
{
    LL n,A,B;
    while(~scanf("%I64d%I64d%I64d",&n,&A,&B))
    {
        for(int i=1;i<=n;++i)scanf("%I64d",C+i);
        suffix_sum[n+1]=0;
        for(int i=n;i>=1;--i)suffix_sum[i]=suffix_sum[i+1]+C[i];
        for(int i=1;i<=n;++i)sum[i]=sum[i-1]+C[i];
        int cnt=1;
        int i=1;
        int turn=1;
        while(cnt<=n)
        {
            if(turn&1)
            {
                if(suffix_sum[cnt]<=A)
                {
                    turn=0;
                    break;
                }
                else if(A-C[cnt]>=0)
                {
                    int L = cnt-1;
                    int R = cnt;
                    while(R+1<n&&sum[R+1]-sum[L]<C[R+2]&&A-sum[R+1]-sum[L]>=0)
                    {
                        ++R;
                    }
                    A -= sum[R]-sum[L];
                    cnt=R+1;
                    turn=0;
                }
                else
                {
                    break;
                }
            }
            else
            {
                if(suffix_sum[cnt]<=B)
                {
                    turn=1;
                    break;
                }
                else if(B-C[cnt]>=0)
                {
                    int L = cnt-1;
                    int R = cnt;
                    while(R+1<n&&sum[R+1]-sum[L]<C[R+2]&&B-sum[R+1]-sum[L]>=0)
                    {
                        ++R;
                    }
                    B -= sum[R]-sum[L];
                    cnt=R+1;
                    turn=1;
                }
                else
                {
                    break;
                }
            }
        }
        if(turn==0)
        {
            puts("ALICE");
        }
        else
        {
            puts("BOB");
        }
    }
	return 0;
}
