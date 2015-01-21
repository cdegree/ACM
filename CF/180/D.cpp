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
int n,m,k;
int a[N],b[N];
int main(int argc, char const *argv[])
{
	//freopen("Din.txt","r",stdin);
	while(cin>>n>>m>>k)
	{
		for(int i=0;i<n;++i)
		{
			scanf("%d",a+i);
		}
		for(int i=0;i<m;++i)
		{
			scanf("%d",b+i);
		}
		sort(a,a+n);
		sort(b,b+m);
		int s1=0,s2=0;
		vector<int> va,vb;
		while(s1<n&&s2<m)
		{
			if(a[s1]==b[s2])
			{
				++s1;
				++s2;
			}
			else if(a[s1]<b[s2])
			{
				va.push_back(a[s1]);
				++s1;
			}
			else 
			{
				vb.push_back(b[s2]);
				++s2;
			}
		}
		while(s1<n)
		{
			va.push_back(a[s1++]);
		}
		while(s2<m)
		{
			vb.push_back(b[s2++]);
		}
		if(va.size()>vb.size())
		{
			puts("YES");
		}
		else 
		{
			bool ok=false;
			for(int j=va.size()-1,p=vb.size()-1;j>=0;--j,--p)
			{
				if(va[j]>vb[p])
				{
					ok=true;
					break;
				}
			}
			if(ok)
			{
				puts("YES");
			}
			else 
			{
				puts("NO");
			}
		}
	}
	return 0;
}