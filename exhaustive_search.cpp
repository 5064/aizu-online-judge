#include <bits/stdc++.h>
using namespace std;

int A[2000];

bool solve(int i, int n, int m)
{
    if (m == 0)
        return true;
    if (i >= n)
        return false;
    bool result = solve(i + 1, n, m) || solve(i + 1, n, m - A[i]);
    return result;
}

int main()
{
    int n, q = 0;
    /* 標準入力受け取り */
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &A[i]);
    }
    scanf("%d", &q);

    int m = 0;
    for (int i = 0; i < q; i++)
    {
        scanf("%d", &m);
        if (solve(0, n, m))
        {
            printf("yes\n");
        }
        else
        {
            printf("no\n");
        }
    }
}
