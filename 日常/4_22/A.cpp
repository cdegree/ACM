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
const int N = 100005;
int a[N];
int n;
bool ok()
{
	sort(a,a+n);

		for(int i=0;i<n;++i)
		{
			if(a[i]%a[0]!=0)
			{
				return false;
			}
		}
		return true;
}
int main(int argc, char const *argv[])
{
	//freopen("Ain.txt","r",stdin);
	
	while(cin>>n)
	{
		for(int i=0;i<n;++i)cin>>a[i];
		if(ok())
		{
			printf("%d\n",a[0]);
		}
		else 
		{
			puts("-1");
		}
	}
	return 0;
}