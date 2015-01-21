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
#define X first
#define Y second
using namespace std;
const double eps = 1e-8 ;
typedef long long LL ;
int main(int argc, char const *argv[])
{
	//freopen("Ain.txt","r",stdin);
	int n,k;
	while(cin>>n>>k)
	{
		if(k>n)
		{
			puts("-1");
		}
		else 
		{
			if(k==1)
			{
				if(n==1)puts("a");
				else puts("-1");
			}
			else if(k==2)
			{
				for(int i=0;i<n;i++)
				{
					printf("%c",(i%2==0)?'a':'b' );
				}
				puts("");
			}
			else 
			{
				int m = k - 2 ;
				for(int i=0;i<n-m;i++)
				{
					printf("%c",(i%2==0)?'a':'b' );
				}
				for(int i=n-m;i<n;i++)
				{
					printf("%c",i-n+m+'c' );
				}
				puts("");
			}
		}
	}
	return 0;
}