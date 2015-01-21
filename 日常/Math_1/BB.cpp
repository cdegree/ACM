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

//ŷ����������Լ��
llint gcd(llint a, llint b)
{
    if (a % b == 0) {
        return b;
    } else {
        return gcd(b, a % b);
    }
}

//�û������ݳ�
void dfs(int num, int pos, llint &sum)
{
    int i;
    if (pos == num) {
        llint lcm = 1;
        for (i = 0; i < num; i++) {
            lcm = lcm * t[i] / gcd(lcm, t[i]);
        }
        //�����Ǽ�
        if (num & 1) {
            sum += (n - 1) / lcm;
        //ż���Ǽ�
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
