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

struct message
{
	int t,x;
}M[1005];

int main(int argc, char const *argv[])
{
	//freopen("Ain.txt","r",stdin);
	int n;
	while(cin>>n)
	{
		for(int i=0;i<n;++i)
		{
			scanf("%d%d",&M[i].t,&M[i].x);
		}
		int pre_t = M[0].t;
		int mx = M[0].x;
		int Q = M[0].x;
		for(int i=1;i<n;++i)
		{
			int now_t = M[i].t;
			int cnt_msg = Q;
			int msg_be_sented = now_t - pre_t ;
			if(msg_be_sented>=cnt_msg)
			{
				Q = M[i].x;
			}
			else 
			{
				Q = cnt_msg - msg_be_sented + M[i].x ;
			}
			mx = max(Q,mx);
			pre_t = now_t;
		}
		int final_t = pre_t + Q ;
		printf("%d %d\n",final_t,mx);
	}
	return 0;
}