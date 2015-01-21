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

set< pair<int,int> > sp;

int main()
{
    int n;
    while(1)
    {
        scanf("%d",&n);
        if(n==0)break;
        sp.clear();
        sp.insert( make_pair(100000010,1) );
        for(int i=0;i<n;++i)
        {
            int id,p;
            scanf("%d%d",&id,&p);
            pair<int,int> pp = make_pair( p,id );
            sp.insert( pp );
            set< pair<int,int> >::iterator it = sp.find(pp),jt,kt;
            if(it==sp.begin())
            {
                ++it;
                printf("%d %d\n",id,it->second);
            }
            else
            {
                jt=--it;
                ++it;
                kt=++it;
                if( abs(jt->first-p) <= abs(kt->first-p))
                {
                    printf("%d %d\n",id,jt->second);
                }
                else
                {
                    printf("%d %d\n",id,kt->second);
                }
            }
        }
    }
	return 0;
}
