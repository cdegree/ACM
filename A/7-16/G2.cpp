/* ����lrj�ĺ�����д��
�뼫����Ƚϵ��ŵ㣺
1. ������򵥣�ֻ�Ǽ򵥵ıȽϣ�û������.
2. ��ʼ������ң����������ĵ�һ����.
3. ���Ժܺõش����������(����).
*/
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
typedef double Type; // ע�������fabs().
const int maxn = 1005;
const double EPS = 1e-8;
const double Pi = acos(-1.0);
struct Point
{
    Type x, y;
    Point () {}
    Point (Type & xx, Type & yy) : x(xx), y(yy) {}
};
// �ж�����.
int dblcmp(Type d)
{
    if (fabs(d) < EPS) return 0; // ע���������Ͳ�ͬ��abs()Ҳ��ͬ.
    return d > 0 ? 1 : -1;
}
// ���.
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
    sort(point, point + n, cmp); // point[0]��Ϊ���.
// ������.
    top = -1;
    Stack[++top] = 0;
    Stack[++top] = 1;
    for (i = 2; i < n; i++)
    {
        while (top >= 1 && dblcmp(Cross(point[Stack[top - 1]], point[i], point[Stack[top]])) >= 0) top--; // ���������ת������ջ. ���ֻҪ�󼫵㣬���ߵĵ�Ҳ�ǲ�Ҫ��(��Ҫ�ӵ���).
        Stack[++top] = i;
    }
    temp_top = top; // ��ʱ��ջ��Ԫ��һ���ǵ�n����.
// ������.
    Stack[++top] = n - 2;
    for (i = n - 3; i >= 0; i--)
    {
        while (top >= temp_top + 1 && dblcmp(Cross(point[Stack[top - 1]], point[i], point[Stack[top]])) >= 0) top--; // ���������ת������ջ. ���ֻҪ�󼫵㣬���ߵĵ�Ҳ�ǲ�Ҫ��(��Ҫ�ӵ���).
        Stack[++top] = i;
    }
// ��ʱ��ջ��Ԫ���ǵ�1����.(���͹����һ��ֱ�ߣ���������������ͬ.)
// ͹���Ķ���Ϊpoint[Stack[0]] �� point[Stack[top - 1]].
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
/* ����lrj�ĺ�����д��.
�����������򵥶����(�㰴˳ʱ�����ʱ�����).
���Ӷȣ�O(n).
*/
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
typedef double Type; // ע�������fabs().
const int maxn = 1005;
const double EPS = 1e-8;
const double Pi = acos(-1.0);
struct Point
{
    Type x, y;
    Point () {}
    Point (Type & xx, Type & yy) : x(xx), y(yy) {}
};
// �ж�����.
int dblcmp(Type d)
{
    if (fabs(d) < EPS) return 0; // ע���������Ͳ�ͬ��abs()Ҳ��ͬ.
    return d > 0 ? 1 : -1;
}
// ���.
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
int Stack[2 * maxn]; // ��ͷջ.
int bot, top; // ջ�ף�ջ��.
double ans;
void Melkman(void)
{
    int i;
    int temp;
    Stack[n] = 0;
// ע�⣺ǰ�����㲻���ǹ��ߵ�.
    for (i = 1; i < n; i++)
    {
        Stack[n + 1] = i; // ������ƽ��ʱҪ���Ǻ�һ����.
        if (dblcmp(Cross(point[Stack[n]], point[Stack[n + 1]], point[i + 1]))) break; // ǰ�����㲻����.
    }
    bot = n, top = n + 1;
    Stack[++top] = Stack[--bot] = i + 1;
// ��֤��ʼ�������������ϵ�����򽻻�Stack[n]��Stack[n + 1] .
    if (dblcmp(Cross(point[Stack[n]], point[Stack[n + 1]], point[Stack[n + 2]])) < 0)
    {
        temp = Stack[n];
        Stack[n] = Stack[n + 1];
        Stack[n + 1] = temp;
    }
// ά��ջ��ĵ�Ϊ����ϵ(��ջ����������������ɵ�·���������ģ����ֱ��).
    for (i = i + 2; i < n; i++)
    {
        if (dblcmp(Cross(point[Stack[top - 1]], point[Stack[top]], point[i])) > 0 &&
                dblcmp(Cross(point[Stack[bot]], point[Stack[bot + 1]], point[i])) > 0)
        {
            // ����õ����ջ�������Ҷ���ջ����������˵���õ���͹����.
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
    Melkman(); // �õ���͹��������Ҳ�ǰ��������.
    cout << top - bot << endl;
    for (i = bot; i < top; i++)
    {
        printf("%lf %lf\n", point[Stack[i]].x, point[Stack[i]].y);
        ans += Distance(point[Stack[i]], point[Stack[i + 1]]); // Stack[top]Ϊ��1����.
    }
    printf("%lf\n", ans);
    return 0;
}
