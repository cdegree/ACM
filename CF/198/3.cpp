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

const LL mod = 1000000007LL;
const int N = 2002;
LL C[N][N];
LL f[N];
void init()
{
    for(int i=0;i<N;++i)
    {
        C[i][0]=C[i][i]=1;
    }
    for(int i=1;i<N;++i)
    {
        for(int j=1;j<N;++j)
        {
            C[i][j]=C[i-1][j-1]+C[i-1][j];
            C[i][j]%=mod;
        }
    }
    f[0]=1;
    for(int i=1;i<N;++i)
    {
        f[i]=f[i-1]*i;
        f[i]%=mod;
    }
}
int a[N];
bool broke[N];
vector<int> b;
LL cnt[N];
bool onboard[N];
int main()
{
    int n;
    init();
    while(cin>>n)
    {
        memset(broke,0,sizeof(broke));
        memset(onboard,0,sizeof(onboard));
        for(int i=1;i<=n;++i)cin>>a[i];
        b.clear();
        for(int i=1;i<=n;++i)
        {
            if(a[i]==-1)
            {
                broke[i]=1;
            }
            else
            {
                onboard[ a[i] ]=1;
            }
        }
        for(int i=1;i<=n;++i)
        {
            if(!onboard[i])
            {
                b.push_back(i);
            }
        }
        memset(cnt,0,sizeof(cnt));
        cnt[1]=0;
        for(int i=0;i<b.size();++i)
        {
            if( broke[ b[i] ] )++cnt[1];
        }
        LL m = b.size();

        for(int i=2;i<=cnt[1];++i)
        {
            cnt[i] = C[ cnt[1] ][i];
        }

        cnt[0]=1;
        LL res = 0;
        for(int i=0;i<=m;++i)
        {
            if(i%2==0)
            {
                res = (res + cnt[i]*f[m -i]% mod )%mod;
            }
            else
            {
                res = ( res - cnt[i]*f[m -i]%mod +mod )%mod;
            }
        }
        cout<<res<<endl;

    }
	return 0;
}
