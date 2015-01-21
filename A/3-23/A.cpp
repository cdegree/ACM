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

using namespace std;

typedef long long LL ;

int a[1005];
int main()
{
    int n;
    while(cin>>n)
    {
        for(int i=1;i<=n;i++)cin>>a[i];
        int sum=0,pos=-1;
        for(int i=1;i+2<=n;i++)
        {
            int now = a[i]+a[i+1]+a[i+2];
            if(now>sum)
            {
                sum=now;
                pos=i+1;
            }
        }
        printf("%d %d\n",sum,pos);
    }
	return 0;
}
