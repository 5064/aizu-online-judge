#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N = 0, length = 1, max = 0;
    /* 標準入力受け取り */
    cin >> N;
    int a = 0;
    int A[101] = {};
    for (int i = 0; i < N; i++)
    {
        cin >> a;
        A[i] = a;
    }

    // judge
    for (int i = 0; i < N; i++)
    {
        if (A[i] <= A[i + 1])
        {
            length++;
        }
        else
        {
            if (length > max)
            {
                max = length;
            }
            length = 1;
        }
    }

    cout << max << endl;
}
