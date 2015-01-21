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

int od[2005];
int bb[2005],as[2005];
int main()
{
    int n;
    scanf("%d",&n);
    {
        for(int i=1;i<=n;++i)
        {
            int a;
            scanf("%d",&a);
            od[a]=i;
        }
        memset(bb,0,sizeof(bb));
        memset(as,0,sizeof(as));
        for(int i=1;i<=n;++i)
        {
            for(int j=i+1;j<=n;++j)
            {
                if(od[i]>od[j])
                {
                    ++bb[i];
                    ++as[j];
                }
            }
        }
        for(int i=1;i<=n;++i)
        {
            printf("%d %d\n",1+bb[i],n-as[i]);
        }
    }
	return 0;
}
