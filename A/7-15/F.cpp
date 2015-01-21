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
using namespace std;

typedef long long LL ;

string tp="fssst";
LL stoll(string s)
{
    LL ret = 0;
    LL e = 1;
    for(int i=s.size()-1;i>=0;--i)
    {
        ret += (s[i]-'a')*e;
        e *= 26;
    }
    return ret;
}
int main()
{
    printf("%d\n",'n'-'a');
    LL res = stoll(tp);
    printf("%lld\n",res);
	return 0;
}
