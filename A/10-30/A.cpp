/*Sample code to read in test cases:*/
#include <iostream>
#include <string>
#include <algorithm>
#include <cstdio>
using namespace std;
struct person
{
	string s;
}P[10005];
bool cmp(person a,person b)
{
	return a.s<b.s;
}
char s[1005];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int n;
		scanf("%d",&n);
		for(int i=0;i<n;++i)
		{
			scanf("%s",s);
			P[i].s=s;
		}
		sort(P,P+n,cmp);
		for(int i=0;i<n;++i)
		{
			printf("%s",P[i].s.c_str());
		}
		puts("");
	}
}
