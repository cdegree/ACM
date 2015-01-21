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

int dx[]={1,0,-1,0};
int dy[]={0,-1,0,1};

int get_k(char c)
{
	switch(c)
	{
		case 'E':return 0;
		case 'S':return 1;
		case 'W':return 2;
		case 'N':return 3;
	}
}
int t,sx,sy,ex,ey;
bool check1(int k)
{
	return abs(ex-(sx+dx[k]))+abs(ey-(sy+dy[k])) < abs(ex-sx) + abs(ey-sy);
}
bool check2()
{
	return sx==ex&&sy==ey;
}
int main(int argc, char const *argv[])
{
	//freopen("Bin.txt","r",stdin);
	
	while(cin>>t>>sx>>sy>>ex>>ey)
	{
		string s;
		cin>>s;
		int res=-1;
		for(int i=0;i<t;++i)
		{
			int k = get_k(s[i]);
			if(check1(k))
			{
				sx += dx[k];
				sy += dy[k];
			}
			if(check2())
			{
				res = i+1;
				break;
			}
		}
		printf("%d\n",res);
	}
	return 0;
}