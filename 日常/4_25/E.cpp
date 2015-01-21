/*

([\+\-]) ? (?<integral_digits>\d*) ? ( (\.)(?<fractional_digits>\d*) ) ? ( ([eE]) (?<exponent>[\+\-]? \d+) )
*/
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
char s[5000000];
int i;
bool OK,empty_fraction,empty_integral,Bed;
void advance()
{
	++i;
}
bool isaddsub(char c)
{
	return c=='+'||c=='-';
}
void error()
{
	OK=false;
}

void Q()
{
	if(isdigit(s[i]))
	{
		advance();
		Q();
	}
}
void A()
{
	if(isaddsub(s[i]))
	{
		advance();
	}
	if(isdigit(s[i]))
	{
		advance();
		Q();
	}
	else 
	{
		empty_integral=true;
	}
}
void B()
{
	if(s[i]=='.')
	{
		advance();
		if(isdigit(s[i]))
		{
			advance();
			Q();
		}
		else 
		{
			empty_fraction=true;
		}
	}
	else 
	{
		empty_fraction=true;
	}
	double a = +0.-2 ;
}
void Cadd()
{
	if(isaddsub(s[i]))
	{
		advance();
	}
	if(isdigit(s[i]))
	{
		advance();
		Q();
	}
	else 
	{
		error();
	}
}


void E()
{
	if(s[i]=='e'||s[i]=='E')
	{
		advance();
		Cadd();
	}
}
void C()
{
	E();
}
void gao()
{
	A();
	B();
	C();
}

int main(int argc, char const *argv[])
{
	freopen("Ein.txt","r",stdin);
	while(gets(s))
	{
		if(s[0]=='#')
		{
			break;
		}
		OK=true;
		Bed = empty_fraction=empty_integral=false;

		i=0;
		gao();
		if(empty_fraction&&empty_integral)
		{
			OK=false;
		}
		if(OK&&i==strlen(s))
		{
			puts("Yes");
		}
		else 
		{
			puts("No");
		}
	}
	return 0;
}