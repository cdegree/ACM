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
#include <stdlib.h>
#include <stdio.h>

using namespace std;

typedef long long LL ;

char s[1005];
int bcnt=0,wcnt=0,bbcnt,wbcnt;
void gao(int len)
{
	int cnt=1;
	char pre=s[0];
	bool becut=false;
	for(int i=1;i<len;i++)
	{
		if(pre==s[i])
		{
			cnt++;
		}
		else 
		{
			becut=true;
			break;
		}
	}
	if(becut)
	{
		if(s[0]!=s[len-1])
		{
			cnt--;
		}
		if(s[len-1]=='B')wbcnt++;
		else bbcnt++;
	}
	if(s[0]=='B')bcnt+=cnt;
	else wcnt+=cnt;

}
int main()
{
	freopen("input.txt","r",stdin);
	int n,T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		bbcnt=wbcnt=bcnt=wcnt=0;
		for(int i=0;i<n;i++)
		{
			scanf("%s",s);
			int len = strlen(s);
			gao(len);
		}
		if(bcnt>wcnt||(bcnt==wcnt&&bbcnt>wbcnt))printf("Win\n");
		else printf("Lose\n");

	}
	return 0;
}