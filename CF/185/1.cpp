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

struct point
{
    int x,y;
}P[2002];

int main()
{
    int n,k;
    while(cin>>n>>k)
    {
        for(int i=0;i<n;++i)
        {
            P[i].x=i;
            P[i].y=i*2000;
        }
        int m=n*(n-1)/2;
        if(m>k)
        {
            for(int i=0;i<n;++i)
            {
                printf("%d %d\n",P[i].x,P[i].y);
            }
        }
        else
        {
            puts("no solution");
        }
    }
	return 0;
}
