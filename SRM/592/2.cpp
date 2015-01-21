#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

int a[55], b[55];
int main() {
    int n=50, k;
    // while(~scanf("%d%d", &n, &k))
    int sum = 0;
    int add=1;
    for(int i=0;i<n;++i)
    {
        sum += add;
        if(i&1)add++;
    }
    printf("%d\n",sum);
}


//Powered by [KawigiEdit] 2.0!
