#include <cstdlib>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <fstream>
#include <numeric>
#include <iomanip>
#include <bitset>
#include <list>
#include <stdexcept>
#include <functional>
#include <utility>
#include <ctime>
#define F(x) ((sqrt(r1*r1-x*x)*sqrt(r2*r2-x*x)))
using namespace std;
double r1,r2;
double pf (int i)
{
    double s=1;
    for (int j=0; j<i; j++)
        s*=2;
    return s/2;
}
const int M = 25;
double gcc (double a, double b,double aa[][M],int i)
{
    double s,h,x;
    h=(b-a)/pf(i);
    s=0;
    x=a+h/2;
    do
    {
        s+=F(x);
        x+=h;
    }
    while (x<b);
    aa[0][i]=aa[0][i-1]/2+h/2*s;
    return 0;
}
double aa[M][M]= {0},e,a,b,h;
int main()
{

    int j,i,n;
    int T;
    scanf("%d",&T);
    while(T--)
    {
        memset(aa,0,sizeof(aa));
        scanf("%lf%lf",&r1,&r2);
        if(r1>r2)swap(r1,r2);
        e=1e-5;
        a=0;
        b=r1;
        aa[0][0]=(b-a)*(F(a)+F(b))/2.0;
        gcc(a,b,aa,1);
        aa[1][0]=(4.0*aa[0][1]-aa[0][0])/3;
        for (i=1; i<M; i++)
        {
            gcc(a,b,aa,i+1);
            for ( n=i,j=1; n>0; n--,j++)
                aa[j][n]=(pf(2*j+1)*aa[j-1][n+1]-aa[j-1][n])/(pf(j*2+1)-1);
            if (fabs(aa[i][1]-aa[i][0])<e)
                break;
            else
                aa[i+1][0]=(pf(2*i+3)*aa[i][1]-aa[i][0])/(pf(2*i+3)-1);
        }
        printf("%.5f\n",8*aa[i][1]);
    }
    return 0;
}
