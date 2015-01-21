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

const int N = 10088;
const LL mod = 10007;
char s[N];
LL F[N];
int main()
{
    int T;
    F[0]=1;
    F[1]=1;
    for(int i=2;i<N;++i)
    {
        F[i]=F[i-1]+F[i-2];
        F[i]%=mod;
    }
    scanf("%d",&T);
    for(int t=1;t<=T;++t)
    {
        scanf("%s",s);
        LL res=1;
        int len=strlen(s);
        LL cnt=0;
        for(int i=0;i<len;)
        {
            if(s[i]=='h'&&i+1<len&&s[i+1]=='e')
            {
                ++cnt;
                i+=2;
            }
            else
            {
                res *= F[cnt];
                res %= mod;
                cnt=0;
                ++i;
            }
        }
        res *= F[cnt];
        res %= mod;
        printf("Case %d: %I64d\n",t,res);
    }
	return 0;
}
