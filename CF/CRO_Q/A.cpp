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
const int N = 1005;
map<int,int> mp;

int main(int argc, char const *argv[])
{
	//freopen("Ain.txt","r",stdin);
	int n;
	while(cin>>n)
	{
		mp.clear();
		for(int i=0;i<n;++i)
		{
			int a;
			cin>>a;
			if(a!=0)mp[a]++;
		}
		int res = 0;
		bool ok=true;
		for( map<int,int>::iterator it = mp.begin() ; it != mp.end() ; ++it )
		{
			if(it->Y>2)
			{
				ok=false;
			}
			else if(it->Y==2)
			{
				++res;
			}
		}
		if(ok)
		{
			printf("%d\n",res);
		}
		else 
		{
			puts("-1");
		}
	}

	return 0;
}