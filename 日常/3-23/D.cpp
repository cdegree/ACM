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

const double eps = 1e-8;
struct point
{
    double x,y;
};
point p[4];

double get_dis(point a,point b)
{
    return sqrt( (a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y) );
}
point get_mid(point a,point b)
{
    point ret ;
    ret.x= (a.x+b.x)/2;
    ret.y=(a.y+b.y)/2;
    return ret;
}

void print(point a)
{
    printf("%f %f\n",a.x,a.y);
}
bool ok(point a,point b,double dis)
{
    return get_dis(a,b)<=dis+eps;
}

point get_the_point_of_circle_near_point_o(point a,point b,point o,double r)
{

}
int main()
{
    double R;
    while(~scanf("%lf",&R))
    {
        for(int i=0;i<3;i++)
        {
            scanf("%lf %lf",&p[i].x,&p[i].y);
        }
        bool vis[3];
        memset(vis,false,sizeof(vis));
        if(get_dis(p[0],p[1])<=2*R+eps&&get_dis(p[0],p[2])<=2*R+eps)
        {
            printf("Now we have enough power\n");
            point res = get_mid(p[0],p[1]);
            print(res);
            res = get_mid(p[0],p[2]);
            print(res);
        }
        else
        {
            if(get_dis(p[0],p[1])>get_dis(p[0],p[2]))
            {
                swap(p[1],p[2]);
            }
            if(get_dis(p[0],p[1])<=2*R&&get_dis(p[1],p[2])<=2*R)
            {

            }
            else
            {

            }
        }
    }
	return 0;
}
