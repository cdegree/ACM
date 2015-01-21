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


int mt[1005][1005];
char s[1005];
int main()
{
    int n;
    while(~scanf("%d",&n))
    {
        if(n==0)break;
        memset(mt,0,sizeof(mt));
        int ind[1005]={0},outd[1005]={0};
        for(int i=1;i<n;++i)
        {
            scanf("%s",s);
            for(int j=0;j<n-i;++j)
            {
                if(s[j]=='0')
                {
                    mt[i][i+j+1]=1;
                    ind[i]++;
                    outd[i+j+1]++;
                }
                else
                {
                    ind[i+j+1]++;
                    outd[i]++;
                    mt[i+j+1][i]=1;
                }
            }
        }
        bool ok=0;
        for(int i=1;i<=n;++i)
        {
            if(ind[i]==n-1)
            {
                ok=1;
            }
        }
        if(ok)
        {
            puts("1");
        }
        else
        {
            int cnt=0;
            for(int i=1;i<=n;++i)
            {
                if(outd[i]==n-1)++cnt;
            }
            printf("%d\n",n-cnt);
        }
    }
	return 0;
}
