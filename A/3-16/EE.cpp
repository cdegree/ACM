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

struct point
{
    LL x,y,z;
    LL dotx(point p1)
    {
        return x*p1.x+y*p1.y+z*p1.z;
    }
    LL mult(point p1)
    {

    }
};

point P[4];

int main()
{
    while(~scanf("%lld%lld%lld",&P[0].x,&P[0].y,&P[0].z))
    {
        for(int i=1;i<4;i++)
        {
            scanf("%lld%lld%lld",&P[i].x,&P[i].y,&P[i].z);
        }

    }
	return 0;
}
