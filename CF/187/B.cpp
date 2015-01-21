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

string a,c;
int p,q;
int b,d;
int next[105];
int get_ac(){
	int na=a.size();
	int nc=c.size();
	int i=0,j=0;
	memset(next,-1,sizeof(next));
	//printf("%d  %d\n",na,nc);
	int cnt=0,cnt1=0,cc;
	for(cc=0;cc<na*b;++cc){
		if(a[i]!=c[j]){
			++i;
			if(i>=na){
				i=0;
				++cnt1;
			}
		}
		else {
			//printf("%d %d\n",i,j);
			++i;
			if(i>=na){
				i=0;
				++cnt1;
			}
			++j;
			if(j>=nc){
				j=0;
				++cnt;
				//printf("%d %d\n",i,j);
			}
			
		}
	}
	return cnt;
}
int main(int argc, char const *argv[])
{
	//freopen("Bin.txt","r",stdin);
	

	while(cin>>b>>d){
		cin>>a>>c;
		int cnt = get_ac();
		int res = cnt/d;
		printf("%d\n",res);
		
	}
	return 0;
}