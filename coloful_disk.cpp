#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, cur = 0;
    stack<int> S;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &cur);
        while (!S.empty() && S.top() < cur)
        {
            S.pop();
        }
        S.push(cur);
    }
    printf("%d\n", S.size());
}
