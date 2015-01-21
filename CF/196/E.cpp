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
#pragma comment(linker,"/STACK:102400000,102400000")

const int N=1000006;
bool isprime[N];
int len,prime[N];
void init()
{
    isprime[1]=0;
    for(int i=2;i<N;++i)
    {
        if(isprime[i])
        {
            for(int j=i+i;j<n;j+=i)
            {
                isprime[j]=0;
            }
            prime[len++]=i;
        }
    }
}
int main()
{
	return 0;
}
