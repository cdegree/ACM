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

const int N  = 300005;
int a[100005];

struct shoot
{
	int Alice;
	int price;
	void clear()
	{
		price=0;
		Alice=-1;
	}
}S[N];
int len;


void gao(int n,int c,int who)
{
	if(n%2==0)
	{
		int m = n/2+1;
		len = 1 ;
		while(~S[len].Alice)++len;
		while(c>0)
		{
			for(int i=0;i<m;++i)
			{
				S[len+i].Alice=who;
				++S[len+i].price;
				--c;
				if(c==0)break;
			}
		}
	}
	else 
	{
		int m = (n+1)/2;
		len = 1 ;
		while(~S[len].Alice)++len;
		while(c>0)
		{
			for(int i=0;i<m;++i)
			{
				S[len+i].Alice=who;
				++S[len+i].price;
				--c;
				if(c==0)break;
			}
		}
	}
}
bool cmp(shoot a,shoot b)
{
	if(a.price!=b.price)
	{
		return a.price>b.price;
	}
	return a.Alice>b.Alice;
}
int main(int argc, char const *argv[])
{
	freopen("Ain.txt","r",stdin);
	int n,c1,c2;
	int T;
	scanf("%d",&T);
	for(int t=1;t<=T;++t)
	{
		scanf("%d %d %d",&n,&c1,&c2);
		printf("Case #%d: ",t);
		for(int i=0;i<N;++i)
		{
			S[i].clear();
		}
		gao(n,c1,1);
		gao(n,c2,0);
		len = 1 ;
		while(~S[len].Alice)++len;
		//printf("n = %d ,len = %d\n",n,len);
		while(len-1>n)
		{
			sort(S+1,S+len,cmp);
			if(S[len-1].Alice==1)
			{
				int pos=-1;
				for(int j=len-2;j>=1;--j)
				{
					if(S[j].Alice==1)
					{
						pos=j;
						break;
					}
				}
				if(~pos)
				{
					while(S[len-1].price>0)
					{
						for(int i=pos;i>=1;--i)
						{
							if(S[i].Alice==1)
							{
								++S[i].price;
								--S[len-1].price;
								if(S[len-1].price==0)
								{
									break;
								}
							}
						}
					}
					--len;
				}
				else 
				{
					break;
				}
			}
			else 
			{
				int pos=-1;
				for(int j=len-2;j>=1;--j)
				{
					if(S[j].Alice==0)
					{
						pos=j;
						break;
					}
				}
				if(~pos)
				{
					while(S[len-1].price>0)
					{
						for(int i=pos;i>=1;--i)
						{
							if(S[i].Alice==0)
							{
								++S[i].price;
								--S[len-1].price;
								if(S[len-1].price==0)
								{
									break;
								}
							}
						}
					}
					--len;
				}
				else 
				{
					break;
				}
			}
		}

		//puts("");
		
		for(int i=1;i<min(len,n+1);++i)
		{
			//printf("%d: alice = %d, price = %d\n",i,S[i].Alice,S[i].price);
		}
		int cnt1=0,cnt2=0;
		
		for(int i=1;i<min(len,n+1);++i)
		{
			if(S[i].Alice==1)
			{
				++cnt1;
			}
			else 
			{
				++cnt2;
			}
		}
		if(cnt1>cnt2)
		{
			puts("1");
		}
		else if(cnt1==cnt2)
		{
			puts("0");
		}
		else 
		{
			puts("-1");
		}
	}
	return 0;
}