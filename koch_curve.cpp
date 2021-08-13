#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
#include <cmath>
using namespace std;

struct coor
{
    double x;
    double y;
};

void koch(int lvl, coor p1, coor p2)
{

    if (lvl == 0)
        return;
    coor s, t, u;
    s.x = (2 * p1.x + p2.x) / 3;
    s.y = (2 * p1.y + p2.y) / 3;
    u.x = (p1.x + 2 * p2.x) / 3;
    u.y = (p1.y + 2 * p2.y) / 3;
    t.x = (u.x - s.x) * cos(M_PI / 3) - (u.y - s.y) * sin(M_PI / 3) + s.x;
    t.y = (u.x - s.x) * sin(M_PI / 3) + (u.y - s.y) * cos(M_PI / 3) + s.y;

    koch(lvl - 1, p1, s);
    cout << fixed << setprecision(8) << s.x << ' ' << s.y << endl;

    koch(lvl - 1, s, t);
    cout << fixed << setprecision(8) << t.x << ' ' << t.y << endl;

    koch(lvl - 1, t, u);
    cout << fixed << setprecision(8) << u.x << ' ' << u.y << endl;

    koch(lvl - 1, u, p2);
}

int main()
{
    int n = 0;
    scanf("%d", &n);

    coor p1 = {0, 0};
    coor p2 = {100, 0};
    cout << fixed << setprecision(8) << p1.x << ' ' << p1.y << endl;
    koch(n, p1, p2);
    cout << fixed << setprecision(8) << p2.x << ' ' << p2.y << endl;
}
