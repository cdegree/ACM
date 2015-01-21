#include <cstdio>
#include <algorithm>
#include <map>
#include <cmath>
#include <cstdlib>
#include <vector>
#include <set>
#include <queue>
#include <string>
#include <cstring>

using namespace std;

const int N = 100005;
int res[N][2];
int main()
{
    int n,k;
    while(~scanf("%d%d",&n,&k))
    {
        int m = n/2;
        int r = n%2;
        if(m>k)
        {
            puts("-1");
        }
        else if(k!=0&&n==1)
        {
            puts("-1");
        }
        else
        {
            int need = k-m+1;
            int g=1;
            for(int i=0; i<m-1; ++i)
            {
                if(g!=need&&g+1!=need&&g!=need*2&&g+1!=need*2)
                {
                    res[i][0]=g;
                    res[i][1]=g+1;
                }
                else
                {
                    --i;
                }
                g+=2;
            }
            res[m-1][0]=need;
            res[m-1][1]=need*2;
            for(int i=0; i<m; ++i)
            {
                for(int j=0; j<2; ++j)
                    printf("%d ",res[i][j]);
            }
            if(r)
            {
                printf("%d",1000000000);
            }
            puts("");
        }
    }
    return 0;
}
