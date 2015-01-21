#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cctype>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <algorithm>
#include <iostream>
#include <string>
#include <set>
#define X first
#define Y second
#define sqr(x) (x)*(x)
using namespace std;
const double PI = acos(-1.0);
map<int,int>::iterator it;
typedef long long LL ;
typedef unsigned long long uLL;
#pragma comment(linker,"/STACK:102400000,102400000")

uLL C[36][36];
void init()
{
    for(int i=0;i<36;++i)C[i][i]=C[i][0]=1;
    for(int i=1;i<36;++i)
    {
        for(int j=1;j<36;++j)
        {
            C[i][j] = C[i-1][j-1] + C[i-1][j];
        }
    }
}
int main()
{
    init();
    int n,a,b;
    while(cin>>n>>a>>b)
    {
        uLL res = C[n+a][n]*C[n+b][n];
        cout<<res<<endl;
    }
	return 0;
}
