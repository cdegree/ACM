#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long LL;
#define inf 10000000000
#define N 1000005
#define M 50010
#define eps 1e-8
int dp[2][3][3], sum[N][3][3];
char str[N];

int main() {/*
#ifndef ONLINE_JUDGE
	freopen("C:\\Users\\Slon\\Desktop\\in.txt","r",stdin);
	freopen("C:\\Users\\Slon\\Desktop\\out.txt","w",stdout);
#endif*/
	int n = 1000000, m = 10000000;
	
	while (scanf("%d", &n) != EOF) {
		scanf("%d%s", &m, str);

		int u = (n-1)&1;  // n为
		memset(dp[u], 0, sizeof(dp[u]));
		dp[u][0][1]++;
		dp[u][1][0]++;
		sum[n-1][1][0] = 1;
		for (int i = n-2; i >= 0; --i) 
		{
			u = i & 1;
			int v = u ^ 1;
			memset(dp[u], 0, sizeof(dp[u]));
			for (int j = 0; j < 3; ++j)
			{
				for (int k = 0; k < 3; ++k) 
				{
					if (j) 
					{
						if (k != 2) dp[u][j][k] = (dp[u][j][k] + dp[v][j-1][k+1]) % m;
						if (!k) dp[u][j][k] = (dp[u][j][k] + dp[v][j-1][k]) % m;
						sum[i][j][k] = dp[u][j][k];
					}

					if (k) 
					{
						if (j != 2) dp[u][j][k] = (dp[u][j][k] + dp[v][j+1][k-1]) % m;
						if (!j) dp[u][j][k] = (dp[u][j][k] + dp[v][j][k-1]) % m;
					}
				}
			}
		}
		int ans = 1, x = 0, y = 0;
		for (int i = 0; i < n; ++i) 
		{
			if (str[i] == 'P')
			{
				for (int j = 0; j < 3; ++j) 
				{	
					for (int k = 0; k < 3; ++k) 
					{
						if (x+j < 3 && y+k < 3)
						{
							ans = (ans + sum[i][j][k]) % m;
						}
					}
				}
				y++;
				if (x) x--;
			}
			else 
			{
				x++;
				if (y) y--;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}