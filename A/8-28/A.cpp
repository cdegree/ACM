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

char s[105];
int main()
{
    int n;
    int T=1;
    while(~scanf("%d",&n))
    {
        int mx=0;

        for(int i=0;i<n;++i)
        {
            scanf("%s",s);
            int cnt=0;
            for(int j=0;j<strlen(s);++j)cnt+=s[j];
            mx=max(mx,cnt);
        }
        printf("Case %d: ",T++);
        printf("%d\n",mx);
    }
	return 0;
}
