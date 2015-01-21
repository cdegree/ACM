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

char s[8][8];

inline bool check_X(char c)
{
	return c=='X'||c=='T';
}
inline bool check_O(char c)
{
	return c=='O'||c=='T';
}

int get_X(int st,bool dir)
{
	int cnt=0;
	if(dir)
	{
		for(int i=0;i<4;++i)
		{
			if(check_X(s[st][i]))
			{
				++cnt;
			}
		}
	}
	else 
	{
		for(int j=0;j<4;++j)
		{
			if(check_X(s[j][st]))
			{
				++cnt;
			}
		}
	}
	return cnt;
}

bool Win_X()
{
	for(int i=0;i<4;++i)
	{
		if(get_X(i,0)==4||get_X(i,1)==4)
		{
			return true;
		}
	}
	int cnt=0;
	for(int i=0;i<4;++i)
	{
		if(check_X(s[i][i]))
		{
			++cnt;
		}
	}
	if(cnt==4)
	{
		return true;
	}
	cnt=0;
	for(int i=0;i<4;++i)
	{
		if(check_X(s[3-i][i]))
		{
			++cnt;
		}
	}
	if(cnt==4)
	{
		return true;
	}
	return false;
}


int get_O(int st,bool dir)
{
	int cnt=0;
	if(dir)
	{
		for(int i=0;i<4;++i)
		{
			if(check_O(s[st][i]))
			{
				++cnt;
			}
		}
	}
	else 
	{
		for(int j=0;j<4;++j)
		{
			if(check_O(s[j][st]))
			{
				++cnt;
			}
		}
	}
	return cnt;
}

bool Win_O()
{
	for(int i=0;i<4;++i)
	{
		if(get_O(i,0)==4||get_O(i,1)==4)
		{
			return true;
		}
	}
	int cnt=0;
	for(int i=0;i<4;++i)
	{
		if(check_O(s[i][i]))
		{
			++cnt;
		}
	}
	if(cnt==4)
	{
		return true;
	}
	cnt=0;
	for(int i=0;i<4;++i)
	{
		if(check_O(s[3-i][i]))
		{
			++cnt;
		}
	}
	if(cnt==4)
	{
		return true;
	}
	return false;
}
bool Full()
{
	for(int i=0;i<4;++i)
	{
		for(int j=0;j<4;++j)
		{
			if(s[i][j]=='.')
			{
				return false;
			}
		}
	}
	return true;
}
void gao()
{
	if(Win_X())
	{
		puts("X won");
	}
	else if(Win_O())
	{
		puts("O won");
	}
	else if(Full())
	{
		puts("Draw");
	}
	else 
	{
		puts("Game has not completed");
	}
}
int main(int argc, char const *argv[])
{
	int T;
	freopen("A-large.in","r",stdin);
	freopen("A-large.out","w",stdout);
	scanf("%d",&T);
	for(int t=1;t<=T;++t)
	{
		for(int i=0;i<4;++i)
		{
			scanf("%s",s[i]);
		}
		printf("Case #%d: ",t);
		gao();
	}
	return 0;
}