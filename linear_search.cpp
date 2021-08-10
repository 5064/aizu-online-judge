#include <bits/stdc++.h>
using namespace std;

bool search(int A[], int n, int key)
{
    int i = 0;
    A[n] = key;
    while (A[i] != key)
    {
        i++;
    }
    return i != n;
}

int main()
{
    int n, q = 0;
    /* 標準入力受け取り */
    scanf("%d", &n);
    int S[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &S[i]);
    }
    scanf("%d", &q);
    int key, sum = 0;
    for (int i = 0; i < q; i++)
    {
        scanf("%d", &key);
        if (search(S, n, key))
        {
            sum++;
        }
    }
    printf("%d\n", sum);
}
