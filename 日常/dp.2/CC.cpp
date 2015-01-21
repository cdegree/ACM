#include<cstdio>

#include<algorithm>

#include<vector>

#include<queue>

#include<cstring>

#define sf scanf

#define pf printf

#define ps for(;;)

#define fr freopen

#define lp(i,a,b) for(int i = a; i <= b; ++i)

using namespace std;
typedef long long ll;

ll fac[21];

int cnt[27]; char ans[110];

ll count() {

ll r = 0,t = 0;

    lp(i,1,26)t += cnt[i];

    r = fac[t];

    lp(i,1,26)r /= fac[cnt[i]];

    return r;

}

int main() {

    fac[0] = 1; lp(i,1,20)fac[i] = fac[i-1] * i;

    int test; sf("£¥d",&test);

    lp(kase,1,test) {

        lp(i,1,26)cnt[i] = 0;

        char tmp[110]; ll n; sf("£¥s£¥lld",tmp + 1,&n);

        int t = strlen(tmp + 1);

        lp(i,1,t)++cnt[tmp[i] - 'a' + 1];

        if(count() < n)pf("Case £¥d: Impossible\n",kase);

        else {

            lp(i,1,t) {

                lp(j,1,26)if(cnt[j]) {

                    --cnt[j];

                    if(count() >= n) {

                        ans[i] = 'a' + j - 1;

                        break;

                    }
                    else {

                        n -= count();

                        ++cnt[j];

                    }

                }



            }

            pf("Case £¥d: ",kase);

            lp(i,1,t)pf("£¥c",ans[i]); pf("\n");

        }

    }

    //ps;

    return 0;

}
