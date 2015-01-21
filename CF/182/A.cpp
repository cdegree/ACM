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

int a[205];
int get_sum(int n)
{
    int ret=0;
    for(int i=1;i<=n;++i)
    {
        ret +=a[i];
    }
    return ret;
}
int main()
{
    int n;
    while(cin>>n)
    {
        int m=2*n-1;
        for(int i=1;i<=n*2-1;++i)cin>>a[i];
        bool dong=true;
        while(dong)
        {
            dong=0;
            int presum = get_sum(m);
            for(int i=1;i<=n;++i)
            {
                for(int j=0;j<n;++j)
                {
                    a[i+j]=-a[i+j];
                }
                if(get_sum(m)>presum)
                {
                    dong=1;
                    break;
                }
                else
                {
                    for(int j=0;j<n;++j)
                    {
                        a[i+j]=-a[i+j];
                    }
                }
            }
        }
        printf("%d\n",get_sum(m));
    }
	return 0;
}
