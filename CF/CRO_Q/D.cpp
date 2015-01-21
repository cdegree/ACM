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

const int N = 10005;

int n,k;
int a[N],res[N];

int main(int argc, char const *argv[])
{
	//freopen("Din.txt","r",stdin);
	while(cin>>n>>k)
	{
		for(int i=1;i<n;++i)
		{
			a[i]=1;
		}
		a[n]=0;
		for(int i=0;i<k;++i)
		{
			//for(int j=1;j<=n;++j)printf("%3d%c",a[j],j==n?'\n':' ');
			
			int pos=-1;
			for(int j=n;j>=1;--j)
			{
				if(a[j]!=n-j)
				{
					pos=j;
					break;
				}
				else 
				{
					res[j]=n;
				}
			}
			int len = n - pos;
			for(int j=pos;j>max(0,pos-len+1);--j)
			{
				a[j] += a[j+len-1];
				res[j] = j+len-1;
			}
			for(int j=pos-len+1;j>=1;--j)
			{
				a[j] = a[pos-len+2];
				res[j] = pos - len + 2;
			}
			//puts("");
			
			for(int j=1;j<=n;++j)
			{
				printf("%d%c",res[j],j==n?'\n':' ');
			}
			//puts("");
		}
	}
	return 0;
}