#include <bits/stdc++.h>
using namespace std;
#define SENTINEL 1024000000
#define MAX 500000

int S[MAX];
int L[MAX / 2 + 2], R[MAX / 2 + 2];

void merge(int A[], int n, int left, int mid, int right)
{
}

void mergeSort(int A[], int left[], int right[])
{
}

int main()
{
    int n = 0;
    /* 標準入力受け取り */
    scanf("%d", &n);

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
