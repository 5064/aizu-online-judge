#include <bits/stdc++.h>
using namespace std;
#define SENTINEL 1024000000
#define MAX 100007

struct Card
{
    char suit;
    int value;
};

// ----------------------------------------------

Card L[MAX / 2 + 2], R[MAX / 2 + 2]; // 一時的なメモリ領域が必要

void merge(Card A[], int left, int mid, int right)
{
    int n1 = mid - left;
    int n2 = right - mid;
    for (int i = 0; i < n1; i++)
    {
        L[i] = A[left + i];
    }
    for (int i = 0; i < n2; i++)
    {
        R[i] = A[mid + i];
    }
    L[n1].value = R[n2].value = SENTINEL;
    int i = 0, j = 0;
    for (int k = left; k < right; k++)
    {
        if (L[i].value <= R[j].value)
        {
            A[k] = L[i++];
        }
        else
        {
            A[k] = R[j++];
        }
    }
}

void mergeSort(Card A[], int left, int right)
{
    if (left + 1 < right) // 部分配列の長さが3以上(1+2 or 2+1)のとき
    {
        int mid = (left + right) / 2;
        mergeSort(A, left, mid);
        mergeSort(A, mid, right);
        merge(A, left, mid, right);
    }
}

// ----------------------------------------------

Card A[MAX], B[MAX];

int partition(Card A[], int p, int r)
{
    Card x = A[r];
    int i = p - 1;
    for (int j = p; j < r; j++)
    {
        if (A[j].value <= x.value)
        {
            i++;
            Card temp = A[j];
            A[j] = A[i];
            A[i] = temp;
        }
    }
    Card temp = A[i + 1];
    A[i + 1] = A[r];
    A[r] = temp;
    return i + 1;
}

void quickSort(Card A[], int p, int r)
{
    int q;
    if (p < r)
    {
        int q = partition(A, p, r);
        quickSort(A, p, q - 1);
        quickSort(A, q + 1, r);
    }
}

int main()
{
    int n = 0;
    Card c;
    /* 標準入力受け取り */
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        cin >> c.suit >> c.value;
        A[i] = B[i] = c;
    }

    quickSort(A, 0, n - 1);
    mergeSort(B, 0, n);
    bool isStable = true;

    for (int i = 0; i < n; i++)
    {
        if (A[i].suit != B[i].suit)
        {
            isStable = false;
        }
    }
    if (isStable)
    {
        cout << "Stable" << endl;
    }
    else
    {
        cout << "Not stable" << endl;
    }
    for (int i = 0; i < n; i++)
    {
        cout << A[i].suit << " " << A[i].value << endl;
    }
}
