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

char s1[22],s2[22];
int d1,d2;
LL cnt[1005],cnt2[1005];
int main()
{
    LL n,m,k;
    while(cin>>n>>m>>k)
    {
        if(n==0&&m==0&&k==0)break;
        LL res = n*m*k;
        int p;
        cin>>p;
        memset(cnt,0,sizeof(cnt));
        memset(cnt2,0,sizeof(cnt2));
        while(p--)
        {
            scanf("%s%d%s%d",s1,&d1,s2,&d2);
            if(s1[0]=='c')
            {
                res-=k;
                cnt[d2]++;
            }
            else if(s1[0]=='p')
            {
                cnt2[d1]++;
                res-=n;
            }
        }
        for(int i=1;i<=m;++i)
        {
            res +=cnt[i]*cnt2[i];
        }
        cout<<res<<endl;
    }
    return 0;
}
