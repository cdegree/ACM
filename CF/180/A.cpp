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
	freopen("Ain.txt","r",stdin);
	int n;
	string s;
	while(cin>>n)
	{
		cin>>s;
		int st=-1,ed=-1;
		for(int i=0;i<s.size();++i)
		{
			if(s[i]=='L')
			{
				st=i;
				if(ed==-1)
				{
					ed=i-1;
				}
			}
			else if(s[i]=='R')
			{
				st=i;
				ed=i+1;
			}
		}
		printf("%d %d\n",st+1,ed+1);
	}
	return 0;
}