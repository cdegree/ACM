#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#define X first
#define Y second
#define sqr(x) ((x)*(x))
using namespace std;
const double eps = 1e-8 ;

typedef long long LL ;
const int N = 444;
struct fraction
{
	LL fz,fm;
	fraction()
	{
		fz=0;
		fm=1;
	}
	fraction(LL _fz,LL _fm)
	{
		fz=_fz;
		fm=_fm;
	}
	fraction add(fraction f)
	{
		fraction ret;
		ret.fm = f.fm*fm;
		ret.fz = fz*f.fm+f.fz*fm;
		LL g = __gcd(ret.fm,ret.fz);
		ret.fm/=g;
		ret.fz/=g;
		return ret;
	}
	fraction sub(fraction f)
	{
		fraction ret;
		ret.fm = f.fm*fm;
		ret.fz = fz*f.fm-f.fz*fm;
		LL g = __gcd(ret.fm,ret.fz);
		ret.fz/=g;
		ret.fm/=g;
		return ret;
	}
	fraction mul(fraction f)
	{
		fraction ret;
		ret.fm = f.fm*fm;
		ret.fz = fz*f.fz;
		LL g = __gcd(ret.fm,ret.fz);
		ret.fz/=g;
		ret.fm/=g;
		return ret;
	}
	void print()
	{
		if(fm==1)
		{
			printf("%lld\n",fz);
		}
		else
		{
			printf("%lld/%lld\n",fz,fm);
		}
	}
};
fraction F[N][N],sum[N];
fraction one(1,1),zero(0,1);
void init()
{
	F[0][1] = one;
	for(int i=1;i<=400;++i)
	{
		sum[i]=zero;
	}
	for(int i=400;i>=0;--i)
	{
		int row = 400 - i + 1;
		for(int j=1;j<=i;++j)
		{
			fraction C(400-i+j,j+1);
			//C.print();
			F[400-i+j][j+1]= C.mul(F[400-i+j-1][j]);
			sum[400-i+j] = sum[400-i+j].add(F[400-i+j][j+1]);
		}
		F[row][1] = one.sub(sum[row]);
	}
}
int main(int argc, char const *argv[])
{
	int T;
	freopen("Ein.txt","r",stdin);
	init();
	scanf("%d",&T);
	while(T--)
	{
		int t,m,k;
		scanf("%d %d %d",&t,&m,&k);
		printf("%d ",t);
		F[m][k].print();
	}
	return 0;
}
