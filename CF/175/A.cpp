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

using namespace std;

typedef long long LL ;

int main()
{
    int n,k;
    scanf("%d%d",&n,&k);
    int go=n;
    for(int i=0;i<k;i++)printf("%d ",go--);
    for(int i=0;i<n-k;i++)printf("%d ",i+1);
    puts("");
	return 0;
}
