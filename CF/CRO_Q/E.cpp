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
const int M = 200005;
int n;
int dirto[M],next[N],nedge,head[N];
string str[M];
void add_edge(int u,int v,string s)
{
	dirto[nedge]=v;
	str[nedge]=s;
	next[nedge]=head[u];
	head[u]=nedge++;
}
string mod;
int res;

void init()
{
	nedge=0;
	res=0;
}

void gao(int cur,int nowpos)
{
	
}

int main(int argc, char const *argv[])
{
	while(cin>>n)
	{
		string s;
		int fa;
		init();
		for(int i=2;i<=n;++i)
		{
			cin>>fa>>s;
			add_edge(fa,i,s);
		}
		cin>>mod;
		gao(0,nowpos);
	}
	return 0;
}
