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

double x,t;
double gao1()
{
    return 60*t-x*t;
}
double gao2()
{
    return 60*60*t/(60-x);
}
double gao3()
{
    return 12.0*60*60*60*t/x;
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int Q;
        scanf("%lf",&x);
        scanf("%d",&Q);
        int no;
        while(Q--)
        {
            scanf("%d %lf",&no,&t);
            if(no==1)
            {
                printf("%.2f\n",gao1());
            }
            else if(no==2)
            {
                printf("%.2f\n",gao2());
            }
            else
            {
                printf("%.2f\n",gao3());
            }
        }
    }
	return 0;
}
