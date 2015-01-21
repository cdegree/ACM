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

inline bool check(char c)
{
	return isalpha(c)||isdigit(c)||c=='.'||c==','||c=='?'||c=='!';
}
char s[N];


int gaomaohao(int st)
{
	while(s[st]!='\"')
	{
		printf("%c",s[st++]);
	}
	return ++st;
}
int gaoword(int st)
{
	while(check(s[st]))
	{
		printf("%c",s[st++] );
	}
	return st;
}

void gao()
{
	int len = strlen(s);

	for(int i=0;i<len;)
	{
		if(s[i]=='\"')
		{
			//printf("i = %d\n",i);
			printf("<");
			i = gaomaohao(i+1);
			puts(">");
		}
		else if(check(s[i]))
		{
			//printf("i = %d\n",i);
			printf("<");
			i = gaoword(i);
			puts(">");
		}
		else 
		{
			++i;
		}
	}

}

int main(int argc, char const *argv[])
{
	//freopen("Bin.txt","r",stdin);
	while(gets(s))
	{
		//puts(s);
		gao();
	}
	return 0;
}