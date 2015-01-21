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
	double Fe= 0.4,Se=1.6;
	printf("res  = %.6f\n",1.0/( (1.0-Fe)+Fe/Se ));
}