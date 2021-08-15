#include <bits/stdc++.h>
using namespace std;

int partition(int A[], int p, int r)
{
    int x = A[r];
    int i = p - 1;
    for (int j = p; j < r; j++)
    {
        if (A[j] <= x)
        {
            i++;
            int temp = A[j];
            A[j] = A[i];
            A[i] = temp;
        }
    }
    int temp = A[i + 1];
    A[i + 1] = A[r];
    A[r] = temp;
    return i + 1;
}

int main()
{
    int n = 0;
    /* 標準入力受け取り */
    scanf("%d", &n);
    int A[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &A[i]);
    }
    int x = partition(A, 0, n - 1);

    for (int i = 0; i < n; i++)
    {
        if (i)
        {
            cout << " ";
        }
        if (i == x)
        {
            cout << '[' << A[i] << ']';
        }
        else
        {
            cout << A[i];
        }
    }
    cout << endl;
}
