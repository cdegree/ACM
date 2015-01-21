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

int hh,mm,ss,h,m,s;
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d:%d:%d %d:%d:%d",&hh,&mm,&ss,&h,&m,&s);

        ss -= s;
        if(ss<0)
        {
            ss += 60 ;
            --mm;
        }
        mm -= m ;
        if(mm<0)
        {
            mm += 60 ;
            --hh;
        }
        hh -= h;
        while(hh<0)
        {
            hh += 12;
        }
        printf("%02d:%02d:%02d\n",hh,mm,ss);
    }
	return 0;
}
