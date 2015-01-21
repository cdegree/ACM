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

LL n,k,vm[N];

char s[22];
inline bool test_bit(LL mask,int pos)
{
	return mask&(1LL<<pos);
}
void pf(LL mask)
{
	for(int i=31;i>=0;--i)
	{
		printf("%d",test_bit(mask,i)?1:0);
		if(i%8==0)printf(" ");
	}
	puts("");
}
LL readoneline()
{
	LL a,b,c,d;
	scanf("%I64d.%I64d.%I64d.%I64d",&a,&b,&c,&d);
	return a*(1LL<<24)+b*(1LL<<16)+c*(1LL<<8)+d;
}
void print(LL mask)
{
	int a,b,c,d;
	a = mask/(1LL<<24);
	mask %=(1LL<<24);
	b = mask/(1LL<<16);
	mask %=(1LL<<16);
	c = mask/(1LL<<8);
	mask %=(1LL<<8);
	d = mask;
	printf("%d.%d.%d.%d\n",a,b,c,d);
}
LL subnet_mask(int pos)
{
	return ((1LL<<32)-1) - ( (1LL<<pos)-1 );
}
void gao()
{
	for(int i=0;i<n;++i)
	{
		vm[i] = readoneline();
		//pf(vm[i]);
	}
	bool found=false;
	LL res = 0;
	for(int pos=31;pos>=0;--pos)
	{
		res = subnet_mask(pos);
		int cnt=0;
		set<LL> myset;
		for(int i=0;i<n;++i)
		{
			myset.insert(res&vm[i]);
		}
		if(myset.size()==k)
		{
			found=true;
			break;
		}
	}
	if(found)
	{
		//pf(res);
		print(res);
	}
	else 
	{
		puts("-1");
	}

}
int main(int argc, char const *argv[])
{
	//freopen("Cin.txt","r",stdin);
	while(cin>>n>>k)
	{
		gao();
	}
	return 0;
}