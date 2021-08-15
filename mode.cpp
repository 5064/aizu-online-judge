#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n = 0, m = 0, j = 0;
    /* 標準入力受け取り */
    cin >> n;
    cin >> m;
    int X[101] = {};
    for (int i = 0; i < n; i++)
    {
        cin >> j;
        X[j] += 1;
    }
    int max = -1;
    for (int i = 0; i < n + 1; i++)
    {

        if (max < X[i])
        {
            max = X[i];
        }
    }

    cout << max << endl;
}
