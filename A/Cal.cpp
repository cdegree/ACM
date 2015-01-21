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

double a[1005];

int main(int argc, char const *argv[])
{
	double n=24;
	const double income=100000;
	{
		double sum = 0 ;
		for(int i=0;i<n;++i){
			a[i]=income;
		}
		for(int i=0;i<n;++i){
			for(int j=0;j<=i;++j){
				sum += a[j]/2;
				a[j]/=2;
			}
		}
		printf("%.lf\n",income*n-sum);
	}
	return 0;
}