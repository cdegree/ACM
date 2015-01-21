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
int count_one(string s)
{
	int ret=0;
	for(int i=0;i<s.size();++i)
	{
		if(s[i]=='1')
		{
			++ret;
		}
	}
	return ret;
}
int main(int argc, char const *argv[])
{
	//freopen("Cin.txt","r",stdin);
	string a,b;
	while(cin>>a>>b)
	{
		int cnta=count_one(a);
		int cntb=count_one(b);
		if(cnta>=cntb||( (cnta%2==1)&&(cnta==cntb-1)  ))
		{
			puts("YES");
		}
		else 
		{
			puts("NO");
		}
	}
	return 0;
}