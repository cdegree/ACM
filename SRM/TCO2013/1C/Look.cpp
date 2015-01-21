#include <iostream>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <algorithm>
#include <stdlib.h>
#include <string>
#include <queue>
#include <vector>
#include <set>
#define eps 0
#define PI 3.14159265358979323846
#define maxn
#define oo 1000000000
#define clearAll(a) memset(a,0,sizeof(a))
#define sq(a) ((a)*(a))

using namespace std;

typedef long long ll;

struct Vet
{
	double x,y;
	Vet() {};
	Vet (double xx,double yy)
	{
		x=xx;
		y=yy;
	}
};

struct Pot
{
	double x,y;
	Pot() {};
	Pot (double xx,double yy)
	{
		x=xx;
		y=yy;
	}
};

Pot A,B,C;
double R,r;

Pot C1[2],C2[2];
Vet V1[2],V2[2];

double dist(double xx,double yy)
{
	return sqrt(sq(xx)+sq(yy));
}

void getC(Pot a, Pot b, double r, double R, Pot C[],Vet V[])
{
	Vet vab(a.x-b.x,a.y-b.y);
	Vet v1,v2;
	double d = dist(a.x-b.x,a.y-b.y);
	double theta = acos((r+R)/d);

	v1.x= vab.x*cos(theta) - vab.y*sin(theta);
	v1.y= vab.x*sin(theta) + vab.y*cos(theta);

	theta=-theta;

	v2.x= vab.x*cos(theta) - vab.y*sin(theta);
	v2.y= vab.x*sin(theta) + vab.y*cos(theta);

	double m = dist(v1.x,v1.y);
	v1.x/=m; v1.y/=m;
	v1.x*=(r+R); v1.y*=(r+R);

	m = dist(v2.x,v2.y);
	v2.x/=m; v2.y/=m;
	v2.x*=(r+R); v2.y*=(r+R);

	V[0] = v1;
	V[1] = v2;

	C[0].x = b.x + v1.x; C[0].y = b.y + v1.y;
	C[1].x = b.x + v2.x; C[1].y = b.y + v2.y;
}

bool check(double x,double y,double X[],double Y[])
{
	Vet a,b;
	a.x = X[2]-X[1]; a.y=Y[2]-Y[1];
	b.x = x-X[1];    b.y=y-Y[1];

	if (a.x*b.x+a.y*b.y<-eps) return false;

	a.x=-a.x; a.y=-a.y;
	b.x = x-X[2];    b.y=y-Y[2];

	if (a.x*b.x+a.y*b.y<-eps) return false;
	return true;
}


bool judge()
{
	Vet v1(B.x-A.x,B.y-A.y);
	Vet v2(C.x-A.x,C.y-A.y);

	double cos0 = (v1.x*v2.x+v1.y*v2.y)/(dist(v1.x,v1.y)*dist(v2.x,v2.y));

	double sin0 = sqrt(1-sq(cos0));

	double h = dist(A.x-C.x,A.y-C.y)*sin0;

	double X[3],Y[3];
	X[2]=A.x; X[1]=B.x;
	Y[2]=A.y; Y[1]=B.y;

	bool flag = check(C.x,C.y,X,Y);

	if (h+eps<r+R&&flag) return false;
	return true;
}

int main()
{
    //freopen("C:\\Users\\py\\Desktop\\input.txt","r",stdin);
    //freopen("C:\\Users\\py\\Desktop\\output.txt","w",stdout);
    int tt;
    scanf("%d",&tt);
    while (tt--)
    {
    	scanf("%lf%lf%lf%lf%lf%lf%lf%lf",&A.x,&A.y,&B.x,&B.y,&C.x,&C.y,&r,&R);

    	getC(A,C,r,R,C1,V1);
    	getC(B,C,r,R,C2,V2);

    	double ans = 1000000000.0f;

    	if (judge())
    	{
    		ans = dist(A.x-B.x,A.y-B.y);
    		printf("%.2f\n",ans);
    		return 0;
    	}

    	for (int i=0;i<2;i++)
    		for (int j=0;j<2;j++)
    		{
    			double tmp  = 0.0;
    			tmp  = dist(A.x-C1[i].x,A.y-C1[i].y)+dist(B.x-C2[j].x,B.y-C2[j].y);

    			double cos0 = (V1[i].x*V2[j].x+V1[i].y*V2[j].y)/(dist(V1[i].x,V1[i].y)*dist(V2[j].x,V2[j].y));
    			//cout << C1[i].x <<endl;
    			double theta = acos(cos0);

    			if (fabs(theta)>PI) theta = fabs(theta)-PI;

    			tmp += theta * (r+R);

    			ans = min(tmp,ans);
    		}

    	printf("%.2f\n",ans);

    }

    return 0;
}