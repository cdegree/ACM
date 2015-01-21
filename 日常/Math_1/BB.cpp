#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
#define llint __int64

int cnt;
int n, m;
int vis[12];
int t[12];
int d[12];

//欧几里得求最大公约数
llint gcd(llint a, llint b)
{
    if (a % b == 0) {
        return b;
    } else {
        return gcd(b, a % b);
    }
}

//用回溯求容斥
void dfs(int num, int pos, llint &sum)
{
    int i;
    if (pos == num) {
        llint lcm = 1;
        for (i = 0; i < num; i++) {
            lcm = lcm * t[i] / gcd(lcm, t[i]);
        }
        //奇数是加
        if (num & 1) {
            sum += (n - 1) / lcm;
        //偶数是减
        } else {
            sum -= (n - 1) / lcm;
        }
    } else {
        for (i = pos; i < cnt; i++) if (pos == 0 || (!vis[i] && d[i] > t[pos - 1]))
        {
            vis[i] = 1;
            t[pos] = d[i];
            dfs(num, pos + 1, sum);
            vis[i] = 0;
        }
    }
}

int main()
{
    while (cin >> n >> m)
    {
        int i, j;
        cnt = 0;
        for (i = 0; i < m; i++) {
            int temp;
            cin >> temp;
            if (temp != 0)
            {
                d[cnt++] = temp;
            }
        }
        llint ans = 0;
        for (i = 1; i <= cnt; i++)
        {
            memset(vis, 0, sizeof(vis));
            dfs(i, 0, ans);
        }
        cout << ans << endl;
    }
    return 0;
}
