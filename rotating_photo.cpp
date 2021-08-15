#include <bits/stdc++.h>
using namespace std;

// Clockwiseに90度回転
vector<string> rotateCW(vector<string> photo, int n)
{
    // swap UpperRight and LowerLeft
    for (int y = 0; y < n; y++)
    {
        for (int x = 0; x < y; x++)
        {
            char pixel = photo[y][x];
            photo[y][x] = photo[x][y];
            photo[x][y] = pixel;
        }
    }

    // swap x
    for (int y = 0; y < n; y++)
    {
        reverse(photo[y].begin(), photo[y].end());
    }
    return photo;
}

int main()
{
    int n = 0, q = 0;
    /* 標準入力受け取り */
    cin >> n;
    vector<string> P;
    string row;
    for (int i = 0; i < n; i++)
    {
        cin >> row;
        P.push_back(row);
    }

    int rotate = 0, sum = 0;
    cin >> q;
    for (int i = 0; i < q; i++)
    {
        cin >> rotate;
        sum += rotate;
    }

    vector<string> answer;
    switch ((4 + (sum % 4)) % 4)
    {
    case 0:
        answer = P;
        break;
    case 1:
        answer = rotateCW(P, n);
        break;
    case 2:
        answer = rotateCW(rotateCW(P, n), n);
        break;
    case 3:
        answer = rotateCW(rotateCW(rotateCW(P, n), n), n);
        break;
    default:
        break;
    }

    for (int i = 0; i < n; i++)
    {
        cout << answer[i] << endl;
    }
}
