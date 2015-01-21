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

int main()
{
    double x1,y1,z1,x2,y2,z2;
    while(~scanf("%lf%lf%lf%lf%lf%lf",&x1,&y1,&z1,&x2,&y2,&z2))
    {
        double res = sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1)+(z2-z1)*(z2-z1));
        double d = res;
        res += (fabs(x1-x2)*fabs(y1-y2)/d/d/d)*(fabs(y1-y2)*fabs(x1-x2)/d/d/d);
        res += (fabs(z1-z2)/d/d)*(fabs(z1-z2)/d/d)/d;
        //res +=sqrt( fabs(y1-y2)/d);
        //res += fabs(y2-y1)/d;
        printf("%.5f\n",res);
    }
	return 0;
}
