/* 按照lrj的黑书来写的
与极角序比较的优点：
1. 排序更简单，只是简单的比较，没有运算.
2. 起始点更好找，就是排序后的第一个点.
3. 可以很好地处理特殊情况(共线).
*/
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
typedef double Type; // 注意下面的fabs().
const int maxn = 1005;
const double EPS = 1e-8;
const double Pi = acos(-1.0);
struct Point
{
    Type x, y;
    Point () {}
    Point (Type & xx, Type & yy) : x(xx), y(yy) {}
};
// 判断正负.
int dblcmp(Type d)
{
    if (fabs(d) < EPS) return 0; // 注意数据类型不同，abs()也不同.
    return d > 0 ? 1 : -1;
}
// 叉乘.
// cross product of (c->a) and (c->b).
Type Cross(Point & c, Point a, Point b)
{
    return (a.x - c.x) * (b.y - c.y) - (b.x - c.x) * (a.y - c.y);
}
Type Distance(Point & u, Point & v)
{
    return sqrt( 0.0 + (u.x - v.x) * (u.x - v.x) + (u.y - v.y) * (u.y - v.y) );
}
int n;
Point point[maxn];
int Stack[maxn];
int top;
double ans;
bool cmp(const Point & a, const Point & b)
{
    if (a.y == b.y) return a.x < b.x;
    return a.y < b.y;
}
void graham_scan(void)
{
    int i;
    int temp_top;
    if (n <= 1)
    {
        top = 0;
        return ;
    }
    sort(point, point + n, cmp); // point[0]即为起点.
// 做右链.
    top = -1;
    Stack[++top] = 0;
    Stack[++top] = 1;
    for (i = 2; i < n; i++)
    {
        while (top >= 1 && dblcmp(Cross(point[Stack[top - 1]], point[i], point[Stack[top]])) >= 0) top--; // 如果不能左转，则退栈. 如果只要求极点，则共线的点也是不要的(即要加等于).
        Stack[++top] = i;
    }
    temp_top = top; // 此时的栈顶元素一定是第n个点.
// 做左链.
    Stack[++top] = n - 2;
    for (i = n - 3; i >= 0; i--)
    {
        while (top >= temp_top + 1 && dblcmp(Cross(point[Stack[top - 1]], point[i], point[Stack[top]])) >= 0) top--; // 如果不能左转，则退栈. 如果只要求极点，则共线的点也是不要的(即要加等于).
        Stack[++top] = i;
    }
// 此时的栈顶元素是第1个点.(如果凸包是一条直线，则左右链倒置相同.)
// 凸包的顶点为point[Stack[0]] 到 point[Stack[top - 1]].
}
int main(void)
{
    int i;
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        scanf("%lf %lf", &point[i].x, &point[i].y);
    }
    graham_scan();
    ans = 0;
    for (i = 0; i < top; i++)
    {
        printf("%lf %lf\n", point[Stack[i]].x, point[Stack[i]].y);
        ans += Distance(point[Stack[i]], point[Stack[i + 1]]); // point[Stack[top]] = point[Stack[0]].
    }
    printf("%lf\n", ans);
    return 0;
}
/******************************************************************************************************************************************************/
/******************************************************************************************************************************************************/
/******************************************************************************************************************************************************/
/******************************************************************************************************************************************************/
/******************************************************************************************************************************************************/
/******************************************************************************************************************************************************/
/******************************************************************************************************************************************************/
/******************************************************************************************************************************************************/
/* 按照lrj的黑书来写的.
适用条件：简单多边形(点按顺时针或逆时针给出).
复杂度：O(n).
*/
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
typedef double Type; // 注意下面的fabs().
const int maxn = 1005;
const double EPS = 1e-8;
const double Pi = acos(-1.0);
struct Point
{
    Type x, y;
    Point () {}
    Point (Type & xx, Type & yy) : x(xx), y(yy) {}
};
// 判断正负.
int dblcmp(Type d)
{
    if (fabs(d) < EPS) return 0; // 注意数据类型不同，abs()也不同.
    return d > 0 ? 1 : -1;
}
// 叉乘.
// cross product of (c->a) and (c->b).
Type Cross(Point & c, Point a, Point b)
{
    return (a.x - c.x) * (b.y - c.y) - (b.x - c.x) * (a.y - c.y);
}
Type Distance(Point & u, Point & v)
{
    return sqrt( 0.0 + (u.x - v.x) * (u.x - v.x) + (u.y - v.y) * (u.y - v.y) );
}
int n;
Point point[maxn];
int Stack[2 * maxn]; // 两头栈.
int bot, top; // 栈底，栈顶.
double ans;
void Melkman(void)
{
    int i;
    int temp;
    Stack[n] = 0;
// 注意：前三个点不能是共线的.
    for (i = 1; i < n; i++)
    {
        Stack[n + 1] = i; // 当三点平行时要的是后一个点.
        if (dblcmp(Cross(point[Stack[n]], point[Stack[n + 1]], point[i + 1]))) break; // 前三个点不共线.
    }
    bot = n, top = n + 1;
    Stack[++top] = Stack[--bot] = i + 1;
// 保证开始的三个点成右手系，否则交换Stack[n]和Stack[n + 1] .
    if (dblcmp(Cross(point[Stack[n]], point[Stack[n + 1]], point[Stack[n + 2]])) < 0)
    {
        temp = Stack[n];
        Stack[n] = Stack[n + 1];
        Stack[n + 1] = temp;
    }
// 维护栈里的点为右手系(即栈中任意连续三点组成的路径是左旋的，或成直线).
    for (i = i + 2; i < n; i++)
    {
        if (dblcmp(Cross(point[Stack[top - 1]], point[Stack[top]], point[i])) > 0 &&
                dblcmp(Cross(point[Stack[bot]], point[Stack[bot + 1]], point[i])) > 0)
        {
            // 如果该点对于栈顶左旋且对于栈底右旋，则说明该点在凸包内.
            continue;
        }
        while (dblcmp(Cross(point[Stack[top - 1]], point[Stack[top]], point[i])) <= 0) top--;
        Stack[++top] = i;
        while (dblcmp(Cross(point[Stack[bot]], point[Stack[bot + 1]], point[i])) <= 0) bot++;
        Stack[--bot] = i;
    }
}
int main(void)
{
    int i;
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        scanf("%lf %lf", &point[i].x, &point[i].y);
    }
    Melkman(); // 得到的凸包点序列也是按极角序的.
    cout << top - bot << endl;
    for (i = bot; i < top; i++)
    {
        printf("%lf %lf\n", point[Stack[i]].x, point[Stack[i]].y);
        ans += Distance(point[Stack[i]], point[Stack[i + 1]]); // Stack[top]为第1个点.
    }
    printf("%lf\n", ans);
    return 0;
}
