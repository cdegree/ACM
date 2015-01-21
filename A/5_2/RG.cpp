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


int main(int argc, char const *argv[])
{
	double PH1 = 0.1;
	double PHE = 0.982;
	double CES = 0.5;
	printf("%.6f\n",PH1+(PHE-PH1)/5*CES);
	return 0;
}