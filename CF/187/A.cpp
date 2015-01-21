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

const int N = 200005;
LL a[200005],pre[N];
int main(int argc, char const *argv[])
{
	//freopen("Ain.txt","r",stdin);
	LL n,k;
	while(cin>>n>>k){
		for(int i=1;i<=n;++i){
			cin>>a[i];
		}
		memset(pre,0,sizeof(pre));
		LL sub=0;
		LL m=n;
		int j=1;
		for(int i=1;i<=n;++i){
			LL sum = pre[i-1] - (m-j)*a[i]*(j-1) ;
			if(sum<k){
				pre[i] = pre[i-1];
				--m;
				//printf("%d\n",sum);
			}
			else {
				pre[i] = pre[i-1] + a[i]*(j-1);
				++j;
			}
			if(sum<k){
				printf("%d\n",i);
			}
		}
	}
	return 0;
}