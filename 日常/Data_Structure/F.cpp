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
#include <stdlib.h>
#include <stdio.h>

using namespace std;

typedef long long LL ;

const int maxn = 20005;

#define lson L , mid , rt << 1
#define rson mid + 1 , R , rt << 1 | 1
#define lc rt<<1
#define rc rt<<1|1

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
#include <stdlib.h>
#include <stdio.h>

using namespace std;

typedef long long LL ;

const int N = 100005;

struct Splay
{
	struct Node
	{
		int pre,chd[2];
		int val;
		Node()
		{
			chd[0]=chd[1]=pre=-1;
		}
		void Reset()
		{
			chd[0]=chd[1]=pre=-1;
		}
	}node[N];
	int root;

	void Rotate(int x, int c)  // 旋转操作 ，0 代表左旋， 1 代表右旋
	{
		int y = node[x].pre ;
		Push_Down(y),Push_Down(x);
		node[y].chd[!c] = node[x].chd[c];
		node[x].pre = node[y].pre;
		if(~node[y].pre)
		{
			node[ node[y].pre ].chd[ (node[ node[y].pre ].chd[0] == y)?0:1  ] = x;
		}
		node[x].chd[c] = y;
		node[y].pre = x;
		Push_Up(y);
		if(y == root)
		{
			root = x;
		}
	}

	void splay(int x, int f)  // splay操作 ，把节点x转移到f的下面
	{
		for( Push_Down(x); node[x].pre!=f; )
		{
			if( node[ node[x].pre ].pre == f )
			{
				Rotate( x, (node[ node[x].pre ].chd[0] == x)?0:1);
			}
			else 
			{
				int y = node[x].pre, z = node[y].pre;
				if( node[z].chd[0] == y )
				{
					Rotate(x,(node[y].chd[0] == x)?1:0);
					Rotate(x,1);
				}
				else 
				{
					Rotate(x,(node[y].chd[1] == x)?0:1);
					Rotate(x,0);
				}
			}
		}
		Push_Up(x);
	}

	void Push_Down(int rt)
	{

	}
	void Push_Up(int rt)
	{

	}
}splay;

int main(int argc, char const *argv[])
{
	int n;
	freopen("Din.txt","r",stdin);
	while(~scanf("%d",&n))
	{
		
	}
	return 0;
}