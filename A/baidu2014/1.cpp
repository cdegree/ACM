#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 100005;
int X[N],H[N];
struct ATTR {
    int X,H;
    int pre,next;
    int cnt;
    ATTR() {
        pre=next=-1;
        cnt=0;
    }
} attr[N],relex[N];
int lenAttr,lenRelex;

int tree[N];

void add(int k,int val)
{
    while(k<N)
    {
        tree[k] += val;
        k += (-k&k);
    }
}

int sum(int k)
{
    int ret=0;
    while(k>0)
    {
        ret += tree[k];
        k -= (-k&k);
    }
    return ret;
}
int mp[N];
int main() {
    int T;
    scanf("%d",&T);
    int n;
    for(int t=1; t<=T; ++t) {
        scanf("%d",&n);
        lenAttr=lenRelex=0;
        for(int i=0; i<n; ++i) {
            attr[i].pre=attr[i].next=-1;
            attr[i].cnt=0;
            relex[i].pre=relex[i].next=-1;
        }
        for(int i=0; i<n; ++i) {
            scanf("%d %d",X+i,H+i);
            if(H[i]) {
                mp[i]=lenAttr;
                attr[lenAttr].X=X[i];
                attr[lenAttr].cnt=1;
                attr[lenAttr++].H=H[i];
            } else {
                relex[lenRelex].X=X[i];
                relex[lenRelex++].H=H[i];
            }
        }
        for(int i=0; i<lenRelex; ++i) {
            int L=0,R=lenAttr-1,mid,ans=-1;
            while(L<=R) {
                mid=(L+R)/2;
                if(attr[mid].X<relex[i].X) {
                    ans = mid;
                    L = mid+1;
                } else {
                    R = mid - 1;
                }
            }
            if(ans==-1) {
                ++ans;
                attr[ans].cnt++;
            } else {
                int rt = ans+1;
                if( abs(attr[ans].X-relex[i].X) < abs(attr[rt].X-relex[i].X)  ) {
                    attr[ans].cnt++;
                } else if(abs(attr[ans].X-relex[i].X) > abs(attr[rt].X-relex[i].X)) {
                    attr[rt].cnt++;
                } else {
                    attr[ans].next=i;
                    relex[i].pre=ans;
                    relex[i].next=rt;
                    attr[rt].pre=i;
                }
            }
        }
        //printf("attrlen = %d relexlen = %d\n",lenAttr,lenRelex);
        memset(tree,0,sizeof(tree));
        for(int i=0;i<lenAttr;++i)
        {
            add(attr[i].H,attr[i].cnt);
            if(~attr[i].next)
            {
                int rid = attr[i].next;
                int nid = relex[rid].next;
                int mx = max( attr[i].H,  attr[nid].H  );
                add(mx,1);
            }
        }
        printf("Case #%d:\n",t);
        int q;
        scanf("%d",&q);
        char s[3];
        int l,v,r;
        int p;
        while(q--)
        {
            scanf("%s",s);
            if(s[0]=='Q')
            {
                scanf("%d",&r);
                printf("%d\n",sum(r));
            }
            else
            {
                scanf("%d %d",&p,&v);
                p=mp[p];
                //printf("id = %d, H = %d\n",p,v);
                add(attr[p].H,-attr[p].cnt);
                add(v,attr[p].cnt);

                if(~attr[p].pre)
                {
                    int rid = attr[p].pre;
                    int nid = relex[rid].pre;
                    int mx = max( attr[p].H,  attr[nid].H  );
                    add(mx,-1);
                    mx = max(v,attr[nid].H);
                    add(mx,1);
                }
                if(~attr[p].next)
                {
                    int rid = attr[p].next;
                    int nid = relex[rid].next;
                    int mx = max( attr[p].H,  attr[nid].H  );
                    add(mx,-1);
                    mx = max(v,attr[nid].H);
                    add(mx,1);
                }
                attr[p].H=v;
            }
        }
    }
    return 0;
}
