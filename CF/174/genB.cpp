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
    int n = 200000;
    freopen("in.txt","w",stdout);
    printf("%d\n",n);
    for(int i=1;i<n;i++)
    {
        printf("%d\n",abs(rand())+1);
    }
	return 0;
}
