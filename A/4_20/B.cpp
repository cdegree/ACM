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

const int N = 505;
int n,n1,n2;
LL Q[N][N];
LL C[N][N];

struct person
{
	int q1,c1,q2,c2;
}P[N];
bool cmp(person a,person b)
{
	return a.q1*b.c1>a.c1*b.q1;
}
int main(int argc, char const *argv[])
{
	freopen("Bin.txt","r",stdin);
	int T;
	scanf("%d",&T);
	for(int t=1;t<=T;++t)
	{
		scanf("%d %d %d",&n,&n1,&n2);
		memset(Q,-1,sizeof(Q));
		memset(C,-1,sizeof(C));
		Q[0][0]=C[0][0]=0;
		for(int i=1;i<=n;++i)
		{
			scanf("%d %d %d %d",&P[i].q1,&P[i].c1,&P[i].q2,&P[i].c2);
		}
		sort(P+1,P+n+1,cmp);
		for(int i=1;i<=n;++i)
		{
			LL q1 = P[i].q1;
			LL c1 = P[i].c1;
			LL q2 = P[i].q2;
			LL c2 = P[i].c2;
			for(int j=n1;j>=0;--j)
			{
				for(int k=n2;k>=0;--k)
				{
					if(j>0&&~Q[j-1][k])
					{
						if(Q[j][k]==-1)
						{
							Q[j][k] = Q[j-1][k] + q1;
							C[j][k] = C[j-1][k] + c1;
						}
						else if( (Q[j-1][k]+q1)*C[j][k] > Q[j][k]*(C[j-1][k]+c1) )
						{
							Q[j][k] = Q[j-1][k] + q1;
							C[j][k] = C[j-1][k] + c1;
						}
					}
					if(k>0&&~Q[j][k-1])
					{
						if(Q[j][k]==-1)
						{
							Q[j][k] = Q[j][k-1] + q2;
							C[j][k] = C[j][k-1] + c2;
						}
						else if( (Q[j][k-1]+q2)*C[j][k] > Q[j][k]*(C[j][k-1]+c2) )
						{
							Q[j][k] = Q[j][k-1] + q2;
							C[j][k] = C[j][k-1] + c2;
						}
					}
				}
			}
		}
		printf("Case #%d: ",t);
		double res = 1.0/C[n1][n2];
		LL sum = Q[n1][n2];
		LL sum1 = sum%10000;
		LL sum2 = sum/10000;
		res = res*sum1 + res*10000*sum2;

		//printf("%d %d\n",Q[n1][n2],C[n1][n2]);
		printf("%.6f\n",res);
	}
	return 0;
}