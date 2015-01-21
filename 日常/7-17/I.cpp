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

char s[20005];
int main()
{
    int T;
    int n,m;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&n,&m);
        scanf("%s",s);
        bool ok=true;
            vector<int> seg;
            int len=0;
            char pre=s[0];
            s[n]='0';
            for(int i=0;i<=n;++i)
            {
                if(s[i]==pre)
                {
                    ++len;
                }
                else
                {
                    seg.push_back(len);
                    len=1;
                    pre=s[i];
                }
            }
            sort(seg.rbegin(),seg.rend());
            int sum=0;
            for(int i=0;i<seg.size();++i)
            {
                sum += (seg[i]+m-1)/m;
            }
            if(seg[0]<m)
            {
                puts("-1");
            }
            else
            printf("%d\n",sum);
    }
	return 0;
}
