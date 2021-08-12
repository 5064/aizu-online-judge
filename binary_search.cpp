#include <bits/stdc++.h>
using namespace std;

bool binarySearch(int A[], int n, int key)
{
    int left = 0;
    int right = n;
    int mid = 0;
    while (left < right)
    {
        mid = (right + left) / 2;
        if (A[mid] == key)
        {
            return true;
        }
        if (A[mid] > key)
        {
            right = mid;
        }
        else if (A[mid] < key)
        {
            left = mid + 1;
        }
    }
    return false;
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
        if (binarySearch(S, n, key))
        {
            sum++;
        }
    }
    printf("%d\n", sum);
}
